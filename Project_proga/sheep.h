#pragma once
#include "creature.h"
#include "Download.h"

class Sheep : public Creature, public Download
{
public:
	Sheep();
	Sheep(std::string, float, float, float, float);
	virtual sf::Sprite getSprite() override { return sprite; }
	virtual void control(float) override;
	int getDir() { return dir; }
	void setDir(int);
	virtual void interectionMap() override;
protected:
	virtual void update(float) override;
	int dir;
};
