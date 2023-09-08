#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set the color to white

    glBegin(GL_POINTS);
    glVertex2f(0.0, 0.0); // Draw a point at the origin (0, 0)
    glVertex2f(0.5, 0.5); // Draw a point at (0.5, 0.5)
    glVertex2f(-0.5, -0.5); // Draw a point at (-0.5, -0.5)
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("OpenGL Points");

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
