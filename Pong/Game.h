#pragma once
#include "Ball.h"
#include "Player.h"

class Game
{
	Ball* ball = nullptr;
	Player* player1 = nullptr;
	Player* player2 = nullptr;
	bool gameRunningFlag = true;
public:
	void update();
	void draw();
	void init();
	bool checkPlayerOneCollision();
	bool checkPlayerTwoCollision();
	Game();
	~Game();
};

