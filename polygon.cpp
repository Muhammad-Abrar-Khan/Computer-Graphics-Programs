#include <GL/glut.h>
#include <cmath>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set the color to white

    glBegin(GL_LINES);

    // Define six vertices for the hexagon in a counterclockwise order
    for (int i = 0; i < 6; ++i) {
        float angle1 = 2.0f * M_PI * static_cast<float>(i) / 6.0f;
        float angle2 = 2.0f * M_PI * static_cast<float>(i + 1) / 6.0f;
        float x1 = 0.4 * cos(angle1);
        float y1 = 0.4 * sin(angle1);
        float x2 = 0.4 * cos(angle2);
        float y2 = 0.4 * sin(angle2);
        
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    }

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("OpenGL Unfilled Hexagon");

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
