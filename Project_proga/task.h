#pragma once
#include "SFML/Graphics.hpp"
#include "sheep.h"
#include "carrot.h"
#include "fermer.h"
#include "inventary.h"

sf::Text getTextMission(bool&, sf::Text&, int, int&);

std::string getText(int, int&);

void drawTask(sf::RenderWindow&, sf::Sprite&, sf::Text&, sf::View&, int, int, bool);

bool compliteTask(Player&, Inventary&, int&, int&);


