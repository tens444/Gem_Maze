#include "stdafx.h"
#include "role.h"

Role::Role()
{
	for (int i = 1; i <= 16; i++)
	{
		texture[i].loadFromFile("images/role/none.png");
		sprite[i].setTexture(texture[i]);
	}
	x = 1;
	y = 2;
	toward = 0;
}

void Role::Update(int x)
{
	if (x == 0)
	{
		for (int i = 1; i <= 8; i++)
		{
			texture[i].loadFromFile("images/role/none.png");
			sprite[i].setTexture(texture[i]);
		}
	}
	else
	{
		for (int i = 1; i <= 16; i++)
		{
			texture[i].loadFromFile("images/role/" + std::to_string(x) + '/' + std::to_string(i) + ".png");
			sprite[i].setTexture(texture[i]);
		}
	}
}

void Role::SetPosition(int x, int y)
{
    this->x = x;
	this->y = y;
}

void Role::Draw(sf::RenderWindow& window)
{
	static int count = 1;
	if (++count == 9) count = 1;
	sprite[count + toward].setPosition(50*(x-1) ,50*(y-1));
    window.draw(sprite[count + toward]);
}

void Role::MoveUp(Map &map)
{
	if (y > 2 && map.mapitem[x][y - 1] != -2)	y--;
}

void Role::MoveDown(Map &map)
{
	if (y < 9 && map.mapitem[x][y + 1] != -2)	y++;
}

void Role::MoveLeft(Map &map)
{
	if (x > 1 && map.mapitem[x - 1][y] != -2)	x--;
	toward = 8;
}

void Role::MoveRight(Map &map)
{
	if (x < 16 && map.mapitem[x + 1][y] != -2)	x++;
	toward = 0;
}