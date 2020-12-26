#include <iostream>
#include "Game.h"
#include "graphics.h"
#include "Config.h"
#include "Ball.h"
#include "Player.h"

void Game::update()
{
	if (gameRunningFlag) {
		//Create ball


		//update ball
		if (ball) {
			ball->update();
		}

		//Create Players

		//Update Player

		if (player1) {
			player1->update();
		}

		if (player2) {
			player2->update();
		}

		if (//Check if ball is near the edges
			ball->getPos_X()<ball->getSize()*2
			or
			ball->getPos_X()>CANVAS_WIDTH-(ball->getSize()*2)
			) {
			//Check Ball Collision with player 1
			if (checkPlayerOneCollision()) {

			}
			else {
				if (ball->isOutOfBounds()) {
					int tempScore = player2->getScore();
					player2->setScore(tempScore++);
					gameRunningFlag = false;
				}
			}


			//Check Ball Collision with player 2
			if (checkPlayerTwoCollision()) {

			}
			else {
				if (ball->isOutOfBounds()) {
					int tempScore = player1->getScore();
					player1->setScore(tempScore++);
					gameRunningFlag = false;
				}
			}
		}

	}
	else {
		if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {
			init();
			gameRunningFlag = true;
		}
	}
}

void Game::draw()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH )+ "\\chalkboard.png";
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT/2, CANVAS_WIDTH, CANVAS_HEIGHT , br);

	//draw player
	if (ball) {
		ball->draw();
	}

	//draw player
	if (player1) {
		player1->draw();
	}

	if (player2) {
		player2->draw();
	}
}

void Game::init()
{

	player1 = new Player(1);
	player2 = new Player(2);
	ball = new Ball(CANVAS_WIDTH/2,CANVAS_HEIGHT/2);

}

bool Game::checkPlayerOneCollision()
{
	//Check Ball Collision with player 1
	if (
		//Check if the edge of the ball matches the edge of the player1 bar
		ball->getPos_X() - ball->getSize() / 2 <= player1->getPlayerPosX() + player1->getBarWidth() / 2
		and
		//Check if the ball Y coordinate is between the upper and lower edge of the player1 bar
		ball->getPos_Y() >= player1->getPlayerPosY() - player1->getBarHeight() / 2
		and
		ball->getPos_Y() <= player1->getPlayerPosY() + player1->getBarHeight() / 2
		)
		//when successfull redirect ball
	{
		ball->setHorizontalSpeed(ball->getHorizontalSpeed() * (-1));
		std::cout << "Collision happened with player one\n";
		return true;
	}
	return false;
}

bool Game::checkPlayerTwoCollision()
{
	//Check Ball Collision with player 2
	if (
		//Check if the edge of the ball matches the edge of the player1 bar
		ball->getPos_X() + ball->getSize() / 2 <= player2->getPlayerPosX() - player2->getBarWidth() / 2
		and
		//Check if the ball Y coordinate is between the upper and lower edge of the player2 bar
		ball->getPos_Y() >= player2->getPlayerPosY() - player2->getBarHeight() / 2
		and
		ball->getPos_Y() <= player2->getPlayerPosY() + player2->getBarHeight() / 2
		)
		//when successfull redirect ball
	{
		ball->setHorizontalSpeed(ball->getHorizontalSpeed() * (-1));
		std::cout << "Collision happened with player two\n";
		return true;
	}
	return false;
}

Game::Game()
{
}

Game::~Game()
{
	if (ball) {
		delete ball;
	}

	if (player1) {
		delete player1;
	}

	if (player2) {
		delete player2;
	}
}
