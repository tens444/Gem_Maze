#pragma once
#include "stdafx.h"

int start(sf::RenderWindow &window)
{
	sf::Texture texture;
	texture.loadFromFile("images/start.png");
	sf::Sprite sprite(texture);

	sf::Font font;
	font.loadFromFile("font/msyhbd.ttf");
	sf::Text begin;
	static sf::Color color(sf::Color::White);
	
	static int change = 10;
	if (color.b + change > 255||color.b + change <0)	change = -change;
	color.b += change;
	color.r += change;
	color.g += change;

	begin.setFont(font);
	begin.setCharacterSize(20);
	begin.setString(L"按任意键以开始游戏......");
	begin.setPosition(300, 400);
	begin.setColor(color);

	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::EventType::Closed)
			window.close();
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
			window.close();
		if (event.type == sf::Event::EventType::KeyPressed || event.type == sf::Event::EventType::MouseButtonReleased)
		{
			return MENU;
		}
	}

	window.clear();
	window.draw(sprite);
	window.draw(begin);
	window.display();
	return START;
}