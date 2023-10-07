#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include "Point.h"
#include <GL/glut.h>

using std::cout;
using std::fstream;
using std::ios;

Point2 P(0.0, 0.0);
int n;
float cxx;
float cyy;
float radiuss;
float rotAnglee = 90.0;
const int screenWidth = 650;	   // width of screen window in pixels
const int screenHeight = 450;	   // height of screen window in pixels

/*TASK1 sKELETON*/
void myDisplay(void);
void myInit(void);
void drawPolyLineFile(const char* fileName); // Updated function prototype
/*TASK2 skeleton*/

void setWindow(float left, float sWidth, float bottom, float sHeight);

void ngon(int n, float cx, float cy, float radius, float rotAngle);
void moveTo(float x, float y);
void lineTo(float x, float y);

// fourth task
void myMove(int t);

int main(int argc, char** argv)
{
	glutInit(&argc, argv); // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Set display mode
	glutInitWindowSize(screenWidth, screenHeight); // Set window size
	glutInitWindowPosition(10, 10); // Set window position on screen
	glutCreateWindow("Dino Line Drawing"); // Create the screen window
	myInit();
	glutDisplayFunc(myDisplay); // Register redraw function
	// fourth task
	glutTimerFunc(1000, myMove, 0);

	glutMainLoop(); // Enter the main loop
	return 1;
}


void myDisplay(void)
{
	drawPolyLineFile("birdhead.dat");
	drawPolyLineFile("house.dat");

	setWindow(0.0,640.0,0.0,480.0);
	 for(int i=0;i< 10; i++)
		 for(int j=0;j<10;j++)
		 {
			 glViewport(i*64,j*44,64,44);
			 drawPolyLineFile("dino.dat");
		 }
		 

	glutSwapBuffers();
}

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);       // background color is white
	glColor3f(0.0f, 0.0f, 0.0f);        // drawing color is black
	glPointSize(2.0);		            // a 'dot' is 2 by 2 pixels
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);//dino window
	glViewport(0, 0, screenWidth, screenHeight);
	glClear(GL_COLOR_BUFFER_BIT);
}

void drawPolyLineFile(const char* fileName)
{
	fstream inStream;

	inStream.open(fileName, ios::in);    // open the file

	if (inStream.fail())
	{
		cout << "can't open it!";
		return;
	}

	GLfloat numpolys, numPoints, x, y;
	inStream >> numpolys;		           // read the number of polylines

	for (int j = 0; j < numpolys; j++)  // read each polyline
	{
		inStream >> numPoints;       // number of points in the first PolyLine  
		glBegin(GL_LINE_STRIP);	     // draw the next polyline
		for (int i = 0; i < numPoints; i++)
		{
			inStream >> x >> y;        // read the next x, y pair
			glVertex2f(x, y);
		}
		glEnd();
	}
	glFlush();
	inStream.close();
}

void setWindow(float left, float sWidth, float bottom, float sHeight)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, sWidth, bottom, sHeight);
}

void ngon(int n, float cx, float cy, float radius, float rotAngle)
{
	cxx = cx;  cyy = cy; radiuss = radius;  rotAnglee = rotAngle;
	if (n < 3)
		return;

	double angle = rotAnglee * 3.1415926 / 180;
	double angleInc = 2 * 3.1415926 / n;

	moveTo(radiuss * (cos(angle)) + cxx, radius * sin(angle) + cyy);
	for (int k = 0; k < n; k++)
	{
		angle += angleInc;
		lineTo(radiuss * cos(angle) + cxx, radiuss * sin(angle) + cyy);
	}
}

void moveTo(float x, float y)
{
	P.set(x, y);
}

void lineTo(float x, float y)
{
	glBegin(GL_LINES);
	glVertex2i(P.getX(), P.getY());
	glVertex2i(x, y);
	glEnd();
	glFlush();
	P.set(x, y);
}

void myMove(int t)
{
	cxx = cxx + 5;
	cyy = +1;
	rotAnglee += 0.5;

	if (cxx > 60)
	{
		cxx = 0;
		cyy = 0;
		rotAnglee = 30;
	}
	if (cxx > 30)
	{
		glColor3f(1.0f, 0.0f, 0.0f);
	}

	glutTimerFunc(1000, myMove, 0);
	glutPostRedisplay();
}
