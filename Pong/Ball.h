#pragma once
#include "Object.h"
#include "Config.h"

class Ball : public Object
{

	float pos_x=CANVAS_WIDTH/2, pos_y=CANVAS_HEIGHT/2;
	int size = 15, verticalSpeed = 2, horizontalSpeed = 2;

public:
	Ball();
	Ball(int x, int y);
	~Ball();

	float getPos_X();
	float getPos_Y();
	int getVerticalSpeed();
	int getHorizontalSpeed();
	int getSize();


	void setPosX(float x);
	void setPosY(float y);
	void setVerticalSpeed(int s);
	void setHorizontalSpeed(int s);
	void setSize(int s);

	bool isOutOfBounds();
	void init() override;
	void update() override;
	void draw() override;


};

