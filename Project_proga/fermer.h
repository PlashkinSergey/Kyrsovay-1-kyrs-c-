#pragma once
#include "map.h"
#include "inventary.h"
#include "sheep.h"
#include "carrot.h"


class Player :public Download, public Creature
{
public:
	Player(std::string, float, float, float, float, float);
	virtual void control(float) override; 
	virtual sf::Sprite getSprite() override { return sprite; }
	virtual void interectionMap() override;
	void plantCarrot(int x, int y, int fx, int fy, Map&, Inventary&);
	int getCurSheep() { return sheep.size(); }
	int getCurCarrot() { return carrot.size(); }
	void clearSheep();
	void clearCarrot();
	int getMoney(Inventary& inv) { return inv[1]; }
	void catchSheep(std::vector<Sheep*>&);
	void collectCarrot(int, int, Map&);
	void saleSheep(Inventary&);
	void saleCarrot(Inventary&);
	void buySeed(Inventary&);
private:
	std::vector<Sheep*> sheep;
	std::vector<Carrot*> carrot;
	int radius;
	enum direction 
	{ 
		up, left, down, right 
	} stat;
protected:
	void update(float) override;
};