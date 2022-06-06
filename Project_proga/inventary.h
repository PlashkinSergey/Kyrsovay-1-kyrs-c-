#pragma once
#include <vector>
#include <string>

class Inventary 
{
public:
	explicit Inventary(int);
	void addMoney(int);
	void addSeeds(int);
	void addMoneySeeds(int, int);
	void delMoney(int);
	void delSeeds(int);
	void delMoneySeeds(int, int);
	int& operator[](int);
	Inventary& operator+(int);
	Inventary operator++(int);
	Inventary& operator++();
	Inventary& operator+=(int);
	bool isFull() const { return (curMoney + curSeeds) == maxSize; }
	bool isEmpty() const { return maxSize == 0; }
private:
	size_t maxMoney, maxSeeds, curMoney, curSeeds, maxSize;
	std::vector<std::pair<std::string, int>> inv;
};