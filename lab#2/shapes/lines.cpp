#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set the clear color to white
    glColor3f(0.0, 0.0, 0.0); // Set the drawing color to black

    glBegin(GL_LINES);

    // Define the first line
    glVertex2f(-0.6, -0.4); // Start point of the first line
    glVertex2f(0.6, 0.4);   // End point of the first line

    // Define the second line
    glVertex2f(-0.6, 0.4);  // Start point of the second line
    glVertex2f(0.6, -0.4);  // End point of the second line

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Lines");

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
