#include "Ball.h"
#include "graphics.h"
#include "Config.h"
#include <iostream>

Ball::Ball()
{
}

Ball::Ball(int x, int y)
{
	pos_x = x;
	pos_y = y;
}

Ball::~Ball()
{
}

float Ball::getPos_X()
{
	return pos_x;
}

float Ball::getPos_Y()
{
	return pos_y;
}

int Ball::getVerticalSpeed()
{
	return verticalSpeed;
}

int Ball::getHorizontalSpeed()
{
	return horizontalSpeed;
}

int Ball::getSize()
{
	return size;
}

void Ball::setPosX(float x)
{
	pos_x = x;
}

void Ball::setPosY(float y)
{
	pos_y = y;
}

void Ball::setVerticalSpeed(int s)
{
	verticalSpeed = s;
}

void Ball::setHorizontalSpeed(int s)
{
	horizontalSpeed = s;
}



void Ball::setSize(int s)
{
	size = s;
}

bool Ball::isOutOfBounds()
{
	return pos_x<0 or pos_x>CANVAS_WIDTH;
}

void Ball::init()
{
	speedUpdateTimestamp = graphics::getGlobalTime();
}

void Ball::update()
{
	if (!curvedFlag) {
		pos_y += verticalSpeed;
		pos_x += horizontalSpeed;
	}
	else {
		pos_y += verticalSpeed * sinf(graphics::getGlobalTime() / 500);
		pos_x += horizontalSpeed;
	}

	if(pos_y < 0)setVerticalSpeed(verticalSpeed*(-1));
	if(pos_y > CANVAS_HEIGHT)setVerticalSpeed(verticalSpeed*(-1));
	
	if (pos_x < 0)setHorizontalSpeed(horizontalSpeed * (-1));
	if (pos_x > CANVAS_WIDTH)setHorizontalSpeed(horizontalSpeed * (-1));

	//Cheat to curve/uncurve the ball
	if (graphics::getKeyState(graphics::SCANCODE_C)) {
		timestamp = graphics::getGlobalTime();
		curvedFlag = !curvedFlag;
	}

	//Reset curveFlag
	if (curvedFlag and (int)(graphics::getGlobalTime()-timestamp) >1000) {
		curvedFlag = !curvedFlag;
	}

	//Increase ball speed
	if (graphics::getGlobalTime() - speedUpdateTimestamp > 5000) {
		if (verticalSpeed > 0)
			verticalSpeed++;
		else
			verticalSpeed--;

		if (horizontalSpeed > 0)
			horizontalSpeed++;
		else
			horizontalSpeed--;
		speedUpdateTimestamp = graphics::getGlobalTime();
	}

	

}

void Ball::draw()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "\\ball.png";
	br.outline_opacity = 0.0f;
	graphics::drawDisk(pos_x, pos_y, size, br);


}
