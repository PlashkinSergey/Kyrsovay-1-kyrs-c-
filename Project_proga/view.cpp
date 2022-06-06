#include "view.h"

void getForView(float x, float y, sf::View& v,int width,int height)
{
	float tempX = x, tempY = y;
	tempX = -width / 2.0 + tempX > 0? (tempX + width / 2.0 < 20 * 89 ? tempX : 20.0 * 89 - width / 2.0) : width / 2.0;
	tempY = -height / 2.0 + tempY > 0 ? (tempY + height / 2.0 < 20 * 89 ? tempY : 20.0 * 89 - height / 2.0) :  height / 2.0;
	v.setCenter(tempX, tempY);
}