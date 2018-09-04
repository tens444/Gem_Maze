#pragma once
#include "stdafx.h"

class Item
{
public:
	int num;
	int id;
public:
	Item() : num(1) {}
	Item(int id, int num = 1) {this->id = id; this->num = num; }
};

class Visible_Item : public Item
{
protected:
	int x;
	int y;
public:
	virtual void Draw(sf::RenderWindow &window){};
	virtual void SetPositon(int x, int y);
	int GetPositionX(){ return x; }
	int GetPositionY(){ return y; }
	friend class Map;
};

class Back : public Visible_Item
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Back();
	void Draw(sf::RenderWindow &window);
};

class Gem : public Visible_Item
{
private:
	sf::Texture texture[33];
	sf::Sprite sprite[33];
	int count;
	int realx;
	int realy;
public:
	Gem(int id);
	Gem(int id, int num);
	void SetPositon(int x, int y);
	void Draw(sf::RenderWindow &window);
	friend class GemPack;
};

class Token : public Visible_Item
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Token(int id);
	void Draw(sf::RenderWindow &window);
};

class Pack : public Visible_Item
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Pack();
	void Draw(sf::RenderWindow &window);
};

class Time : public Visible_Item
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Time(int id);
	void Draw(sf::RenderWindow &window);
};