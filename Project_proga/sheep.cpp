#include "sheep.h"
using namespace sf;

Sheep::Sheep():Creature(0,0,0,0), dir(0)
{}

Sheep::Sheep(std::string F, float _x, float _y, float W, float H) :Creature(_x, _y, W, H), Download(F), dir(rand() % 4 + 1)
{
	sprite.setTextureRect(sf::IntRect(11, 11, w, h));
	sprite.setScale(2.0f, 2.0f);
}

void Sheep::update(float time)
{
	if (dir == 1)
	{
		currentFrame += 0.007 * time; 
		speed = 0.2;
		if (currentFrame > 3)
		{
			currentFrame -= 3;
		}
		sprite.setTextureRect(sf::IntRect(3*(int)currentFrame, 10, 35, 30));
	}
	else if (dir == 2)
	{
		currentFrame += 0.007 * time; 
		speed = 0.2;
		if (currentFrame > 3)
			currentFrame -= 3;
		sprite.setTextureRect(sf::IntRect(3 * (int)currentFrame, 55, 35, 32));
	}
	else if (dir == 3)
	{
		currentFrame += 0.007 * time; 
		speed = 0.2;
		if (currentFrame > 3)
			currentFrame -= 3;
		sprite.setTextureRect(sf::IntRect(3* (int)currentFrame, 95, 35, 25));
	}
	else if (dir == 4)
	{
		currentFrame += 0.007 * time; 
		speed = 0.2;
		if (currentFrame > 3)
			currentFrame -= 3;
		sprite.setTextureRect(sf::IntRect(3 * (int)currentFrame, 128, 30, 37));
	}
}

void Sheep::control(float time)
{
	update(time);
	switch (dir)
	{
	case 1: {
		dx = 0;
		dy = speed;
		break;
	}
	case 2: {
		dx = -speed;
		dy = 0;
		break;
	}
	case 3: {
		dx = speed;
		dy = 0;
		break;
	}
	case 4: {
		dx = 0;
		dy = -speed;
		break;
	}
	}
	x += dx * time;
	y += dy * time;
	sprite.setPosition(x, y);
	speed = 0;
	interectionMap();
}

void Sheep::setDir(int d)
{
	dir = d;
}

void Sheep::interectionMap()
{
	if (!IntRect(2 * 89, 2 * 89, 89 * 16, 89 * 16).contains(sprite.getGlobalBounds().left, sprite.getGlobalBounds().top) || !IntRect(2 * 89, 2 * 89, 89 * 16, 89 * 16).contains(sprite.getGlobalBounds().left + sprite.getGlobalBounds().width, sprite.getGlobalBounds().height + sprite.getGlobalBounds().top))
	{
		y = y < 2 * 89 ? 2 * 89 : y;
		x = x < 2 * 89 ? 2 * 89 : x;
		x = x + sprite.getGlobalBounds().width > 18 * 89 ? 18 * 89 - sprite.getGlobalBounds().width : x;
		y = y + sprite.getGlobalBounds().height > 17 * 89 ? 17 * 89 - sprite.getGlobalBounds().height : y;
		if (dir == 1)
			dir = 4;
		else if (dir == 4)
			dir = 1;
		else if (dir == 2)
			dir = 3;
		else if (dir == 3)
			dir = 2;
	}
}


