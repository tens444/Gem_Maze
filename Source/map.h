#pragma once
#include "item.h"
#include "stdafx.h"

class Map
{
private:
	int map[16 + 1][9 + 1];
	sf::Texture texture[5];
	sf::Sprite sprite[5];
public:
	int mapitem[16 + 1][9 + 1];
public:
	Map();
	void Draw(sf::RenderWindow &);
	void Create(int floor);
	void Create0();
	void Create4(int floor, Back &back);
	void AddItem(int x, int y, int id);
};