#include "Ball.h"

Ball::Ball(int x, int y)
{
	posX = x;
	posY = y;
}

Ball::~Ball()
{
}

void Ball::setPosX(float x)
{
	posX = x;
}

void Ball::setPosY(float y)
{
	posY = y;
}
