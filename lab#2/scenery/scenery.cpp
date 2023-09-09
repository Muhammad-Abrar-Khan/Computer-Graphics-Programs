#include <GL/glut.h>
#include <cmath> // Include the <cmath> header for cos and sin functions

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the background color to light blue for the sky
    glClearColor(0.53, 0.81, 0.92, 1.0);
    glColor3f(0.0, 0.0, 0.0); // Set the drawing color to black

    // Draw the sky
    glBegin(GL_QUADS);
    glVertex2f(-1.0, 1.0);
    glVertex2f(1.0, 1.0);
    glVertex2f(1.0, 0.3);
    glVertex2f(-1.0, 0.3);
    glEnd();

    // Set the color to brown for the mountains
    glColor3f(0.36, 0.25, 0.20);

    // Draw the mountains
    glBegin(GL_TRIANGLES);
    glVertex2f(-1.0, 0.3);
    glVertex2f(0.0, 1.0);
    glVertex2f(1.0, 0.3);
    glEnd();

    // Set the color to yellow for the sun
    glColor3f(1.0, 1.0, 0.0);

    // Draw the sun
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.7, 0.7);
    for (int i = 0; i <= 360; i += 10) {
        float angle = i * 3.1415926 / 180.0;
        float x = -0.7 + 0.15 * cos(angle);
        float y = 0.7 + 0.15 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    // Set the color to green for the ground
    glColor3f(0.0, 0.5, 0.0);

    // Draw the ground
    glBegin(GL_QUADS);
    glVertex2f(-1.0, 0.3);
    glVertex2f(1.0, 0.3);
    glVertex2f(1.0, -1.0);
    glVertex2f(-1.0, -1.0);
    glEnd();

    // Set the color to blue for the water canal
    glColor3f(0.0, 0.0, 1.0);

    // Draw the water canal
    glBegin(GL_QUADS);
    glVertex2f(-0.2, -1.0);
    glVertex2f(0.2, -1.0);
    glVertex2f(0.1, -0.3);
    glVertex2f(-0.1, -0.3);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Scenery");

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
