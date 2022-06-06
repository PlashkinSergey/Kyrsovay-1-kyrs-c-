#include "task.h"
#include <sstream>

sf::Text getTextMission(bool& show, sf::Text &text, int cur, int &count)
{
	std::string textTask = getText(cur, count);

	text.setFillColor(sf::Color::Black);
	switch (show)
	{
	case true:
	{
		std::ostringstream task;
		task << textTask;
		text.setString("Текущая миссия:\n" +  task.str());
		show = false;
		break;
	}
	case false:
	{
		text.setString("");
		show = true;
		break;
	}
	}
	return text;
}

std::string getText(int cur, int& count)
{
	std::ostringstream ss;
	count = rand() % 1000 + 1;
	std::string textTask = " ";
	if (cur % 2 == 0)
	{
		ss << count;
		textTask = "Собрать морковь\nв колличестве:\n " + ss.str();
	}
	else
	{
		ss << count;
		textTask = "Поймать овец\nв колличестве:\n" + ss.str();
	}
	return textTask;
}

void drawTask(sf::RenderWindow& win, sf::Sprite& s, sf::Text& t, sf::View& v, int w, int h, bool show)
{
	if (show)
	{
		t.setFillColor(sf::Color(228, 228, 27));
		t.setString("Задание Выполнено");
		t.setPosition(v.getCenter().x - w / 2.0 + 5, v.getCenter().y - h / 2.0);
		win.draw(t);
	}
	else
	{
		t.setPosition(v.getCenter().x - w / 2.0 + 5, v.getCenter().y - h / 2.0);
		s.setPosition(v.getCenter().x - w / 2.0, v.getCenter().y - h / 2.0);
		win.draw(s);
		win.draw(t);
	}
}

bool compliteTask(Player& p, Inventary& inv, int& count, int& cur)
{
	if (cur % 2 == 0)
	{
		if (p.getCurCarrot() >= count)
		{
			int money = 10 + p.getCurCarrot();
			++cur;
			inv += money;
			return true;
		}
	}
	else if (cur % 2 != 0)
	{
		if (p.getCurSheep() >= count)
		{
			int money = 15 + p.getCurSheep();
			++cur;
			inv += money;
			return true;
		}
	}
	return false;
}

