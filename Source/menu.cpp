#pragma once
#include "stdafx.h"
#include "data.h"

extern Data data;

extern sf::Sound actions;

sf::Texture background;
sf::Sprite backgrounds;

sf::Texture a[5];
sf::Texture b[5];
sf::Sprite as[5];
sf::Sprite bs[5];

sf::Texture status;
sf::Sprite statuss;
sf::Texture bag;
sf::Sprite bags;
sf::Texture gem;
sf::Sprite gems;
sf::Texture magic;
sf::Sprite magics;
sf::Texture option;
sf::Sprite options;

sf::Texture frame[5];
sf::Sprite frames[5];

sf::Font menufont;
sf::Text name[5];
sf::Text cooltime[5];
sf::Text _cooltime[5];

void menu_init()
{
	background.loadFromFile("images/menu.png");
	backgrounds.setTexture(background);

	a[0].loadFromFile("images/land/01a.png");
	b[0].loadFromFile("images/land/01b.png");
	a[1].loadFromFile("images/land/02a.png");
	b[1].loadFromFile("images/land/02b.png");
	a[2].loadFromFile("images/land/03a.png");
	b[2].loadFromFile("images/land/03b.png");
	a[3].loadFromFile("images/land/04a.png");
	b[3].loadFromFile("images/land/04b.png");
	a[4].loadFromFile("images/land/05a.png");
	b[4].loadFromFile("images/land/05b.png");

	as[0].setTexture(a[0]);
	as[0].setPosition(100, 45);
	as[1].setTexture(a[1]);
	as[1].setPosition(324, 45);
	as[2].setTexture(a[2]);
	as[2].setPosition(548, 45);
	as[3].setTexture(a[3]);
	as[3].setPosition(212, 230);
	as[4].setTexture(a[4]);
	as[4].setPosition(436, 230);
	bs[0].setTexture(b[0]);
	bs[0].setPosition(100, 45);
	bs[1].setTexture(b[1]);
	bs[1].setPosition(324, 45);
	bs[2].setTexture(b[2]);
	bs[2].setPosition(548, 45);
	bs[3].setTexture(b[3]);
	bs[3].setPosition(212, 230);
	bs[4].setTexture(b[4]);
	bs[4].setPosition(436, 230);

	status.loadFromFile("images/menu/status.png");
	statuss.setTexture(status);
	statuss.setPosition(80, 380);

	bag.loadFromFile("images/menu/bag.png");
	bags.setTexture(bag);
	bags.setPosition(224, 380);

	gem.loadFromFile("images/menu/gem.png");
	gems.setTexture(gem);
	gems.setPosition(368, 380);

	magic.loadFromFile("images/menu/magic.png");
	magics.setTexture(magic);
	magics.setPosition(512, 380);

	option.loadFromFile("images/menu/option.png");
	options.setTexture(option);
	options.setPosition(656, 380);

	frame[0].loadFromFile("images/frame.png");
	frames[0].setTexture(frame[0]);
	frames[0].setPosition(statuss.getPosition().x, statuss.getPosition().y);
	frame[1].loadFromFile("images/frame.png");
	frames[1].setTexture(frame[1]);
	frames[1].setPosition(bags.getPosition().x, bags.getPosition().y);
	frame[2].loadFromFile("images/frame.png");
	frames[2].setTexture(frame[2]);
	frames[2].setPosition(gems.getPosition().x, gems.getPosition().y);
	frame[3].loadFromFile("images/frame.png");
	frames[3].setTexture(frame[3]);
	frames[3].setPosition(magics.getPosition().x, magics.getPosition().y);
	frame[4].loadFromFile("images/frame.png");
	frames[4].setTexture(frame[4]);
	frames[4].setPosition(options.getPosition().x, options.getPosition().y);

	menufont.loadFromFile("font/msyh.ttf");
	name[0].setFont(menufont);
	name[0].setCharacterSize(15);
	name[0].setString(L"宝石迷宫 ①");
	name[0].setPosition(140, 20);

	name[1].setFont(menufont);
	name[1].setCharacterSize(15);
	name[1].setString(L"宝石迷宫 ②");
	name[1].setPosition(364, 20);

	name[2].setFont(menufont);
	name[2].setCharacterSize(15);
	name[2].setString(L"宝石迷宫 ③");
	name[2].setPosition(588, 20);

	name[3].setFont(menufont);
	name[3].setCharacterSize(15);
	name[3].setString(L"特殊关卡 ④");
	name[3].setPosition(252, 205);

	name[4].setFont(menufont);
	name[4].setCharacterSize(15);
	name[4].setString(L"特殊关卡 ⑤");
	name[4].setPosition(476, 205);

	cooltime[1].setFont(menufont);
	cooltime[1].setColor(sf::Color::Red);
	cooltime[1].setCharacterSize(15);
	cooltime[1].setString(L"冷却时间：");
	cooltime[1].setPosition(354, 165);
	_cooltime[1].setFont(menufont);
	_cooltime[1].setColor(sf::Color::Red);
	_cooltime[1].setCharacterSize(15);
	_cooltime[1].setPosition(434, 165);

	cooltime[2].setFont(menufont);
	cooltime[2].setColor(sf::Color::Red);
	cooltime[2].setCharacterSize(15);
	cooltime[2].setString(L"冷却时间：");
	cooltime[2].setPosition(578, 165);
	_cooltime[2].setFont(menufont);
	_cooltime[2].setColor(sf::Color::Red);
	_cooltime[2].setCharacterSize(15);
	_cooltime[2].setPosition(658, 165);

	cooltime[3].setFont(menufont);
	cooltime[3].setColor(sf::Color::Red);
	cooltime[3].setCharacterSize(15);
	cooltime[3].setString(L"冷却时间：");
	cooltime[3].setPosition(242, 350);
	_cooltime[3].setFont(menufont);
	_cooltime[3].setColor(sf::Color::Red);
	_cooltime[3].setCharacterSize(15);
	_cooltime[3].setPosition(322, 350);

	cooltime[4].setFont(menufont);
	cooltime[4].setColor(sf::Color::Red);
	cooltime[4].setCharacterSize(15);
	cooltime[4].setString(L"冷却时间：");
	cooltime[4].setPosition(466, 350);
	_cooltime[4].setFont(menufont);
	_cooltime[4].setColor(sf::Color::Red);
	_cooltime[4].setCharacterSize(15);
	_cooltime[4].setPosition(546, 350);
}

int button(sf::RenderWindow &window)
{
	static bool frame[5] = { 0 };
	static bool act[5] = { 0 };
	static bool warning[5] = { 0 };

	sf::Vector2<int> position;
	position = sf::Mouse::getPosition(window);
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::EventType::Closed)
			window.close();
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
			window.close();

		if (event.type == sf::Event::MouseMoved)
		{
			if (position.x > statuss.getPosition().x&&position.x < statuss.getPosition().x + status.getSize().x
				&& position.y > statuss.getPosition().y&&position.y < statuss.getPosition().y + status.getSize().y)
			{
				if (!frame[0]&&data.is_sound)
					actions.play();
				frame[0] = true;
			}
			else    frame[0] = false;
			if (position.x > bags.getPosition().x&&position.x < bags.getPosition().x + bag.getSize().x
				&& position.y > bags.getPosition().y&&position.y < bags.getPosition().y + bag.getSize().y)
			{
				if (!frame[1] && data.is_sound)
					actions.play();
				frame[1] = true;
			}
			else    frame[1] = false;
			if (position.x > gems.getPosition().x&&position.x < gems.getPosition().x + gem.getSize().x
				&& position.y > gems.getPosition().y&&position.y < gems.getPosition().y + gem.getSize().y)
			{
				if (!frame[2] && data.is_sound)
					actions.play();
				frame[2] = true;
			}
			else    frame[2] = false;
			if (position.x > magics.getPosition().x&&position.x < magics.getPosition().x + magic.getSize().x
				&& position.y > magics.getPosition().y&&position.y < magics.getPosition().y + magic.getSize().y)
			{
				if (!frame[3] && data.is_sound)
					actions.play();
				frame[3] = true;
			}
			else    frame[3] = false;
			if (position.x > options.getPosition().x&&position.x < options.getPosition().x + option.getSize().x
				&& position.y > options.getPosition().y&&position.y < options.getPosition().y + option.getSize().y)
			{
				if (!frame[4] && data.is_sound)
					actions.play();
				frame[4] = true;
			}
			else    frame[4] = false;
			if (position.x > bs[0].getPosition().x&&position.x < bs[0].getPosition().x + b[0].getSize().x
				&& position.y > bs[0].getPosition().y&&position.y < bs[0].getPosition().y + b[0].getSize().y)
			{
				if (!act[0] && data.is_sound)
					actions.play();
				act[0] = true;
			}
			else    act[0] = false;
			if (position.x > bs[1].getPosition().x&&position.x < bs[1].getPosition().x + b[1].getSize().x
				&& position.y > bs[1].getPosition().y&&position.y < bs[1].getPosition().y + b[1].getSize().y)
			{
				if (data.ac[0] == 3 || data.cool_time[1].getElapsedTime().asSeconds() >= 150 - data.cool_time_down)
				{
					if (!act[1] && data.is_sound)
						actions.play();
					warning[1] = false;
					act[1] = true;
				}
				else
				{
					warning[1] = true;
					act[1] = false;
				}
			}
			else
			{
				act[1] = false;
				warning[1] = false;
			}
			if (position.x > bs[2].getPosition().x&&position.x < bs[2].getPosition().x + b[2].getSize().x
				&& position.y > bs[2].getPosition().y&&position.y < bs[2].getPosition().y + b[2].getSize().y)
			{
				if (data.ac[0] == 3 || data.cool_time[2].getElapsedTime().asSeconds() >= 300 - data.cool_time_down)
				{
					if (!act[2] && data.is_sound)
						actions.play();
					warning[2] = false;
					act[2] = true;
				}
				else
				{
					warning[2] = true;
					act[2] = false;
				}
			}
			else
			{
				act[2] = false;
				warning[2] = false;
			}
			if (position.x > bs[3].getPosition().x&&position.x < bs[3].getPosition().x + b[3].getSize().x
				&& position.y > bs[3].getPosition().y&&position.y < bs[3].getPosition().y + b[3].getSize().y)
			{
				if (data.moneyget < 20000 || data.ac[0] != 3 && data.cool_time[3].getElapsedTime().asSeconds() < 300 - data.cool_time_down)
				{
					warning[3] = true;
					act[3] = false;
				}
				else
				{
					if (!act[3] && data.is_sound)
						actions.play();
					warning[3] = false;
					act[3] = true;
				}
			}
			else
			{
				act[3] = false;
				warning[3] = false;
			}
			if (position.x > bs[4].getPosition().x&&position.x < bs[4].getPosition().x + b[4].getSize().x
				&& position.y > bs[4].getPosition().y&&position.y < bs[4].getPosition().y + b[4].getSize().y)
			{
				if (data.moneyget < 50000 || data.ac[0] != 3 && data.cool_time[4].getElapsedTime().asSeconds() < 300 - data.cool_time_down)
				{
					warning[4] = true;
					act[4] = false;
				}
				else
				{
					if (!act[4] && data.is_sound)
						actions.play();
					warning[4] = false;
					act[4] = true;
				}
			}
			else
			{
				act[4] = false;
				warning[4] = false;
			}
		}

		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (position.x > statuss.getPosition().x&&position.x < statuss.getPosition().x + status.getSize().x
				&& position.y > statuss.getPosition().y&&position.y < statuss.getPosition().y + status.getSize().y)
			{
				return STATUS_INIT;
			}
			if (position.x > bags.getPosition().x&&position.x < bags.getPosition().x + bag.getSize().x
				&& position.y > bags.getPosition().y&&position.y < bags.getPosition().y + bag.getSize().y)
			{
				return BAG_INIT;
			}
			if (position.x > gems.getPosition().x&&position.x < gems.getPosition().x + gem.getSize().x
				&& position.y > gems.getPosition().y&&position.y < gems.getPosition().y + gem.getSize().y)
			{
				return WORKSHOP_INIT;
			}
			if (position.x > magics.getPosition().x&&position.x < magics.getPosition().x + magic.getSize().x
				&& position.y > magics.getPosition().y&&position.y < magics.getPosition().y + magic.getSize().y)
			{
				if (data.moneyget < 10000)	return UNFINISHED;
				return SCHOOL_INIT;
			}
			if (position.x > options.getPosition().x&&position.x < options.getPosition().x + option.getSize().x
				&& position.y > options.getPosition().y&&position.y < options.getPosition().y + option.getSize().y)
			{
				return OPTION;
			}
			if (position.x > bs[0].getPosition().x&&position.x < bs[0].getPosition().x + b[0].getSize().x
				&& position.y > bs[0].getPosition().y&&position.y < bs[0].getPosition().y + b[0].getSize().y)
			{
				if (act[0])
				{
					act[0] = false;
					data.floor = 0;
					data.extra_time = 0;
					data.game_time.restart();
					return ONE_INIT;
				}
			}
			if (position.x > bs[1].getPosition().x&&position.x < bs[1].getPosition().x + b[1].getSize().x
				&& position.y > bs[1].getPosition().y&&position.y < bs[1].getPosition().y + b[1].getSize().y)
			{
				if (act[1])
				{
					act[1] = false;
					data.floor = 0;
					data.extra_time = 0;
					data.game_time.restart();
					data.cool_time[1].restart();
					return TWO_INIT;
				}
			}
			if (position.x > bs[2].getPosition().x&&position.x < bs[2].getPosition().x + b[2].getSize().x
				&& position.y > bs[2].getPosition().y&&position.y < bs[2].getPosition().y + b[2].getSize().y)
			{
				if (act[2])
				{
					act[2] = false;
					data.floor = 0;
					data.extra_time = 0;
					data.game_time.restart();
					data.cool_time[2].restart();
					return THREE_INIT;
				}
			}
			if (position.x > bs[3].getPosition().x&&position.x < bs[3].getPosition().x + b[3].getSize().x
				&& position.y > bs[3].getPosition().y&&position.y < bs[3].getPosition().y + b[3].getSize().y)
			{
				if (act[3])
				{
					act[3] = false;
					data.floor = 0;
					data.game_time.restart();
					data.cool_time[3].restart();
					return FOUR_INIT;
				}
				return UNFINISHED;
			}
			if (position.x > bs[4].getPosition().x&&position.x < bs[4].getPosition().x + b[4].getSize().x
				&& position.y > bs[4].getPosition().y&&position.y < bs[4].getPosition().y + b[4].getSize().y)
			{
				if (act[4])
				{
					act[4] = false;
					data.floor = 0;
					data.game_time.restart();
					data.cool_time[4].restart();
					data.game_score = 0;
					return FIVE_INIT;
				}
				return UNFINISHED;
			}
		}
	}

	window.draw(bs[0]);
	window.draw(bs[1]);
	window.draw(bs[2]);
	window.draw(bs[3]);
	window.draw(bs[4]);

	window.draw(name[0]);
	window.draw(name[1]);
	window.draw(name[2]);
	window.draw(name[3]);
	window.draw(name[4]);

	if (frame[0])	window.draw(frames[0]);
	if (frame[1])	window.draw(frames[1]);
	if (frame[2])	window.draw(frames[2]);
	if (frame[3])	window.draw(frames[3]);
	if (frame[4])	window.draw(frames[4]);

	window.draw(statuss);
	window.draw(bags);
	window.draw(gems);
	window.draw(magics);
	window.draw(options);

	if (warning[1])	
	{
		window.draw(cooltime[1]); window.draw(_cooltime[1]);
	}
	if (warning[2])
	{
		window.draw(cooltime[2]); window.draw(_cooltime[2]);
	}
	if (warning[3])
	{
		window.draw(cooltime[3]); window.draw(_cooltime[3]);
	}
	if (warning[4])
	{
		window.draw(cooltime[4]); window.draw(_cooltime[4]);
	}

	if (act[0])	window.draw(as[0]);
	if (act[1])	window.draw(as[1]);
	if (act[2])	window.draw(as[2]);
	if (act[3])	window.draw(as[3]);
	if (act[4])	window.draw(as[4]);

	return MENU;
}

int menu(sf::RenderWindow &window)
{
	int scene = MENU;
	static bool is_init = false;
	if (!is_init)	{ menu_init(); is_init = true; }

	_cooltime[1].setString(std::to_string((int)(150 - data.cool_time_down - data.cool_time[1].getElapsedTime().asSeconds())));
	_cooltime[2].setString(std::to_string((int)(300 - data.cool_time_down - data.cool_time[2].getElapsedTime().asSeconds())));
	if (data.moneyget < 20000)
	{
		cooltime[3].setString(L"未解锁");
		cooltime[3].setPosition(266, 350);
		_cooltime[3].setString("");
	}
	else
	{
		cooltime[3].setString(L"冷却时间：");
		cooltime[3].setPosition(242, 350);
		_cooltime[3].setString(std::to_string((int)(300 - data.cool_time_down - data.cool_time[3].getElapsedTime().asSeconds())));
	}
	if (data.moneyget < 50000)
	{
		cooltime[4].setString(L"未解锁");
		cooltime[4].setPosition(490, 350);
		_cooltime[4].setString("");
	}
	else
	{
		cooltime[4].setString(L"冷却时间：");
		cooltime[4].setPosition(466, 350);
		_cooltime[4].setString(std::to_string((int)(300 - data.cool_time_down - data.cool_time[4].getElapsedTime().asSeconds())));
	}

	window.clear();
	window.draw(backgrounds);
	scene = button(window);
	window.display();
	return scene;
}