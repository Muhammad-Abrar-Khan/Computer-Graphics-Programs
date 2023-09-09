#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set the clear color to white
    glColor3f(0.0, 0.0, 0.0); // Set the drawing color to black

    glBegin(GL_LINE_STRIP);

    // Define vertices for a line strip
    glVertex2f(-0.6, -0.4);
    glVertex2f(-0.2, 0.4);
    glVertex2f(0.2, -0.4);
    glVertex2f(0.6, 0.4);

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Line Strip");

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
