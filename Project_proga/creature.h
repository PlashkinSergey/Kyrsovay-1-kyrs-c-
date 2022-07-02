#pragma once
#include "SFML/Graphics.hpp"

class Creature
{
public:
	inline float getCordsY() { return y;}
	float getCordsX() { return x; }
	Creature(float, float, float, float);
	virtual sf::Sprite getSprite() = 0;
	virtual void control(float) = 0;
	virtual void interectionMap() = 0;
protected:
	virtual void update(float) = 0;
	std::string File;
	float currentFrame;
	float w, h, dx, dy, speed, x, y;
};
