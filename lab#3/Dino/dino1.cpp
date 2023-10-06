#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include "Point.h"
#include <GL/glut.h>

using std::cout;
using std::fstream;
using std::ios;

Point2 P(0.0, 0.0);
const int screenWidth = 650;
const int screenHeight = 450;

void myDisplay(void);
void myInit(void);
void drawPolyLineFile(const char* fileName);
void setWindow(float left, float sWidth, float bottom, float sHeight);
void ngon(int n, float cx, float cy, float radius, float rotAngle);
void moveTo(float x, float y);
void lineTo(float x, float y);
void myMove(int t);

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Dino Line Drawing");
    myInit();
    glutDisplayFunc(myDisplay);
    glutTimerFunc(1000, myMove, 0);
    glutMainLoop();
    return 1;
}

void myDisplay(void)
{
    drawPolyLineFile("birdhead.dat");
    drawPolyLineFile("house.dat");
    drawPolyLineFile("dino.dat");
    glutSwapBuffers();
}

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
    glViewport(0, 0, screenWidth, screenHeight);
    glClear(GL_COLOR_BUFFER_BIT);
}

void drawPolyLineFile(const char* fileName)
{
    fstream inStream;
    inStream.open(fileName, ios::in);
    if (inStream.fail())
    {
        cout << "can't open it!";
        return;
    }

    GLfloat numpolys, numPoints, x, y;
    inStream >> numpolys;
    
    for (int j = 0; j < numpolys; j++)
    {
        inStream >> numPoints;
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i < numPoints; i++)
        {
            inStream >> x >> y;
            glVertex2f(x, y);
        }
        glEnd();
    }
    glFlush();
    inStream.close();
}

void setWindow(float left, float sWidth, float bottom, float sHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(left, sWidth, bottom, sHeight);
}
