#include <GL/gl.h>
#include <unistd.h> // Include the usleep function

class Point2
{
  public:
    Point2() { x = y = 0.0f;} // constructor 1
    Point2(float xx,float yy) { x = xx; y = yy;} // constructor 2
    void set(float xx,float yy) { x = xx; y = yy;}
    float getX() { return x;}
    float getY() { return y;}
    void draw(void)
    {
		glPointSize(2.0);

		glEnable(GL_BLEND);
  		glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  		glHint( GL_POINT_SMOOTH_HINT, GL_NICEST);
 		glEnable( GL_POINT_SMOOTH);

		glBegin(GL_POINTS); // draw this point
			glVertex2f((GLfloat)x, (GLfloat)y);
		glEnd();

		glDisable( GL_POINT_SMOOTH);

    }// end draw
  private:
    float x, y;
};          // end class Point2




class Mario
{
public:

	RGBApixmap pix[5];          // make six empty pixmaps, one for each side of cube
	enum State	{STANDING,RUNNING1, RUNNING2,RUNNING3,JUMPING,DIE} state ;
	enum ModeType	{STAY,RUN,JUMP,DEAD} mode;
   	float pos_X, pos_Y;

	Mario(Point2 pos)

	{
	  pix[0].readBMPFile("MarioStanding.bmp",1);
	  pix[1].readBMPFile("MarioRun2.bmp",1);  // read texture for side 1 from image
	  pix[2].readBMPFile("MarioRun1.bmp",1);
	  pix[3].readBMPFile("MarioRun1.bmp",1);  // read texture for side 1 from image
	  pix[4].readBMPFile("MarioJump.bmp",1);

	  for(int i=0;i<5;i++)
		pix[i].setChromaKey(192,192,192);

	  this->pos_X = pos.getX();
	  this->pos_Y = pos.getY();

	}


	void changePosition(float dx, float dy)
	{
		this->pos_X += dx;  this->pos_Y += dy;
	}

	void render();
	void changeMode(ModeType m);
	void run();
	void stay();
	void jump();
	
};

void Mario::render()
{

	switch( mode )
	{

	case STAY:
		stay();
		break;

	case RUN:

		run();
		break;

	case JUMP:
		jump();
		break;
	}

}

void Mario::stay() {
	glRasterPos2i(this->pos_X,this->pos_Y);
	pix[0].mDraw();

}

void Mario::jump()
{
    const int jumpHeight = 100;    // Adjust the jump height as needed
    const int jumpSpeed = 2;      // Adjust the jump speed as needed
    const int jumpDistance = 100; // Adjust the jump horizontal distance

    // Simulate the upward jump motion
    for (int i = 0; i < jumpHeight; i += jumpSpeed)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        this->pos_Y += jumpSpeed;
        glRasterPos2i(this->pos_X, this->pos_Y);
        pix[4].mDraw();
        glFlush();
        usleep(10000); // Sleep for 10 milliseconds (adjust as needed)
    }

    // Simulate moving forward while jumping
    for (int i = 0; i < jumpDistance; i += jumpSpeed)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        this->pos_X += (float)jumpSpeed * 0.5; // Move forward at a slower rate
        this->pos_Y += jumpSpeed; // Move upward
        glRasterPos2i(this->pos_X, this->pos_Y);
        pix[4].mDraw();
        glFlush();
        usleep(10000); // Sleep for 10 milliseconds (adjust as needed)
    }

    // Simulate the remaining horizontal movement while descending
    for (int i = 0; i < jumpDistance; i += jumpSpeed)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        this->pos_X += (float)jumpSpeed * 0.5; // Continue moving forward at a slower rate
        this->pos_Y -= jumpSpeed; // Move downward
        glRasterPos2i(this->pos_X, this->pos_Y);
        pix[4].mDraw();
        glFlush();
        usleep(10000); // Sleep for 10 milliseconds (adjust as needed)
    }

    // Simulate the remaining downward motion after jumping
    for (int i = 0; i < jumpHeight; i += jumpSpeed)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        this->pos_Y -= jumpSpeed;
        glRasterPos2i(this->pos_X, this->pos_Y);
        pix[4].mDraw();
        glFlush();
        usleep(10000); // Sleep for 10 milliseconds (adjust as needed)
    }

    state = STANDING;
    mode = STAY;
}

// void Mario::jump() {

// 	pix[4].mDraw();
// 	glRasterPos2i(this->pos_X+50,this->pos_Y+20);
// 	this->pos_X += 50;  
 	 
// 	// this->pos_Y += 50; 	 
// 	pix[0].mDraw();
// 	state = STANDING;
// 	mode = STAY;

// }


void Mario::run()
{

	switch( state )
	{

	case RUNNING1:

		state = RUNNING2;
		break;

	case RUNNING2:

		state = RUNNING3;
		break;

	case RUNNING3:

		state = RUNNING1;
		break;
	}

    changePosition(0.2,0);
	glRasterPos2i(this->pos_X,this->pos_Y);
	pix[state].mDraw();

}


void Mario::changeMode(ModeType m)
{
	if( mode == m )
		return;

	switch( m )
	{
	case STAY:

		state = STANDING;
		break;

	case RUN:

		state = RUNNING1;
		break;

	case JUMP:

		state = JUMPING;
		break;

	}

	mode = m;
}