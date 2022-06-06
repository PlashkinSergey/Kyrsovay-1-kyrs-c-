#include "inventary.h"

Inventary::Inventary(int x):maxMoney(10000), maxSeeds(10000), inv({ {"Семена", 0}, {"Монеты", 0} })
{
	maxSize = maxMoney + maxSeeds;
	curMoney = curSeeds = x;
	curMoney = x * 10.0;
	inv[0].second = curSeeds;
	inv[1].second = curMoney;
}

void Inventary::addMoney(int m)
{
	if ((curMoney < maxMoney) && !isFull())
	{
		if (m < maxMoney - curMoney)
		{
			inv[1].second += m;
			curMoney += m;
		}
		else
		{
			inv[1].second += maxMoney - curMoney;
			curMoney = maxMoney;
		}
	}
}

void Inventary::addSeeds(int s)
{
	if ((curSeeds < maxSeeds) && !isFull())
	{
		if (s < maxSeeds - curSeeds)
		{
			inv[0].second += s;
			curSeeds += s;
		}
		else
		{
			inv[0].second += maxSeeds - curSeeds;
			curSeeds = maxSeeds;
		}
	}
}

void Inventary::addMoneySeeds(int s, int m)
{
	addMoney(m);
	addSeeds(s);
}

void Inventary::delMoney(int m)
{
	if (!isEmpty())
	{
		if (m > curMoney)
		{
			inv[1].second = 0;
			curMoney = 0;
		}
		else
		{
			inv[1].second -= m;
			curMoney -= m;
		}
	}
}

void Inventary::delSeeds(int s)
{
	if (!isEmpty())
	{
		if (s > curSeeds)
		{
			inv[0].second = 0;
			curSeeds = 0;
		}
		else
		{
			inv[0].second -= s;
			curSeeds -= s;
		}
	}
}

void Inventary::delMoneySeeds(int s, int m)
{
	delMoney(m);
	delSeeds(s);
}

int& Inventary::operator[](int i)
{
	if (i >= 0 && i <= 1)
	{
		return inv[i].second;
	}
}

Inventary& Inventary::operator+(int m)
{
	addMoney(m);
	return *this;
}

Inventary Inventary::operator++(int)
{
	Inventary temp = *this;
	++(*this);
	return temp;
}

Inventary& Inventary::operator++()
{
	addMoney(1);
	return *this;
}

Inventary& Inventary::operator+=(int m)
{
	*this = *this + m;
	return *this;
}
