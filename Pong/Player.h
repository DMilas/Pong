#pragma once
#include "Config.h"
#include "Object.h"

class Player : public Object
{
	float pos_x, 
		pos_y;

	int playerNumber,
		barWidth=20,
		barHeight=75,
		speed=5,
		score=0;

	bool curveBallFlag,
		shrinkRayFlag;
public:

	//Constructors
	Player(int pn);
	~Player();

	//getters
	int getPlayerNumber();
	float getPlayerPosX();
	float getPlayerPosY();
	int getBarHeight();
	int getBarWidth();
	int getSpeed();
	int getScore();

	//setters	
	void setPlayerPosX(float x);
	void setPlayerPosY(float y);
	void setPlayerNumber(int pn);
	void setBarWidth(int width);
	void setBarHeight(int height);
	void setSpeed(int s);
	void setScore(int s);

	//functions
	void init() override;
	void update() override;
	void draw() override;

};

