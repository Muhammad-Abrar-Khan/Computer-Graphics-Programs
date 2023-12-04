
/*

Draw a star using concepts of affine transformation.
Draw a snow flake using concepts of affine transformation
Make tilling of dinosaur using concepts of affine transformation.

*/



#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

const int screenWidth = 640;	   // width of screen window in pixels
const int screenHeight = 460;	   // height of screen window in pixels

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);       // background color is white
	glColor3f(0.0f, 0.0f, 0.0f);         // drawing color is black
	glPointSize(2.0);		          // a 'dot' is 2 by 2 pixels
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluOrtho2D(-200.0, 200.0, -200.0, 200.0);   //dino window

}

void setWindow(int xs, int xe, int ys, int ye) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D((GLint)xs, (GLint)xe, (GLint)ys, (GLint)ye);
}


void drawPolyLineFile(const char* fileName)
{
	fstream inStream;

	inStream.open(fileName, ios::in);	// open the file

	if (inStream.fail())
	{
		cout << "can't open it!"; return;
	}

	GLfloat numpolys, numPoints, x, y;
	inStream >> numpolys;		           // read the number of polylines

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


void pushCT(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
}

void popCT(){
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

void transform_dino(){

     setWindow(0,640.0,0,440.0);

     pushCT();
     glTranslated(0.0,0.0,0.0);
     for(int i = 0 ; i<8 ;i++){
        pushCT();
        for(int j = 0 ; j<9 ;j++){
            glViewport( j*64, i*44, 64, 44);
            //drawPolyLineFile("C:\\Users\\khush\\OneDrive\\Desktop\\Subhan Sem. 6\\Computer Graphics (514) 6th - Miss. Humera Bashir\\Lab 3_ WW to VP mapping\\dino.dat");
            drawPolyLineFile("F:\\B20102046 ~ Hamdan Siddiqui\\dino.dat");
			//drawPolyLineFile("C:\\Users\\Home\\Desktop\\Varsity work hamdan\\Computer Graphics\\Coding Folder\\Star-Snowflake-TransformDino-week10\\dino.dat");
        }
        popCT();
        glTranslated(20.0,0.0,0.0);
     }
     popCT();
}


void circular_dino(){

    setWindow(0,640.0,0,440.0);

    const int numMotifs = 12;
    const int centerX = 320; // X-coordinate of the center of the circle
    const int centerY = 220; // Y-coordinate of the center of the circle
    const int radius = 140;
    const int motifWidth = 100;
    const int motifHeight = 100;

    // Radius of the circular arrangement
    for (int i = 0; i < numMotifs; i++)
    {
        double angle = 2 * M_PI * i / numMotifs; // Calculate angle for each motif
        int x = centerX + static_cast<int>(radius * cos(angle));
        int y = centerY + static_cast<int>(radius * sin(angle));

        glViewport( x, y, 64, 44);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        double rotationAngle = (angle - M_PI) / 2.0;
        cout << x + motifWidth / 2 << ":" << y + motifHeight / 2;
        glTranslatef((x + motifWidth )/ 2, (y + motifHeight) / 2, 0); // Translate to the center of the motif
        glRotatef((rotationAngle * 180.0 )/ M_PI, 0, 0, 1);         // Rotate around the z-axis
        glTranslatef(-motifWidth / 2, -motifHeight / 2, 0);       // Translate back to the original position
        cout << -motifWidth / 2 << ":" << -motifHeight / 2 << std::endl;

        //drawPolyLineFile("C:\\Users\\khush\\OneDrive\\Desktop\\Subhan Sem. 6\\Computer Graphics (514) 6th - Miss. Humera Bashir\\Lab 3_ WW to VP mapping\\dino.dat");
        drawPolyLineFile("F:\\B20102046 ~ Hamdan Siddiqui\\dino.dat");
        //drawPolyLineFile("C:\\Users\\Home\\Desktop\\Varsity work hamdan\\Computer Graphics\\Coding Folder\\Star-Snowflake-TransformDino-week10\\dino.dat");
        glPopMatrix();
    }

    glFlush();
    glutSwapBuffers();

}

void snowflakes_motif(){

    glPushMatrix();
    glBegin(GL_LINE_STRIP);
	glVertex2i(0, 2);
	glVertex2i(20,2);
	glVertex2i(30, 15);
	glVertex2i(35,13);
	glVertex2i(25, 2);
	glVertex2i(30, 2);
	glVertex2i(45, 15);
	glVertex2i(50, 13);
	glVertex2i(35, 2);
	glVertex2i(55, 2);
	glVertex2i(60, 0);
    glEnd();

    glFlush();
    glutSwapBuffers();
}

void drawflakes() {

    setWindow(-150.0, 150.0 ,-150.0, 150.0);
    for (int i = 0; i < 12; i++) {
            snowflakes_motif();
            glScalef(1.0,-1.0, 1.0);
            snowflakes_motif();
            glScalef(1.0, -1.0, 1.0);
            glRotated(60.0, 0.0, 0.0, 1.0);
    }
}

void star_motif(){

    glPushMatrix();
    glBegin(GL_LINE_STRIP);
        glVertex2i(3,3);
        glVertex2i(0,8);
        glVertex2i(-3,0);
        glVertex2i(-2,-1);
        glVertex2i(0,5);
        glVertex2i(2,3);
    glEnd();
    glutSwapBuffers();

}

void drawstar(){

    setWindow(-10.0, 10.0 ,-10.0, 10.0);
	for (int count = 0;count < 5;count++) {
		star_motif();
		glTranslatef(1, 0, 0);
		glRotatef(72,0,0,1);
	}
	glutSwapBuffers();
}



void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // drawstar();
    drawflakes();
   // transform_dino();
    //circular_dino();

    glutSwapBuffers();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);   // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition(10, 10); // set window position on screen
	glutCreateWindow("Star/Snowflake/Dino"); // open the screen window
	glutDisplayFunc(myDisplay);     // register redraw function
	init();
	glutMainLoop(); 		     // go into a perpetual loop
	return 1;
}


