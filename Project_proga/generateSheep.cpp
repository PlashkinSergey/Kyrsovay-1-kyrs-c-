#include "generateSheep.h"

void addSheep(std::vector<Sheep*>& v)
{
	int size = rand() % 5 + 20;
	for (int i = 0; i < size; ++i)
		v.push_back(new Sheep("sheep.png", rand() % 1300 + 300, rand() % 1300 + 300, 19, 30));
	return;
}

void drawSheep(std::vector<Sheep*>& v, float time, float& timer, sf::RenderWindow& w)
{
	bool flag = true;
	for (int i = 0; i < v.size(); ++i)
	{
		v[i]->control(time);
		if (timer >= 2000)
		{
			v[i]->setDir(rand() % 4 + 1);
			flag = false;
		}
		w.draw(v[i]->getSprite());
	}
	if (!flag)
		timer = 0;
	return;
}