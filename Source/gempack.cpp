#pragma once
#include "stdafx.h"
#include "gempack.h"
#include "data.h"

extern Data data;
std::vector<Item*>::iterator dit;

GemPack::GemPack(int id, int num)
{
	this->id = id;
	this->num = num;
	texture.loadFromFile("images/gempack/un.png");
	sprite.setTexture(texture);

	switch (id)
	{
	case 1:
		v.push_back(new Gem(11, 4));
		v.push_back(new Gem(41, 3)); break;
	case 2:
		v.push_back(new Gem(21, 2));
		v.push_back(new Gem(31, 2)); 
		v.push_back(new Gem(41, 2));
		v.push_back(new Gem(51, 2)); break;
	case 3:
		v.push_back(new Gem(11, 4));
		v.push_back(new Gem(31, 2));
		v.push_back(new Gem(41, 1)); break;
	case 4:
		v.push_back(new Gem(51, 6)); break;
	case 5:
		v.push_back(new Gem(11, 1));
		v.push_back(new Gem(41, 4));
		v.push_back(new Gem(51, 2)); break;
	case 6:
		v.push_back(new Gem(21, 4));
		v.push_back(new Gem(31, 3)); break;
	case 7:
		v.push_back(new Gem(11, 3));
		v.push_back(new Gem(31, 3));
		v.push_back(new Gem(51, 2)); break;
	case 8:
		v.push_back(new Gem(21, 1));
		v.push_back(new Gem(31, 4));
		v.push_back(new Gem(51, 1)); break;
	case 9:
		v.push_back(new Gem(11, 1));
		v.push_back(new Gem(31, 4));
		v.push_back(new Gem(41, 3));break;
	case 10:
		v.push_back(new Gem(21, 2));
		v.push_back(new Gem(31, 2));
		v.push_back(new Gem(41, 2));
		v.push_back(new Gem(51, 2)); break;
	case 11:
		v.push_back(new Gem(11, 3));
		v.push_back(new Gem(41, 2));
		v.push_back(new Gem(51, 1)); break;
	case 12:
		v.push_back(new Gem(21, 7)); break;
	case 13:
		v.push_back(new Gem(11, 2));
		v.push_back(new Gem(41, 1));
		v.push_back(new Gem(51, 3)); break;
	case 14:
		v.push_back(new Gem(51, 8)); break;
	case 15:
		v.push_back(new Gem(41, 3));
		v.push_back(new Gem(51, 4)); break;
	case 16:
		v.push_back(new Gem(31, 2));
		v.push_back(new Gem(41, 3));
		v.push_back(new Gem(51, 3)); break;
	case 17:
		v.push_back(new Gem(41, 3));
		v.push_back(new Gem(51, 4)); break;
	case 18:
		v.push_back(new Gem(21, 1));
		v.push_back(new Gem(41, 4));
		v.push_back(new Gem(51, 2)); break;
	case 19:
		v.push_back(new Gem(11, 3));
		v.push_back(new Gem(31, 3)); break;
	case 20:
		v.push_back(new Gem(41, 4));
		v.push_back(new Gem(51, 4)); break;
	case 21:
		v.push_back(new Gem(41, 3));
		v.push_back(new Gem(51, 3)); break;
	case 22:
		v.push_back(new Gem(21, 2));
		v.push_back(new Gem(31, 4));
		v.push_back(new Gem(41, 1)); break;
	case 23:
		v.push_back(new Gem(41, 3));
		v.push_back(new Gem(51, 3)); break;
	case 24:
		v.push_back(new Gem(31, 3));
		v.push_back(new Gem(41, 2));
		v.push_back(new Gem(51, 2)); break;
	case 25:
		v.push_back(new Gem(11, 3));
		v.push_back(new Gem(31, 3)); break;
	case 26:
		v.push_back(new Gem(41, 3));
		v.push_back(new Gem(51, 3)); break;
	case 27:
		v.push_back(new Gem(11, 1));
		v.push_back(new Gem(31, 2));
		v.push_back(new Gem(41, 5)); break;
	case 28:
		v.push_back(new Gem(21, 7)); break;
	case 29:
		v.push_back(new Gem(11, 3));
		v.push_back(new Gem(31, 1));
		v.push_back(new Gem(51, 3)); break;
	case 30:
		v.push_back(new Gem(11, 2));
		v.push_back(new Gem(21, 2));
		v.push_back(new Gem(31, 2));
		v.push_back(new Gem(51, 2)); break;
	case 31:
		v.push_back(new Gem(41, 5));
		v.push_back(new Gem(51, 2)); break;
	case 32:
		v.push_back(new Gem(21, 1));
		v.push_back(new Gem(41, 5)); break;
	case 33:
		v.push_back(new Gem(11, 2));
		v.push_back(new Gem(41, 5)); break;
	case 34:
		v.push_back(new Gem(51, 6)); break;
	case 35:
		v.push_back(new Gem(41, 5));
		v.push_back(new Gem(51, 2)); break;
	case 36:
		v.push_back(new Gem(21, 2));
		v.push_back(new Gem(41, 2));
		v.push_back(new Gem(51, 2)); break;
	case 37:
		v.push_back(new Gem(11, 6));
		v.push_back(new Gem(41, 2)); break;
	case 38:
		v.push_back(new Gem(31, 4));
		v.push_back(new Gem(51, 4)); break;
	case 39:
		v.push_back(new Gem(11, 3));
		v.push_back(new Gem(31, 4)); break;
	case 40:
		v.push_back(new Gem(21, 6));
		v.push_back(new Gem(51, 2)); break;
	}
	statue = 0;
}

int GemPack::Up()
{
	bool flag = true;

	if (statue == 2) return 2;

	if (num == 0) return -1;

	std::vector<Gem*>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
	{
		for (dit = data.items.begin(); dit != data.items.end(); dit++)
		{
			if ((*dit)->id == (*it)->id)
			{
				if ((*dit)->num < (*it)->num)
					return 0;
				else
					break;
			}
		}
		if (dit == data.items.end())
			return 0;
	}

	num--;

	for (it = v.begin(); it != v.end(); it++)
	{
		data.DeleteItem((*it)->id, (*it)->num);
	}

	if (statue == 0)
	{
		texture.loadFromFile("images/gempack/unfinished/" + std::to_string(id) + ".png");
		v.clear();
		switch (id)
		{
		case 1:
			v.push_back(new Gem(12, 4));
			v.push_back(new Gem(42, 3)); break;
		case 2:
			v.push_back(new Gem(22, 2));
			v.push_back(new Gem(32, 2));
			v.push_back(new Gem(42, 2));
			v.push_back(new Gem(52, 2)); break;
		case 3:
			v.push_back(new Gem(12, 4));
			v.push_back(new Gem(32, 2));
			v.push_back(new Gem(42, 1)); break;
		case 4:
			v.push_back(new Gem(52, 6)); break;
		case 5:
			v.push_back(new Gem(12, 1));
			v.push_back(new Gem(42, 4));
			v.push_back(new Gem(52, 2)); break;
		case 6:
			v.push_back(new Gem(22, 4));
			v.push_back(new Gem(32, 3)); break;
		case 7:
			v.push_back(new Gem(12, 3));
			v.push_back(new Gem(32, 3));
			v.push_back(new Gem(52, 2)); break;
		case 8:
			v.push_back(new Gem(22, 1));
			v.push_back(new Gem(32, 4));
			v.push_back(new Gem(52, 1)); break;
		case 9:
			v.push_back(new Gem(12, 1));
			v.push_back(new Gem(32, 4));
			v.push_back(new Gem(42, 3)); break;
		case 10:
			v.push_back(new Gem(22, 2));
			v.push_back(new Gem(32, 2));
			v.push_back(new Gem(42, 2));
			v.push_back(new Gem(52, 2)); break;
		case 11:
			v.push_back(new Gem(12, 3));
			v.push_back(new Gem(42, 2));
			v.push_back(new Gem(52, 1)); break;
		case 12:
			v.push_back(new Gem(22, 7)); break;
		case 13:
			v.push_back(new Gem(12, 2));
			v.push_back(new Gem(42, 1));
			v.push_back(new Gem(52, 3)); break;
		case 14:
			v.push_back(new Gem(52, 8)); break;
		case 15:
			v.push_back(new Gem(42, 3));
			v.push_back(new Gem(52, 4)); break;
		case 16:
			v.push_back(new Gem(32, 2));
			v.push_back(new Gem(42, 3));
			v.push_back(new Gem(52, 3)); break;
		case 17:
			v.push_back(new Gem(42, 3));
			v.push_back(new Gem(52, 4)); break;
		case 18:
			v.push_back(new Gem(22, 1));
			v.push_back(new Gem(42, 4));
			v.push_back(new Gem(52, 2)); break;
		case 19:
			v.push_back(new Gem(12, 3));
			v.push_back(new Gem(32, 3)); break;
		case 20:
			v.push_back(new Gem(42, 4));
			v.push_back(new Gem(52, 4)); break;
		case 21:
			v.push_back(new Gem(42, 3));
			v.push_back(new Gem(52, 3)); break;
		case 22:
			v.push_back(new Gem(22, 2));
			v.push_back(new Gem(32, 4));
			v.push_back(new Gem(42, 1)); break;
		case 23:
			v.push_back(new Gem(42, 3));
			v.push_back(new Gem(52, 3)); break;
		case 24:
			v.push_back(new Gem(32, 3));
			v.push_back(new Gem(42, 2));
			v.push_back(new Gem(52, 2)); break;
		case 25:
			v.push_back(new Gem(12, 3));
			v.push_back(new Gem(32, 3)); break;
		case 26:
			v.push_back(new Gem(42, 3));
			v.push_back(new Gem(52, 3)); break;
		case 27:
			v.push_back(new Gem(12, 1));
			v.push_back(new Gem(32, 2));
			v.push_back(new Gem(42, 5)); break;
		case 28:
			v.push_back(new Gem(22, 7)); break;
		case 29:
			v.push_back(new Gem(12, 3));
			v.push_back(new Gem(32, 1));
			v.push_back(new Gem(52, 3)); break;
		case 30:
			v.push_back(new Gem(12, 2));
			v.push_back(new Gem(22, 2));
			v.push_back(new Gem(32, 2));
			v.push_back(new Gem(52, 2)); break;
		case 31:
			v.push_back(new Gem(42, 5));
			v.push_back(new Gem(52, 2)); break;
		case 32:
			v.push_back(new Gem(22, 1));
			v.push_back(new Gem(42, 5)); break;
		case 33:
			v.push_back(new Gem(12, 2));
			v.push_back(new Gem(42, 5)); break;
		case 34:
			v.push_back(new Gem(52, 6)); break;
		case 35:
			v.push_back(new Gem(42, 5));
			v.push_back(new Gem(52, 2)); break;
		case 36:
			v.push_back(new Gem(22, 2));
			v.push_back(new Gem(42, 2));
			v.push_back(new Gem(52, 2)); break;
		case 37:
			v.push_back(new Gem(12, 6));
			v.push_back(new Gem(42, 2)); break;
		case 38:
			v.push_back(new Gem(32, 4));
			v.push_back(new Gem(52, 4)); break;
		case 39:
			v.push_back(new Gem(12, 3));
			v.push_back(new Gem(32, 4)); break;
		case 40:
			v.push_back(new Gem(22, 6));
			v.push_back(new Gem(52, 2)); break;
		}
		statue = 1;
		return 1;
	}
	else if (statue == 1)
	{
		texture.loadFromFile("images/gempack/finished/" + std::to_string(id) + ".png");
		v.clear();
		statue = 2;
		return 1;
	}

	return -2;
}

void GemPack::SetPosition(int x, int y)
{
	this->x = x;
	this->y = y;
	sprite.setPosition(x + (170 - texture.getSize().x) / 2, y);
}

void GemPack::Draw(sf::RenderWindow &window)
{
	static sf::Font font;
	font.loadFromFile("font/msyhbd.ttf");
	static sf::Text number[5];
	static sf::Text numbers;

	window.draw(sprite);
	std::vector<Gem*>::iterator it;
	int count = 0;
	for (it = v.begin(); it != v.end(); it++)
	{
		if (++count % 2 != 0)
		{
			(*it)->realx = x + 15;
			(*it)->realy = y + 160 + (count - 1) / 2 * 60;
		}
		else
		{
			(*it)->realx = x + 85;
			(*it)->realy = y + 160 + (count - 1) / 2 * 60;
		}
		(*it)->Draw(window);

		int curnum = 0;

		for (dit = data.items.begin(); dit != data.items.end();dit++)
		{
			if ((*dit)->id == (*it)->id)
			{
				curnum = (*dit)->num; break;
			}
		}

		number[count].setPosition((*it)->realx + 32, (*it)->realy + 20);
		number[count].setFont(font);
		number[count].setCharacterSize(13);
		number[count].setString(std::to_string(curnum) + " / " + std::to_string((*it)->num));
		if (curnum >= (*it)->num)	number[count].setColor(sf::Color::Green);
		else    number[count].setColor(sf::Color::Red);
		window.draw(number[count]);
	}

	sf::Color color(150, 90, 31);
	numbers.setPosition(x + 40, 345);
	numbers.setFont(font);
	numbers.setColor(color);
	numbers.setCharacterSize(20);
	numbers.setString(std::to_string(num));
	window.draw(numbers);
}