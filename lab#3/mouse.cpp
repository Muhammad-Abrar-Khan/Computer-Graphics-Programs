#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(5.0, 1.0, 5.0);
    glLineWidth(3.0);
    // Add your drawing commands here
    glFlush();
}

void myMouse(int button, int state, int x, int y) {
    if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) {
        glPointSize(5.0);

        glBegin(GL_POINTS);
        glVertex2d(x, 600 - y);
        glEnd();
        glFlush();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Button Click");
    gluOrtho2D(0, 800, 0, 600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glutDisplayFunc(display);
    glutMouseFunc(myMouse);

    glutMainLoop();

    return 0;
}