#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set the color to white

    glBegin(GL_LINES);
    glVertex2f(-0.5, 0.0); // Start of the first line
    glVertex2f(0.5, 0.0);  // End of the first line

    glVertex2f(0.0, -0.5); // Start of the second line
    glVertex2f(0.0, 0.5);  // End of the second line
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("OpenGL Lines");

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
