#pragma once
class Object
{
	
public:
	float timestamp;

	virtual void init() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

};

