#pragma once
class Ball
{
public:
	float posX, posY;
	int size = 10;
	Ball(int x, int y);
	~Ball();
	void setPosX(float x);
	void setPosY(float y);

};

