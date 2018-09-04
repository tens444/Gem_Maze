#pragma once
#include "stdafx.h"
#include "map.h"

class Role
{
private:
	int x;
	int y;
	sf::Texture texture[16 + 1];
	sf::Sprite sprite[16 + 1];
	int toward;
	
public:
	Role();
	void Update(int x);
	int GetPositionX(){ return x; }
	int GetPositionY(){ return y; }
	void SetPosition(int x, int y);
	void Load();
	void Draw(sf::RenderWindow&);
	void MoveUp(Map &);
	void MoveDown(Map &);
	void MoveLeft(Map &);
	void MoveRight(Map &);
};