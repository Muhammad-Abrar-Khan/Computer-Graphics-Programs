#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glOrtho(-210, 210, -220, 310, -210, 310);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //-----------------------sky------------------------------------------------------------------
    glColor3ub(135, 206, 250); // light blue
    glRecti(-200, 300, 200, 100);

    //-----------------------------------field------------------------------
    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0); // green

    glVertex2i(-200, 100);
    glVertex2i(-100, 160);
    glVertex2i(0, 100);
    glVertex2i(50, 70);
    glVertex2i(100, 180);
    glVertex2i(200, 100);
    glColor3ub(255, 215, 0); // gold
    glVertex2i(200, -200);

    glVertex2i(-200, -200);
    glColor3ub(255, 215, 0); // gold
    glVertex2i(-200, 100);

    glEnd();

    //-------------------SUN-------------------------
    glColor3ub(255, 215, 0);
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 360; i++)
    {
        double x = 90 + cos((i * 3.14) / 180) * 30;
        double y = 250 + sin((i * 3.14) / 180) * 45; // Decrease the 'sin' multiplier for a slightly smaller sun
        glVertex2d(x, y);
    }
    glEnd();

    //-------------------------------------------RIVER--------------------------------------------------
    glBegin(GL_POLYGON);
    glColor3ub(30, 144, 255);
    glVertex2i(-200, -50);
    glVertex2i(200, -30);
    glColor3ub(0, 0, 128);
    glVertex2i(200, -200);
    glVertex2i(-200, -200);
    glVertex2i(-200, -50);
    glEnd();

    glBegin(GL_POLYGON); // border
    glColor3ub(128, 128, 0);
    glVertex2i(-200, -45);
    glVertex2i(200, -25);
    glVertex2i(200, -30);
    glVertex2i(-200, -50);
    glVertex2i(-200, -45);
    glEnd();

    //-------------------------------------------HOUSE one----------------------------
    glBegin(GL_POLYGON); // First Part
    glColor3ub(128, 0, 0); // gray
    glVertex2i(-58, 115);
    glVertex2i(-75, 145);
    glVertex2i(-115, 150); // point
    glVertex2i(-90, 100);
    glVertex2i(-62, 100);
    glEnd();

    glBegin(GL_POLYGON); // Second Part
    glColor3ub(120, 0, 0); // maroon
    glVertex2i(-115, 150);
    glVertex2i(-130, 100);
    glVertex2i(-120, 100); // point
    glVertex2i(-108, 137); // point
    glVertex2i(-115, 150);
    glEnd();

    glBegin(GL_POLYGON); // Third Part
    glColor3ub(46, 139, 87);
    glVertex2i(-108, 137);
    glVertex2i(-120, 100);
    glVertex2i(-120, 45);
    glVertex2i(-90, 40); // point
    glVertex2i(-90, 100);
    glVertex2i(-108, 137);
    glEnd();

    glBegin(GL_POLYGON); // Fourth Part
    glColor3ub(143, 188, 143);
    glVertex2i(-90, 40);
    glVertex2i(-60, 45);
    glVertex2i(-60, 100);
    glVertex2i(-90, 100);
    glEnd();

    glColor3ub(120, 0, 0); // maroon // Door One
    glRecti(-75, 80, -65, 40);

    glColor3ub(120, 0, 0); // maroon // Door One
    glRecti(-110, 90, -100, 70);

    glBegin(GL_POLYGON); // Third Part (lower part 1)
    glColor3ub(0, 0, 0);
    glVertex2i(-90, 40);
    glVertex2i(-123, 45);
    glVertex2i(-123, 35);
    glVertex2i(-90, 30);
    glVertex2i(-90, 40);
    glEnd();

    glBegin(GL_POLYGON); // Third Part (lower part 2)
    glColor3ub(0, 0, 0);
    glVertex2i(-90, 40);
    glVertex2i(-55, 45);
    glVertex2i(-55, 35);
    glVertex2i(-90, 30);
    glVertex2i(-90, 40);
    glEnd();

    glFlush();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(900, 1300);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow(" village scenery ");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
