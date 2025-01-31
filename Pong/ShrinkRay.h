#pragma once
#include "Object.h"
#include "Player.h"

class ShrinkRay : public Object
{
	float start_pos_x, start_pos_y, end_pos_x, end_pos_y;
	int speed=3;
	bool shrinkFlag = false;
	Player* playerTarget;
	Player* playerSource;

public:
	ShrinkRay(Player* source, Player* target);
	~ShrinkRay();
	void draw() override;
	void update() override;
	void init() override;
	void shrinkPlayer();
	bool getShrinkFlag();
	float calculateAngle();

};

