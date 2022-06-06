#pragma once

class Vegetables
{
public:
	Vegetables();
	explicit Vegetables(int);
	virtual void setTime(float t) = 0;
	virtual float getTime() = 0;
	virtual int getStadia() = 0;
	virtual void setStadia(int) = 0;
protected:
	int stadia;
	float timeGrow;
};