#include <ctime>
#include "inventary.h"
#include "task.h"
#include "map.h"
#include "view.h"
#include "fermer.h"
#include "sheep.h"
#include "generateSheep.h"
#include "carrot.h"
#include "showMenu.h"
#include "information.h"

int main()
{
	srand(time(NULL));
	Map map("map2.png");
	Player fermer("fermer.png", 200, 200, 56.0, 116.0, 0.35);
	Inventary invent(rand() % 10 + 10);
	std::vector<Sheep*> vecSheep;
	std::vector<sf::Text> text;
	sf::Font font;
	font.loadFromFile("font/CyrilicOld.TTF");
	for (int i = 0; i < 6; ++i)
	{
		sf::Text temp;
		temp.setString("");
		temp.setFont(font);
		temp.setCharacterSize(20);
		temp.setFillColor(sf::Color::Black);
		text.push_back(temp);
	}
	sf::RenderWindow window(sf::VideoMode(1280, 720), "ferma");
	showMenu(window);
	sf::Clock clock;
	sf::View view;
	view.reset(sf::FloatRect(0, 0, 1920, 1080));
	sf::Texture texture;
	texture.loadFromFile("images/mission.jpg");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 340, 510));
	sprite.setScale(0.5f, 0.5f);
	bool showMission = true;
	int curMission = 1, count = 0;
	float timer = 0;
	bool click = false;
	while (window.isOpen())
	{
		if (!vecSheep.size())
			addSheep(vecSheep);
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 1000;
		timer += time;
		int height = window.getSize().y;
		int width = window.getSize().x;
		map.checkGarden(time);
		view.setSize(width, height);
		int mouse_x = sf::Mouse::getPosition(window).x + view.getCenter().x - width / 2.0;
		int mouse_y = sf::Mouse::getPosition(window).y + view.getCenter().y - height / 2.0;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
					fermer.plantCarrot(mouse_x, mouse_y, fermer.getCordsX(), fermer.getCordsY(), map, invent);
				if (event.mouseButton.button == sf::Mouse::Right)
					fermer.collectCarrot(mouse_x, mouse_y, map);
			}
			if (event.key.code == sf::Keyboard::Space)
				fermer.catchSheep(vecSheep);
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Tab && showMission)
				{
					getTextMission(showMission, text[0], curMission, count);
					click = true;
				}
				if (event.key.code == sf::Keyboard::B)
					fermer.buySeed(invent);
				if (event.key.code == sf::Keyboard::C)
					fermer.saleSheep(invent);
				if (event.key.code == sf::Keyboard::X)
					fermer.saleCarrot(invent);
			}
		}
		getForView(fermer.getCordsX(), fermer.getCordsY(), view, width, height);
		fermer.control(time);
		window.setView(view);
		window.clear();
		window.draw(map);
		window.draw(fermer.getSprite());
		drawSheep(vecSheep, time, timer, window);
		if (!showMission)
			showMission = compliteTask(fermer, invent, count, curMission);
		if (click)
			drawTask(window, sprite, text[0], view, width, height, showMission);
		showInformation(fermer, invent, text, window, view, width, height);
		window.display();
	}
	return 0;
}