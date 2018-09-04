#pragma once
#include "stdafx.h"
#include "SFML/Audio.hpp"
#include "data.h"

extern Data data;
extern sf::Music music;

int option(sf::RenderWindow &window)
{
	sf::Texture background;
	sf::Sprite backgrounds;

	background.loadFromFile("images/option/background.png");
	backgrounds.setTexture(background);

	sf::Texture back;
	back.setSmooth(true);
	static sf::Color color = sf::Color::Black;
	back.loadFromFile("images/back.png");
	sf::Sprite backs(back);
	backs.setPosition(735, 5);
	backs.setColor(color);

	sf::Texture op[2][2];
	sf::Sprite ops[2][2];
	op[0][0].loadFromFile("images/option/none.png");
	op[1][0].loadFromFile("images/option/none.png");
	op[0][1].loadFromFile("images/option/done.png");
	op[1][1].loadFromFile("images/option/done.png");
	ops[0][0].setTexture(op[0][0]);
	ops[1][0].setTexture(op[1][0]);
	ops[0][1].setTexture(op[0][1]);
	ops[1][1].setTexture(op[1][1]);
	ops[0][0].setPosition(710, 367);
	ops[1][0].setPosition(710, 405);
	ops[0][1].setPosition(710, 367);
	ops[1][1].setPosition(710, 405);

	sf::Event event;
	sf::Vector2<int> position;
	position = sf::Mouse::getPosition(window);
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::EventType::Closed)
			window.close();
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
			window.close();

		if (event.type == sf::Event::MouseMoved)
		{
			if (position.x > backs.getPosition().x&&position.x < backs.getPosition().x + back.getSize().x
				&& position.y > backs.getPosition().y&&position.y < backs.getPosition().y + back.getSize().y)
				color = sf::Color::White;
			else
				color = sf::Color::Black;
		}

		if (event.type == sf::Event::EventType::MouseButtonReleased)
		{
			if (position.x > backs.getPosition().x&&position.x < backs.getPosition().x + back.getSize().x
				&& position.y > backs.getPosition().y&&position.y < backs.getPosition().y + back.getSize().y)
				return MENU;
			if (position.x > ops[0][0].getPosition().x&&position.x < ops[0][0].getPosition().x + op[0][0].getSize().x
				&& position.y > ops[0][0].getPosition().y&&position.y < ops[0][0].getPosition().y + op[0][0].getSize().y)
			{
				if (data.is_music)	{ data.is_music = false; music.pause(); }
				else { data.is_music = true; music.play(); }
			}
			if (position.x > ops[1][0].getPosition().x&&position.x < ops[1][0].getPosition().x + op[1][0].getSize().x
				&& position.y > ops[1][0].getPosition().y&&position.y < ops[1][0].getPosition().y + op[1][0].getSize().y)
			{
				if (data.is_sound)	data.is_sound = false; else data.is_sound = true;
			}
		}
	}

	window.clear();
	window.draw(backgrounds);
	window.draw(backs);
	if (data.is_music)	window.draw(ops[0][1]); else window.draw(ops[0][0]);
	if (data.is_sound)	window.draw(ops[1][1]); else window.draw(ops[1][0]);
	window.display();
	return OPTION;
}