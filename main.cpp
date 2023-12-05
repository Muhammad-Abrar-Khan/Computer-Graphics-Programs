#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glut.h>

// Define the initial values
int i = 0;
int len = 10;

// Function to move the turtle forward
void forward(float distance) {
    glBegin(GL_LINES);
    glVertex2f(0, 0);
    glVertex2f(distance, 0);
    glEnd();
    glTranslatef(distance, 0, 0);
}

// Function to turn the turtle
void turn(float angle) {
    glRotatef(angle, 0, 0, 1);
}

// Function to display
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // Set the color to black

    glPushMatrix(); // Save the current matrix

    while (i != 3) {
        forward(10);
        turn(60);
        forward(10);
        turn(60);
        forward(10);
        turn(120);
        i++;
    }

    glPopMatrix(); // Restore the previous matrix

    glFlush();
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Turtle Graphics with OpenGL");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-100, 100, -100, 100);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
