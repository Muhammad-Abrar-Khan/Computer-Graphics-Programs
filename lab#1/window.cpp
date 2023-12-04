#include <GL/glut.h>

void display() {
    // Your rendering code goes here
    glClear(GL_COLOR_BUFFER_BIT);
    
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set the clear color to white
    // Add your OpenGL drawing commands here
    
    // End of rendering code

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480); // Set the window size
    glutCreateWindow("Window Screen");

    // Register the display callback function
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
