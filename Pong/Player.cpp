#include "Player.h"
#include "graphics.h"
#include "Config.h"
#include <iostream>

using namespace std;

Player::Player(int pn)
{
	playerNumber = pn;
	switch (playerNumber)
	{
	default:
		break;
	case 1:
		pos_x = 10.0f;
		pos_y = CANVAS_HEIGHT / 2;
		score = 0;
		
		break;
	case 2:
		pos_x = CANVAS_WIDTH-10.0f;
		pos_y = CANVAS_HEIGHT / 2;
		score = 0;
		break;

	}
}

Player::~Player()
{
}

int Player::getPlayerNumber()
{
	return playerNumber;
}

float Player::getPlayerPosX()
{
	return pos_x;
}

float Player::getPlayerPosY()
{
	return pos_y;
}

int Player::getBarHeight()
{
	return barHeight;
}

int Player::getBarWidth()
{
	return barWidth;
}

int Player::getSpeed()
{
	return speed;
}

int Player::getScore()
{
	return score;
}

bool Player::getShrinkFlag()
{
	return shrinkRayFlag;
}

bool Player::getCurveBallFlag()
{
	return curveBallFlag;
}



void Player::setPlayerPosX(float x)
{
	pos_x = x;
}

void Player::setPlayerPosY(float y)
{
	pos_y = y;
}

void Player::setPlayerNumber(int pn)
{
	playerNumber = pn;
}

void Player::setBarWidth(int width)
{
	barWidth = width;
}

void Player::setBarHeight(int height)
{
	barHeight = height;
}



void Player::setSpeed(int s)
{
	speed = s;
}

void Player::setScore(int s)
{
	score = s;
}

void Player::setShrinkFlag(bool flag)
{
	shrinkRayFlag = flag;
}

void Player::setCurveBallFlag(bool flag)
{
	curveBallFlag = flag;
}

void Player::init()
{
}

void Player::update()
{
	if (graphics::getKeyState(graphics::SCANCODE_W) and playerNumber==1) {
		if(pos_y-barHeight/2>0)
		pos_y -= speed;
	}

	if (graphics::getKeyState(graphics::SCANCODE_S) and playerNumber == 1) {
		if(pos_y+barHeight/2< CANVAS_HEIGHT)
		pos_y += speed;
	}

	if (graphics::getKeyState(graphics::SCANCODE_UP) and playerNumber == 2) {
		if (pos_y - barHeight / 2 > 0)
			pos_y -= speed;
	}

	if (graphics::getKeyState(graphics::SCANCODE_DOWN) and playerNumber == 2) {
		if (pos_y + barHeight / 2 < CANVAS_HEIGHT)
			pos_y += speed;
	}

	
}

void Player::draw()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "\\bar.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(pos_x, pos_y, barWidth,barHeight , br);


	graphics::Brush br2;
	if (playerNumber == 1) {
		string temp = "Score : " + to_string(score);
		graphics::drawText(150, 30, 40, temp, br2);

		if (!curveBallFlag) {
			graphics::Brush br2;

			br2.texture = std::string(ASSET_PATH) + "\\Bounce.png";
			graphics::drawRect(60, CANVAS_HEIGHT - 15, 30,30, br2);
		}

		if (!shrinkRayFlag) {
			graphics::Brush br2;
			br2.outline_opacity = 0.0f;
			br2.texture = std::string(ASSET_PATH) + "\\RayGun.png";
			graphics::drawRect(30, CANVAS_HEIGHT - 15, 30, 30, br2);
		}
	}

	if (playerNumber == 2) {
		string temp = "Score : " + to_string(score);
		graphics::drawText(CANVAS_WIDTH - 350, 30, 40, temp , br2);


		if (!curveBallFlag) {
			graphics::Brush br2;
			br2.outline_opacity = 0.0f;
			br2.texture = std::string(ASSET_PATH) + "\\Bounce.png";
			graphics::drawRect(CANVAS_WIDTH-60, CANVAS_HEIGHT - 15, 30, 30, br2);
		}

		if (!shrinkRayFlag) {
			graphics::Brush br2;
			br2.outline_opacity = 0.0f;
			br2.texture = std::string(ASSET_PATH) + "\\RayGun.png";
			graphics::drawRect(CANVAS_WIDTH - 30, CANVAS_HEIGHT - 15, 30, 30, br2);
		}
	}


}
