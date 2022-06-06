#include "Download.h"

Download::Download()
{}

Download::Download(std::string F)
{
	image.loadFromFile("images/" + F);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
}
