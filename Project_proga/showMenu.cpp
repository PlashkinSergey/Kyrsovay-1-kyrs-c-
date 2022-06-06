#include "showMenu.h"

void showMenu(sf::RenderWindow& w)
{
	sf::Texture menuTexture1, menuTexture2, menuBackground;
	menuTexture1.loadFromFile("images/111.png");
	menuTexture2.loadFromFile("images/333.png");
	menuBackground.loadFromFile("images/fon.jpg");
	sf::Sprite menu1(menuTexture1), menu2(menuTexture2), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(100, 300);
	menu2.setPosition(100, 400);
	menuBg.setPosition(0, 0);
	while (isMenu)
	{
		menu1.setColor(sf::Color::Red);
		menu2.setColor(sf::Color::Red);
		menuNum = 0;
		w.clear();
		if (sf::IntRect(100, 300, 300, 50).contains(sf::Mouse::getPosition(w))) 
		{ 
			menu1.setColor(sf::Color::Blue); 
			menuNum = 1; 
		}
		if (sf::IntRect(100, 400, 300, 50).contains(sf::Mouse::getPosition(w))) 
		{ 
			menu2.setColor(sf::Color::Blue); 
			menuNum = 2; 
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (menuNum == 1) 
				isMenu = false;
			if (menuNum == 2) 
			{ 
				w.close(); 
				isMenu = false; 
			}
		}
		w.draw(menuBg);
		w.draw(menu1);
		w.draw(menu2);
		w.display();
	}
}