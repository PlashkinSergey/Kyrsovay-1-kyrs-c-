#pragma once
#include "SFML/Graphics.hpp"
#include "sheep.h"
#include <vector>

void addSheep(std::vector<Sheep*>& );

void drawSheep(std::vector<Sheep*>& , float, float&, sf::RenderWindow&);