#include "ShrinkRay.h"
#include "graphics.h"
#include <iostream>

ShrinkRay::ShrinkRay(Player* source, Player* target)
{
	start_pos_x = source->getPlayerPosX();
	start_pos_y = source->getPlayerPosY();
	end_pos_x = target->getPlayerPosX();
	end_pos_y = target->getPlayerPosY();
	playerTarget = target;
}

ShrinkRay::~ShrinkRay()
{
}

void ShrinkRay::draw()
{
	graphics::Brush br;
	br.texture = (std::string)(ASSET_PATH)+"\\beam.png";
	br.outline_opacity = 0.0f;
	if(start_pos_y<=end_pos_y+playerTarget->getBarHeight()/2 or
	start_pos_y >= end_pos_y - playerTarget->getBarHeight() / 2 )
	graphics::setOrientation(ShrinkRay::calculateAngle());
	graphics::drawRect(start_pos_x, start_pos_y, 80, 50, br);
	graphics::resetPose();

	
}

void ShrinkRay::update()
{
	if (start_pos_x>=end_pos_x) 
		start_pos_x -= int(start_pos_x + end_pos_x) /speed*2;

	if (start_pos_y >= end_pos_y)
		start_pos_y -= int(start_pos_y + end_pos_y) /speed;

	if (start_pos_x <= end_pos_x) 
		start_pos_x += int(start_pos_x + end_pos_x) /speed*2;

	if (start_pos_y <= end_pos_y)
		start_pos_y += int(start_pos_y + end_pos_y) / speed;

	if (int(start_pos_x) <= int(end_pos_x))
		shrinkPlayer();
}

void ShrinkRay::init()
{
}

void ShrinkRay::shrinkPlayer()
{	
	//fix timing
	float temp = playerTarget->getBarHeight();
	playerTarget->setBarHeight(int(temp / 2));
	//fix exit of the loop
	delete this;
}

float ShrinkRay::calculateAngle()
{	
	float x = start_pos_x - end_pos_x;
	float y = start_pos_y - end_pos_y;
	
	float calculatedSin = x / y;
	if (calculatedSin == INFINITY)return 0.0f;

	float angle= (cosf(calculatedSin)*(-10));
	
	return angle;
}
