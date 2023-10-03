#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;


void drawPolyLineFile(const char* fileName)
{
	fstream inStream;
    inStream.open(fileName, ios::in);	// open the file
	if (inStream.fail())
	{
		cout << "can't open it!"; return;
	}
    GLfloat numpolys, numPoints, x, y;
	inStream >> numpolys;

	cout << "Number of polylines: " << numpolys << endl;	           // read the number of polylines
	for (int j = 0; j < numpolys; j++)  // read each polyline
	{
		inStream >> numPoints;       //number of points in first PolyLine

		glBegin(GL_LINE_STRIP);	     // draw the next polyline
		for (int i = 0; i < numPoints; i++)
		{
			inStream >> x >> y;        // read the next x, y pair
			glVertex2f(x, y);
		}
		glEnd();
	}
	inStream.close();
}
void setWindow(int xs, int xe, int ys, int ye) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D((GLint)xs, (GLint)xe, (GLint)ys, (GLint)ye);
}

void flipping(){

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if ((i + j) % 2 == 0) {
                    setWindow(0, 640, 0, 480);
            }
			else{
                    setWindow(0, 640, 480, 0);
			}
			glViewport(i * 64, j * 44, 64, 44);
			drawPolyLineFile("S:\\NS\\CG\\Dino\\dino.dat");

		}
	}
	glFlush();
	glutSwapBuffers();

}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.0f, 0.0f);
   glPointSize(4.0);

    //drawPolyLineFile("S:\\NS\\CG\\Dino\\dino.dat");
    //drawPolyLineFile("S:\\NS\\CG\\dino.dat");

    flipping();
    glutSwapBuffers();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   // set display mode
	glutInitWindowSize(640, 480); // set window size
	glutCreateWindow("Dino Drawing"); // open the screen window
	gluOrtho2D(0, 640, 0, 480); // Set the coordinate system
	//glViewport(0, 0, 640, 480);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glClearColor(1.0, 1.0, 1.0, 0.0);       // background color is white

    glutDisplayFunc(display);

	glutMainLoop(); 		     // go into a perpetual loop
	return 0;
}