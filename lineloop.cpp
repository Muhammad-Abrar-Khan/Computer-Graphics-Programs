#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set the color to white

    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.5, -0.5); // First point
    glVertex2f(0.0, 0.5);   // Second point
    glVertex2f(0.5, -0.5);  // Third point
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("OpenGL Line Loop");

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
