#pragma once
#include "stdafx.h"
#include <vector>
#include "item.h"

class GemPack
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	int x;
	int y;
	int statue;

public:
	int id;
	int num;
	std::vector<Gem*> v;
	void SetPosition(int x, int y);
	int Up();
	void Draw(sf::RenderWindow &window);
	friend class Data;
	friend void workshop_draw(sf::RenderWindow &window);
	GemPack();
	GemPack(int id, int num = 1);
};