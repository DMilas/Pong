#include <iostream>
#include "Game.h"
#include "graphics.h"
#include "Config.h"
#include "Ball.h"
#include "Player.h"

void Game::update()
{

	if (state == State::mainMenu) {

		if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {
			ball->init();
			state = State::running;
		}
	}
	else if (state==State::running) {


		//update ball
		if (ball) {
			ball->update();
		}


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
				if (ball->isOutOfBounds() and ball->getPos_X()<CANVAS_WIDTH/2) {
					int tempScore = player2->getScore()+1;
					player2->setScore(tempScore);
					state=State::score;
				}
			}


			//Check Ball Collision with player 2
			if (checkPlayerTwoCollision()) {

			}
			else {
				if (ball->isOutOfBounds() and ball->getPos_X() > CANVAS_WIDTH / 2) {
					int tempScore = player1->getScore()+1;
					player1->setScore(tempScore);
					state = State::score;
				}
			}
		}

		//Player1 ShrinkRay Activation
		if (graphics::getKeyState(graphics::SCANCODE_D) and !player1->getShrinkFlag()) {
			shrinkRay = new ShrinkRay(player1, player2);
			state = State::shrinkRay;
		}

		//Player 2 ShrinkRay Activation
		if (graphics::getKeyState(graphics::SCANCODE_L) and !player2->getShrinkFlag()) {
			shrinkRay = new ShrinkRay(player2, player1);
			state = State::shrinkRay;
		}

		//Player 1 Redirect Ball
		if (graphics::getKeyState(graphics::SCANCODE_C) and !player1->getCurveBallFlag()) {
			ball->bounceBall();
			player1->setCurveBallFlag(true);
		}

		//Player 2 Redirect Ball
		if (graphics::getKeyState(graphics::SCANCODE_K) and !player2->getCurveBallFlag()) {
			ball->bounceBall();
			player2->setCurveBallFlag(true);
		}

		if (player1->getScore() == 5 or player2->getScore() == 5) {
			state = State::gameFinished;
		}
	}
	else if (state == State::shrinkRay) {
		if (shrinkRay) {
			if (shrinkRay)
				if (!shrinkRay->getShrinkFlag())
					shrinkRay->update();
				else {
					shrinkRay = nullptr;
					state = State::running;
				}
		}

	}

	else if (state == State::score) {
		resetBoard();
		state = State::running;
	}

	else  {

		if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {
			
			state = State::running;
		}
	}
}

void Game::draw()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH )+ "\\background.png";
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT/2, CANVAS_WIDTH, CANVAS_HEIGHT , br);
	
	//Draw mainMenu
	if (state == State::mainMenu) {
		graphics::Brush br2;

		br2.fill_color[0] = 0.9f;
		br2.fill_color[1] = 0.5f;
		br2.fill_color[2] = 0.9f;

		graphics::drawText(CANVAS_WIDTH / 8, CANVAS_HEIGHT / 4,100, "xTREME PoNG!", br2);
		graphics::drawText(CANVAS_WIDTH / 5, (CANVAS_HEIGHT / 9)*8, 50, "Press SPACE to START", br2);

	}
	else {
		//draw ball
		if (ball) {
			ball->draw();
		}

		//draw player 1
		if (player1) {
			player1->draw();
		}
		//draw plauer 2
		if (player2) {
			player2->draw();
		}
		//draw shrinkRay
		if (shrinkRay) {
			shrinkRay->draw();
		}

		if (state == State::score) {
			
		}

		if (state == State::paused) {
			graphics::Brush br;

			graphics::drawText(CANVAS_WIDTH / 4, CANVAS_HEIGHT / 2, 50, "Press Space to Continue", br);
		}

		// Draw winner's Text
		if (state == State::gameFinished) {
			if (player1->getScore() == 5) {
				graphics::Brush br;

				graphics::drawText(CANVAS_WIDTH / 4, CANVAS_HEIGHT / 2, 50, "Player one Won", br);
				graphics::drawText(CANVAS_WIDTH / 5, (CANVAS_HEIGHT / 9) * 8, 50, "Press SPACE to RESTART", br);
			}

			if (player2->getScore() == 5) {
				graphics::Brush br;

				graphics::drawText(CANVAS_WIDTH / 4, CANVAS_HEIGHT / 2, 50, "Player Two Won", br);
			}
		}
	}
	
}

void Game::init()
{
	//Init Game
	player1 = new Player(1);
	player2 = new Player(2);
	ball = new Ball(CANVAS_WIDTH/2,CANVAS_HEIGHT/2);
	graphics::playMusic(std::string(ASSET_PATH) + "\\Music.mp3", 0.3f, true, 5000);

	

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

		graphics::playSound(std::string(ASSET_PATH) + "\\Pen Clicking .mp3", 0.5f, false);
		ball->setHorizontalSpeed(ball->getHorizontalSpeed() * (-1));
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

		graphics::playSound(std::string(ASSET_PATH) + "\\Pen Clicking .mp3", 0.5f, false);
		ball->setHorizontalSpeed(ball->getHorizontalSpeed() * (-1));
		return true;
	}
	return false;
}

void Game::resetBoard()
{
	player1->setPlayerPosY(CANVAS_HEIGHT / 2);
	player2->setPlayerPosY(CANVAS_HEIGHT / 2);

	player1->setBarHeight(75);
	player2->setBarHeight(75);

	ball->setPosX(CANVAS_WIDTH / 2);
	ball->setPosY(CANVAS_HEIGHT / 2);

	ball->setHorizontalSpeed(2);
	ball->setVerticalSpeed(2);

}

Game::Game()
{
	state = State::mainMenu;
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

	if (shrinkRay) {
		delete shrinkRay;
	}
}
