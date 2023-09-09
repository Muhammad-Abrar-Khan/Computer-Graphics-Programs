#include <GL/glut.h>
#include <cmath>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set the clear color to white
    glColor3f(0.0, 0.0, 0.0); // Set the drawing color to black

    glBegin(GL_TRIANGLE_FAN);

    // Define vertices for a triangle fan
    glVertex2f(0.0, 0.0); // Center of the fan

    // Define vertices for the fan points
    for (int i = 0; i <= 6; ++i) {
        float angle = 2.0f * M_PI * static_cast<float>(i) / 6.0f;
        float x = 0.4 * cos(angle);
        float y = 0.4 * sin(angle);
        
        glVertex2f(x, y);
    }

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Triangle Fan");

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
