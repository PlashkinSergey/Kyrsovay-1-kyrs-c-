#include "information.h"

void showInformation(Player& p, Inventary& i, std::vector<sf::Text>& t, sf::RenderWindow& window, sf::View& v, int w, int h)
{
	std::ostringstream curSheep, curCarrot, curSeed, curMoney;
	curSheep << p.getCurSheep(); 
	curCarrot << p.getCurCarrot(); 
	curSeed << i[0]; 
	curMoney << i[1];
	for (size_t i = 1; i < 5; ++i) 
	{
		t[i].setFillColor(sf::Color(228, 228, 27));
		t[i].setCharacterSize(25);
	}
	t[1].setString("Колличество пойманный овец: " + curSheep.str());
	t[2].setString("Колличество собранной моркови: " + curCarrot.str());
	t[3].setString("Монеты: " + curMoney.str());
	t[4].setString("Семена: " + curSeed.str());
	t[1].setPosition(v.getCenter().x - w / 2.0 + 900, v.getCenter().y - h / 2.0);
	t[2].setPosition(v.getCenter().x - w / 2.0 + 900, v.getCenter().y - h / 2.0 + 50);
	t[3].setPosition(v.getCenter().x - w / 2.0 + 700, v.getCenter().y - h / 2.0);
	t[4].setPosition(v.getCenter().x - w / 2.0 + 700, v.getCenter().y - h / 2.0 + 50);
	window.draw(t[1]);
	window.draw(t[2]);
	window.draw(t[3]);
	window.draw(t[4]);
}
