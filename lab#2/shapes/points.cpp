#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glClearColor(1.0, 1.0, 1.0, 1.0); // Set the clear color to white
    glColor3f(0.0, 0.0, 0.0); // Set the drawing color to black
    glPointSize(10.0); // Increase the point size

    glBegin(GL_POINTS);
    glVertex2f(-0.5, 0.0); // First point
    glVertex2f(0.5, 0.0);  // Second point
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
