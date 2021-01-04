#pragma once
#include "Object.h"
#include "graphics.h"
#include "Config.h"

class Ball : public Object
{

	float pos_x = CANVAS_WIDTH / 2,
		pos_y = CANVAS_HEIGHT / 2,
		speedUpdateTimestamp;

	int size = 15,
		verticalSpeed = 2,
		horizontalSpeed = 2;
	
	bool curvedFlag=false;

public:
	//Constructors
	Ball();
	Ball(int x, int y);
	~Ball();

	//Getters
	float getPos_X();
	float getPos_Y();
	int getVerticalSpeed();
	int getHorizontalSpeed();
	int getSize();

	//Setters
	void setPosX(float x);
	void setPosY(float y);
	void setVerticalSpeed(int s);
	void setHorizontalSpeed(int s);
	void setSize(int s);
	
	//Functions
	bool isOutOfBounds();
	void init() override;
	void update() override;
	void draw() override;


};

