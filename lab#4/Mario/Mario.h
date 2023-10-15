#pragma once
#include <GL/glut.h>
#include "pixMap.h"

class Point2 {
public:
    Point2() { x = y = 0.0f; }
    Point2(float xx, float yy) { x = xx; y = yy; }
    void set(float xx, float yy) { x = xx; y = yy; }
    float getX() { return x; }
    float getY() { return y; }
    void draw(void) {
        glPointSize(2.0);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
        glEnable(GL_POINT_SMOOTH);
        glBegin(GL_POINTS);
        glVertex2f((GLfloat)x, (GLfloat)y);
        glEnd();
        glDisable(GL_POINT_SMOOTH);
    }
private:
    float x, y;
};

enum MarioState {
    MARIO_STAY,
    MARIO_RUN_LEFT,
    MARIO_RUN_RIGHT,
    MARIO_JUMP,
    MARIO_DEAD
};

class Mario {
public:
    RGBApixmap pix[5];
    enum State { STANDING, RUNNING1, RUNNING2, RUNNING3, JUMPING, DIE } state;
    MarioState marioState;
    Point2 velocity;

    float pos_X, pos_Y;

    Mario(Point2 pos) {
        pix[0].readBMPFile("MarioStanding.bmp", 1);
        pix[1].readBMPFile("MarioRun2.bmp", 1);
        pix[2].readBMPFile("MarioRun1.bmp", 1);
        pix[3].readBMPFile("MarioRun1.bmp", 1);
        pix[4].readBMPFile("MarioJump.bmp", 1);

        for (int i = 0; i < 5; i++)
            pix[i].setChromaKey(192, 192, 192);

        this->pos_X = pos.getX();
        this->pos_Y = pos.getY();

        marioState = MARIO_STAY;
        velocity = Point2(0, 0);
    }

    void changeMode(MarioState newState) {
        marioState = newState;
    }

    void moveLeft() {
        marioState = MARIO_RUN_LEFT;
        velocity.set(-5, velocity.getY());
    }

    void moveRight() {
        marioState = MARIO_RUN_RIGHT;
        velocity.set(5, velocity.getY());
    }

    void jump() {
        if (marioState != MARIO_JUMP) {
            marioState = MARIO_JUMP;
            velocity.set(velocity.getX(), 15);
        }
    }

    void update() {
        changePosition(velocity.getX(), velocity.getY());

        if (marioState == MARIO_JUMP) {
            velocity.set(velocity.getX(), velocity.getY() - 1);
        }

        if (pos_Y < 0) {
            marioState = MARIO_DEAD;
        }
    }

    bool isDead() {
        return marioState == MARIO_DEAD;
    }

    void changePosition(float dx, float dy) {
        this->pos_X += dx;
        this->pos_Y += dy;
    }

    void render() {
        update();

        if (isDead()) {
            pos_X = 0;
            pos_Y = 0;
            marioState = MARIO_STAY;
        } else {
            switch (marioState) {
                case MARIO_STAY:
                    glRasterPos2i(this->pos_X, this->pos_Y);
                    pix[0].mDraw();
                    break;
                case MARIO_RUN_LEFT:
                case MARIO_RUN_RIGHT:
                    run();
                    break;
                case MARIO_JUMP:
                    // Implement jump rendering if needed
                    break;
                case MARIO_DEAD:
                    // Implement dead rendering if needed
                    break;
            }
        }
    }

    void run() {
        switch (state) {
            case RUNNING1:
                state = RUNNING2;
                break;
            case RUNNING2:
                state = RUNNING3;
                break;
            case RUNNING3:
                state = RUNNING1;
                break;
        }
        changePosition(20, 0);
        glRasterPos2i(this->pos_X, this->pos_Y);
        pix[state].mDraw();
    }
};
