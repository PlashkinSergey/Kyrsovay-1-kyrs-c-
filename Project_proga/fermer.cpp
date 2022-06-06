#include "map.h"
#include "fermer.h"

Player::Player(std::string F, float X, float Y, float W, float H, float s) : Creature(X, Y, W, H), Download(F), radius(50)
{
	stat = Player::direction::down;
	speed = s;
	sprite.setTextureRect(sf::IntRect(0, 0, w, h));
}

void Player::update(float time)
{
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A))) 
	{
		stat = Player::left; speed = 0.25;
		currentFrame += 0.007 * time;
		if (currentFrame > 3) currentFrame -= 3;
		sprite.setTextureRect(sf::IntRect(54 * 2 * (int)currentFrame, 163, 55, 120));
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D))) 
	{
		stat = Player::right; speed = 0.25;
		currentFrame += 0.007 * time;
		if (currentFrame > 3) currentFrame -= 3;
		sprite.setTextureRect(sf::IntRect(54 * 2 * (int)currentFrame, 470, 55, 120));
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
	{
		stat = Player::up; speed = 0.25;
		currentFrame += 0.007 * time;
		if (currentFrame > 3) currentFrame -= 3;
		sprite.setTextureRect(sf::IntRect(54 * 2 * (int)currentFrame, 318, 56, 116));
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
	{
		stat = Player::down; speed = 0.25;
		currentFrame += 0.007 * time;
		if (currentFrame > 3) currentFrame -= 3;
		sprite.setTextureRect(sf::IntRect(54 * 2 * (int)currentFrame, 0, 60, 116));
	}
}

void Player::interectionMap()
{
	if (!sf::IntRect(2 * 89, 2 * 89, 89 * 16, 89 * 16).contains(sprite.getGlobalBounds().left, sprite.getGlobalBounds().top) || !sf::IntRect(2 * 89, 2 * 89, 89 * 16, 89 * 16).contains(sprite.getGlobalBounds().left + sprite.getGlobalBounds().width, sprite.getGlobalBounds().height + sprite.getGlobalBounds().top))
	{
		y = y < 1 * 89 ? 1 * 89 : y;
		x = x < 2 * 89 ? 2 * 89 : x;
		x = x + sprite.getGlobalBounds().width > 18 * 89 ? 18 * 89 - sprite.getGlobalBounds().width : x;
		y = y + sprite.getGlobalBounds().height > 18 * 89 ? 18 * 89 - sprite.getGlobalBounds().height : y;
	}
}

void Player::plantCarrot(int x, int y, int fx, int fy, Map& m, Inventary& i)
{
	if (i[0] != 0)
	{
		int temp = m.clickChecked(x, y, fx, fy);
		if (temp)
			i.delSeeds(1);
	}
}

void Player::clearSheep()
{
	sheep.clear();
}

void Player::clearCarrot()
{
	carrot.clear();
}

void Player::catchSheep(std::vector<Sheep*>& s)
{
	sf::CircleShape center;
	center.setRadius(radius);
	center.setPosition(x + 26 - radius, y + 60 - radius);
	for (size_t x = 0; x < s.size(); x++)
	{
		if (center.getGlobalBounds().contains(sf::Vector2f(s[x]->getCordsX(), s[x]->getCordsY())))
		{
			sheep.push_back(s[x]);
			Sheep* temp = s[x];
			s[x] = s[s.size() - 1];
			s[s.size() - 1] = temp;
			s.pop_back();
		}
	}
}

void Player::collectCarrot(int x, int y, Map& m)
{
	if (m.checkCarrot(x, y, getCordsX(), getCordsY()))
		carrot.push_back(new Carrot);
}

void Player::saleSheep(Inventary& inv)
{
	if (getCurSheep() && !inv.isFull())
	{
		inv += getCurSheep() * 30;
		clearSheep();
	}

}

void Player::saleCarrot(Inventary& inv)
{
	if (getCurCarrot() && !inv.isFull())
	{
		inv += getCurCarrot() * 8;
		clearCarrot();
	}

}

void Player::buySeed(Inventary& inv)
{
	if (!inv[0]  && inv[1])
	{
		inv.addSeeds(10);
		inv.delMoney(50);
	}
	else if (inv[0] != 0 && inv[1] != 0)
	{
		inv.addSeeds(1);
		inv.delMoney(5);
	}
}

void Player::control(float time)
{
	update(time);
	switch (stat)
	{
	case right: {
		dx = speed;
		dy = 0;  
		break; 
	}
	case left: {
		dx = -speed; 
		dy = 0;  
		break; 
	}
	case down: { 
		dx = 0; 
		dy = speed;   
		break; 
	}
	case up: {
		dx = 0; 
		dy = -speed;  
		break; 
	}
	}
	x += dx * time;
	y += dy * time;
	speed = 0;
	sprite.setPosition(x, y);
	interectionMap();
}

