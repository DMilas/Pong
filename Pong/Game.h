#pragma once
#include "Ball.h"
#include "Player.h"
#include "ShrinkRay.h"
#include "Config.h"

class Game
{
	//Variables
	enum class State :int { 
		mainMenu=1,
		running=2 ,
		paused=3 ,
		shrinkRay=4,
		score=5,
		gameFinished=6};
	State state;
	Ball* ball = nullptr;
	Player* player1 = nullptr;
	Player* player2 = nullptr;
	ShrinkRay* shrinkRay = nullptr;
	bool gameRunningFlag = true;

public:

	//functions
	void update();
	void draw();
	void init();
	bool checkPlayerOneCollision();
	bool checkPlayerTwoCollision();
	void resetBoard();

	//constructors
	Game();
	~Game();
};

