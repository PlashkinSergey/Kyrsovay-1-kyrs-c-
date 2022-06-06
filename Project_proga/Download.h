#pragma once
#include "SFML/Graphics.hpp"

class Download
{
public:
	Download();
	explicit Download(std::string);
protected:
	sf::Image image;
	sf::Sprite sprite;
	sf::Texture texture;
};