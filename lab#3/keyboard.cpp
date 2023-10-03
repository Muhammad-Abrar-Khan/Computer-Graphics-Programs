#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdlib>

float xstart,ystart, xend, yend;
bool check=true;

void myKeyboard(unsigned char key, int x, int y){
    switch (key) {
    case 'A':
    case 'a':
        xstart = rand()%800;
        ystart = rand()%600;
        xend = rand()%800;
        yend = rand()%600;
          glutPostRedisplay();
        break;
    case 'u': // You forgot to put 'u' inside single quotes
    case 'U':
        glClearColor(1, 1, 1, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        check = false;
        break;
    }
    glutPostRedisplay();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(5.0, 1.0, 5.0);
    glLineWidth(3.0);

    glBegin(GL_LINES);
        glVertex2i(xstart,ystart);
        glVertex2i(xend,yend);

    glEnd();

glFlush();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Keyboard Event");
    gluOrtho2D(0, 800, 0, 600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboard);

    glutMainLoop();

    return 0;
}