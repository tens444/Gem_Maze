#pragma once
#include "map.h"
#include "data.h"

extern Data data;

void Map::Create0()
{
	map[1][1] = 1;
	mapitem[1][1] = -2;
	for (int i = 2; i <= 15; i++)
	{
		map[i][1] = 2;
		mapitem[i][1] = -2;
	}
	map[16][1] = 3;
	mapitem[16][1] = -2;

	for (int i = 1; i <= 16; i++)
	{
		for (int j = 2; j <= 9; j++)
		{
			map[i][j] = 0;
			mapitem[i][j] = 0;
		}
	}
	mapitem[1][2] = -3;
}

void Map::Create4(int floor, Back &back)
{
	map[1][1] = 1;
	mapitem[1][1] = -2;
	for (int i = 2; i <= 15; i++)
	{
		map[i][1] = 2;
		mapitem[i][1] = -2;
	}
	map[16][1] = 3;
	mapitem[16][1] = -2;

	for (int i = 1; i <= 16; i++)
	{
		for (int j = 2; j <= 9; j++)
		{
			map[i][j] = 0;
			mapitem[i][j] = 0;
		}
	}
	mapitem[1][2] = -3;

	int flag = 0;
	while (!flag)
	{
		srand(data.clock.getElapsedTime().asMicroseconds());
		int r_x = (rand()) % 16 + 1;
		int r_y = (rand()) % 9 + 1;
		if (mapitem[r_x][r_y] == 0)
		{
			flag = 1;
			back.SetPositon(r_x, r_y);
			mapitem[r_x][r_y] = -1;
		}
	}

	for (int i = 1; i <= 1 + 2 * floor * (1 - data.barrier_p); i++)
	{
		srand(data.clock.getElapsedTime().asMicroseconds());
		int r_x = (rand() * i + i) % 16 + 1;
		int r_y = (rand() * i + i) % 9 + 1;
		if (mapitem[r_x][r_y] == 0)
		{
			map[r_x][r_y] = 4;
			mapitem[r_x][r_y] = -2;
		}
	}
}

void Map::Create(int floor)
{
	map[1][1] = 1;
	mapitem[1][1] = -2;
	for (int i = 2; i <= 15; i++)
	{
		map[i][1] = 2;
		mapitem[i][1] = -2;
	}
	map[16][1] = 3;
	mapitem[16][1] = -2;

	for (int i = 1; i <= 16; i++)
	{
		for (int j = 2; j <= 9; j++)
		{
			map[i][j] = 0;
			mapitem[i][j] = 0;
		}
	}
	mapitem[1][2] = -3;
	mapitem[16][9] = -1;

	for (int i = 1; i <= 1 + 2 * floor * (1 - data.barrier_p); i++)
	{
		srand(data.clock.getElapsedTime().asMicroseconds());
		int r_x = rand() % 16 + 1;
		int r_y = rand() % 9 + 1;
		if (mapitem[r_x][r_y] == 0)
		{
			map[r_x][r_y] = 4;
			mapitem[r_x][r_y] = -2;
		}
	}
}

void Map::Draw(sf::RenderWindow &window)
{
    for(int i = 1; i <= 16;i++)
    {
        for(int j = 1; j <= 9 ;j++)
		{
			sprite[map[i][j]].setPosition(50.f*(i - 1), 50.f*(j - 1));
			window.draw(sprite[map[i][j]]);
        }
    }
}

Map::Map()
{
	for (int i = 0; i < 5; i++)
	{
		texture[i].loadFromFile("images/map/1/" + std::to_string(i) + ".png");
		sprite[i].setTexture(texture[i]);
	}

	for (int i = 1; i <= 16; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			map[i][j] = 0;
			mapitem[i][j] = 0;
		}
	}
	mapitem[16][9] = -1;
}

void Map::AddItem(int x, int y, int id)
{
	mapitem[x][y] = id;
}