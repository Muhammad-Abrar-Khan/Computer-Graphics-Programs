#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set the color to white

    glBegin(GL_TRIANGLE_STRIP);

    // Define vertices for a triangle strip
    glVertex2f(-0.6, -0.6); // Vertex 1
    glVertex2f(0.0, 0.6);   // Vertex 2
    glVertex2f(0.6, -0.6);  // Vertex 3
    glVertex2f(1.2, 0.6);   // Vertex 4

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Triangle Strip");

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
