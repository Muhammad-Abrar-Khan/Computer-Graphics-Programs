#include <GL/glut.h>
#include <stdlib.h>

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glOrtho(-5, 5, -5, 5, -1, 1);
}

void drawHouse()
{
    // Base of the house
    glColor3ub(255, 0, 0); // Red color
    glBegin(GL_POLYGON);
    glVertex2f(-1.5, -1.5);
    glVertex2f(1.5, -1.5);
    glVertex2f(1.5, 1.5);
    glVertex2f(-1.5, 1.5);
    glEnd();

    // Roof of the house
    glColor3ub(0, 0, 255); // Blue color
    glBegin(GL_TRIANGLES);
    glVertex2f(-1.7, 1.5);
    glVertex2f(1.7, 1.5);
    glVertex2f(0, 3.0);
    glEnd();

    // Door
    glColor3ub(139, 69, 19); // Brown color
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, -1.5);
    glVertex2f(0.2, -1.5);
    glVertex2f(0.2, 0);
    glVertex2f(-0.2, 0);
    glEnd();

    // Window 1
    glColor3ub(0, 0, 0); // Black color
    glBegin(GL_POLYGON);
    glVertex2f(-0.8, 0.5);
    glVertex2f(-0.4, 0.5);
    glVertex2f(-0.4, 0.9);
    glVertex2f(-0.8, 0.9);
    glEnd();

    // Window 2
    glColor3ub(0, 0, 0); // Black color
    glBegin(GL_POLYGON);
    glVertex2f(0.4, 0.5);
    glVertex2f(0.8, 0.5);
    glVertex2f(0.8, 0.9);
    glVertex2f(0.4, 0.9);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the house
    drawHouse();

    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("2D House");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
