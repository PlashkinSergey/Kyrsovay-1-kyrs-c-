#pragma once
#include "map.h"
#include "vegetables.h"

class Carrot: public Vegetables
{
public:
	Carrot();
	virtual void setTime(float t) override;
	virtual float getTime() override;
	virtual int getStadia() override;
	virtual void setStadia(int) override;
};
