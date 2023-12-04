
class Point2
{
public:
	Point2() { x = y = 0.0f; } // constructor 1
	Point2(float xx, float yy)  // constructor 2
	{
		x = xx;
		y = yy;
	} 
	void set(float xx, float yy)  
	{
		x = xx;
		y = yy;
	}
	float getX() { return x; }
	float getY() { return y; }
	void draw(void)
	{
		glPointSize(2.0);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
		glEnable(GL_POINT_SMOOTH);

		glBegin(GL_POINTS); // draw this point
		glVertex2f((GLfloat)x, (GLfloat)y);
		glEnd();

		glDisable(GL_POINT_SMOOTH);

	}   // end draw
private:
	float x, y;
};     // end class Point2



class Spider
{
public:
	RGBApixmap pix[3]; // make 3 empty pixmaps, one for each side of cube

	enum State
	{
		STANDING,
		RUNNING1,
		JUMPING,
		DIE
	} state;

	enum ModeType
	{
		STAY,
		RUN,
		JUMP,
		DEAD
	} mode;

	float pos_X, pos_Y;

	Spider(Point2 pos)

	{
		pix[0].readBMPFile("S:\\NS\\CG\\Lab 7 Computer Graphics spider\\spider1.bmp", 1);
		pix[1].readBMPFile("S:\\NS\\CG\\Lab 7 Computer Graphics spider\\spider.bmp", 1);
		pix[2].readBMPFile("S:\\NS\\CG\\Lab 7 Computer Graphics spider\\mak3.bmp", 1);
		pix[3].readBMPFile("S:\\NS\\CG\\Lab 7 Computer Graphics spider\\splash.bmp", 1);

		for (int i = 0; i < 4; i++)
			pix[i].setChromaKey(192, 192, 192);

		this->pos_X = pos.getX();
		this->pos_Y = pos.getY();
	}

	void changePosition(float dx, float dy)
	{
		this->pos_X += dx;
		this->pos_Y += dy;
	}

	void render();
	void changeMode(ModeType m);
	void run();
	void stay();
	void jump();
};

void Spider::render()
{

	switch (mode)
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

void Spider::stay()
{
	glRasterPos2i(this->pos_X, this->pos_Y);
	pix[0].mDraw();
}

void Spider::jump()
{
	pix[0].mDraw();
	glRasterPos2i(this->pos_X + 60, this->pos_Y + 50);
	this->pos_X += 50;
	pix[0].mDraw();
	state = STANDING;
	mode = STAY;
}

void Spider::run()
{
	switch (state)
	{

	case STANDING:

		state = RUNNING1;
		break;

	case RUNNING1:

		state = STANDING;
		break;
	}

	changePosition(20, 0);
	glRasterPos2i(this->pos_X, this->pos_Y);
	pix[state].mDraw();
}

void Spider::changeMode(ModeType m)
{
	if (mode == m)
		return;

	switch (m)
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
