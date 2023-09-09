#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set the color to white

    glBegin(GL_LINES);
    glVertex2f(-0.4, -0.6);
    glVertex2f(0.0, 0.5);

    glVertex2f(0.0, 0.5);
    glVertex2f(0.4, -0.6);

    glVertex2f(0.4, -0.6);
    glVertex2f(-0.2, -0.8);

    glVertex2f(-0.2, -0.8);
    glVertex2f(-0.4, -0.6);

    glVertex2f(-0.4, -0.6);
    glVertex2f(0.2, -0.8);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("OpenGL Unfilled Pentagon");

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
