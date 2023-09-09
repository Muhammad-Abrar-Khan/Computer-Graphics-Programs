#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set the clear color to white
    glColor3f(0.0, 0.0, 0.0); // Set the drawing color to black


    glBegin(GL_TRIANGLES);

    // Define vertices for three triangles
    glVertex2f(-0.6, -0.6); // Triangle 1, Vertex 1
    glVertex2f(0.0, 0.6);   // Triangle 1, Vertex 2
    glVertex2f(0.6, -0.6);  // Triangle 1, Vertex 3

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Triangles");

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
