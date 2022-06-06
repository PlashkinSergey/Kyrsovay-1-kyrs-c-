#include "carrot.h"

Carrot::Carrot() : Vegetables()
{}

void Carrot::setTime(float t)
{
	timeGrow += t;
}

float Carrot::getTime()
{
	return timeGrow;
}

int Carrot::getStadia()
{
	return stadia;
}

void Carrot::setStadia(int x)
{
	stadia = x;
}
