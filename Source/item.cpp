#pragma once
#include "item.h"
#include "data.h"

extern std::map<int, std::string> ID;
extern Data data;

void Visible_Item::SetPositon(int x, int y)
{
	this->x = x;
	this->y = y;
}

Back::Back()
{
	id = -1;
	x = 16;
	y = 9;
	texture.loadFromFile("images/re.png");
	sprite.setTexture(texture);
	sprite.setPosition(50 * (x-1) + 9.0f, 50 * (y-1) + 9.0f);
}

void Back::Draw(sf::RenderWindow &window)
{
	sprite.setPosition(50 * (x - 1) + 9.0f, 50 * (y - 1) + 9.0f);
	window.draw(sprite);
}

void Gem::SetPositon(int x, int y)
{
	this->x = x;
	this->y = y;

	realx = 50 * (x - 1) + 9.0f;
	realy = 50 * (y - 1) + 9.0f;
}

Gem::Gem(int id)
{
	this->id = id;
	std::string name = ID[id];
	count = 0;
	texture[1].loadFromFile("images/item/gem/" + name + "/1.png");
	texture[2].loadFromFile("images/item/gem/" + name + "/2.png");
	texture[3].loadFromFile("images/item/gem/" + name + "/3.png");
	texture[4].loadFromFile("images/item/gem/" + name + "/4.png");
	texture[5].loadFromFile("images/item/gem/" + name + "/5.png");
	texture[6].loadFromFile("images/item/gem/" + name + "/6.png");
	texture[7].loadFromFile("images/item/gem/" + name + "/7.png");
	texture[8].loadFromFile("images/item/gem/" + name + "/8.png");
	texture[9].loadFromFile("images/item/gem/" + name + "/9.png");
	texture[10].loadFromFile("images/item/gem/" + name + "/10.png");
	texture[11].loadFromFile("images/item/gem/" + name + "/11.png");
	texture[12].loadFromFile("images/item/gem/" + name + "/12.png");
	texture[13].loadFromFile("images/item/gem/" + name + "/13.png");
	texture[14].loadFromFile("images/item/gem/" + name + "/14.png");
	texture[15].loadFromFile("images/item/gem/" + name + "/15.png");
	texture[16].loadFromFile("images/item/gem/" + name + "/16.png");
	texture[17].loadFromFile("images/item/gem/" + name + "/17.png");
	texture[18].loadFromFile("images/item/gem/" + name + "/18.png");
	texture[19].loadFromFile("images/item/gem/" + name + "/19.png");
	texture[20].loadFromFile("images/item/gem/" + name + "/20.png");
	texture[21].loadFromFile("images/item/gem/" + name + "/21.png");
	texture[22].loadFromFile("images/item/gem/" + name + "/22.png");
	texture[23].loadFromFile("images/item/gem/" + name + "/23.png");
	texture[24].loadFromFile("images/item/gem/" + name + "/24.png");
	texture[25].loadFromFile("images/item/gem/" + name + "/25.png");
	texture[26].loadFromFile("images/item/gem/" + name + "/26.png");
	texture[27].loadFromFile("images/item/gem/" + name + "/27.png");
	texture[28].loadFromFile("images/item/gem/" + name + "/28.png");
	texture[29].loadFromFile("images/item/gem/" + name + "/29.png");
	texture[30].loadFromFile("images/item/gem/" + name + "/30.png");
	texture[31].loadFromFile("images/item/gem/" + name + "/31.png");
	texture[32].loadFromFile("images/item/gem/" + name + "/32.png");

	srand(data.clock.getElapsedTime().asMilliseconds() * id);
	SetPositon(rand() % 16 + 1, rand() % 9 + 1);

	realx = 50 * (x - 1) + 9.0f;
	realy = 50 * (y - 1) + 9.0f;

	for (int i = 1; i <= 32; i++)
		sprite[i].setTexture(texture[i]);
}

Gem::Gem(int id, int num)
{
	this->id = id;
	this->num = num;
	std::string name = ID[id];
	count = 0;
	texture[1].loadFromFile("images/item/gem/" + name + "/1.png");
	texture[2].loadFromFile("images/item/gem/" + name + "/2.png");
	texture[3].loadFromFile("images/item/gem/" + name + "/3.png");
	texture[4].loadFromFile("images/item/gem/" + name + "/4.png");
	texture[5].loadFromFile("images/item/gem/" + name + "/5.png");
	texture[6].loadFromFile("images/item/gem/" + name + "/6.png");
	texture[7].loadFromFile("images/item/gem/" + name + "/7.png");
	texture[8].loadFromFile("images/item/gem/" + name + "/8.png");
	texture[9].loadFromFile("images/item/gem/" + name + "/9.png");
	texture[10].loadFromFile("images/item/gem/" + name + "/10.png");
	texture[11].loadFromFile("images/item/gem/" + name + "/11.png");
	texture[12].loadFromFile("images/item/gem/" + name + "/12.png");
	texture[13].loadFromFile("images/item/gem/" + name + "/13.png");
	texture[14].loadFromFile("images/item/gem/" + name + "/14.png");
	texture[15].loadFromFile("images/item/gem/" + name + "/15.png");
	texture[16].loadFromFile("images/item/gem/" + name + "/16.png");
	texture[17].loadFromFile("images/item/gem/" + name + "/17.png");
	texture[18].loadFromFile("images/item/gem/" + name + "/18.png");
	texture[19].loadFromFile("images/item/gem/" + name + "/19.png");
	texture[20].loadFromFile("images/item/gem/" + name + "/20.png");
	texture[21].loadFromFile("images/item/gem/" + name + "/21.png");
	texture[22].loadFromFile("images/item/gem/" + name + "/22.png");
	texture[23].loadFromFile("images/item/gem/" + name + "/23.png");
	texture[24].loadFromFile("images/item/gem/" + name + "/24.png");
	texture[25].loadFromFile("images/item/gem/" + name + "/25.png");
	texture[26].loadFromFile("images/item/gem/" + name + "/26.png");
	texture[27].loadFromFile("images/item/gem/" + name + "/27.png");
	texture[28].loadFromFile("images/item/gem/" + name + "/28.png");
	texture[29].loadFromFile("images/item/gem/" + name + "/29.png");
	texture[30].loadFromFile("images/item/gem/" + name + "/30.png");
	texture[31].loadFromFile("images/item/gem/" + name + "/31.png");
	texture[32].loadFromFile("images/item/gem/" + name + "/32.png");

	srand(data.clock.getElapsedTime().asMilliseconds() * id);
	SetPositon(rand() % 16 + 1, rand() % 9 + 1);

	realx = 50 * (x - 1) + 9.0f;
	realy = 50 * (y - 1) + 9.0f;

	for (int i = 1; i <= 32; i++)
		sprite[i].setTexture(texture[i]);
}

void Gem::Draw(sf::RenderWindow &window)
{
	if (count == 32)	count = 1;
	else count++;
	sprite[count].setPosition(realx, realy);
	window.draw(sprite[count]);
}

Token::Token(int id)
{
	this->id = id;
	std::string name = ID[id];
	texture.loadFromFile("images/item/" + name);
	sprite.setTexture(texture);
}

void Token::Draw(sf::RenderWindow &window)
{
	sprite.setPosition(50 * (x - 1) + 5.0f, 50 * (y - 1) + 5.0f);
	window.draw(sprite);
}

Pack::Pack()
{
	id = 101;
	texture.loadFromFile("images/gempack/unknown.png");
	sprite.setTexture(texture);
}

void Pack::Draw(sf::RenderWindow &window)
{
	sprite.setPosition(50 * (x - 1) + 5.0f, 50 * (y - 1) + 5.0f);
	window.draw(sprite);
}

Time::Time(int id)
{
	this->id = id;
	texture.loadFromFile("images/item/" + ID[id] + ".png");
	sprite.setTexture(texture);
}

void Time::Draw(sf::RenderWindow &window)
{
	sprite.setPosition(50 * (x - 1) + 5.0f, 50 * (y - 1) + 5.0f);
	window.draw(sprite);
}