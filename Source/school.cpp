#pragma once
#include <iostream>
#include "data.h"
#include "stdafx.h"

sf::Texture skill_gold;
sf::Texture skill_gem;
sf::Sprite skill_golds;
sf::Sprite skill_gems;

extern sf::Texture money;
extern sf::Sprite moneys;
extern sf::Text money_text;
extern sf::Font font;
sf::Text schoolmsg;

sf::Text cost;
sf::Text _cost;

sf::Texture skill_up[2][2];
sf::Sprite skill_ups[2][2];

sf::Texture schoolback;
sf::Sprite schoolbacks;

extern std::map<int, int> Cost;
extern Data data;

extern sf::Sound skillups;
extern sf::Sound errors;

bool school_init()
{
	font.loadFromFile("font/msyh.ttf");
	money.loadFromFile("images/bag/money.png");
	moneys.setTexture(money);
	moneys.setPosition(620, 400);
	money_text.setFont(font);
	money_text.setCharacterSize(15);
	money_text.setColor(sf::Color::Black);
	money_text.setString(std::to_string(data.money));
	money_text.setPosition(680, 415);

	schoolmsg.setFont(font);
	schoolmsg.setPosition(100, 50);
	schoolmsg.setCharacterSize(15);
	schoolmsg.setColor(sf::Color::Black);
	schoolmsg.setString(L"宝石路线：升级一次性奖励紫晶；  炼金路线：迷宫掉落加时道具。  注意：两者只可研习一种。");


	schoolback.loadFromFile("images/school/school.png");
	schoolbacks.setTexture(schoolback);

	skill_gem.loadFromFile("images/school/gem" + std::to_string(data.skill_gem) + ".png");
	skill_gems.setTexture(skill_gem);
	skill_gems.setPosition(218, 100);

	skill_gold.loadFromFile("images/school/gold" + std::to_string(data.skill_gold) + ".png");
	skill_golds.setTexture(skill_gold);
	skill_golds.setPosition(500, 100);

	skill_up[0][0].loadFromFile("images/school/study0.png");
	skill_up[1][0].loadFromFile("images/school/study0.png");
	skill_up[0][1].loadFromFile("images/school/study2.png");
	skill_up[1][1].loadFromFile("images/school/study2.png");
	skill_ups[0][0].setTexture(skill_up[0][0]);
	skill_ups[1][0].setTexture(skill_up[1][0]);
	skill_ups[0][1].setTexture(skill_up[0][1]);
	skill_ups[1][1].setTexture(skill_up[1][1]);
	skill_ups[0][0].setPosition(230, 280);
	skill_ups[0][1].setPosition(230, 280);
	skill_ups[1][0].setPosition(512, 280);
	skill_ups[1][1].setPosition(512, 280);

	return true;
}

int school(sf::RenderWindow &window, bool init)
{
	if (!init)	school_init();
	int scene = SCHOOL;

	sf::Texture back;
	back.setSmooth(true);
	static sf::Color color = sf::Color::Black;
	back.loadFromFile("images/back.png");
	sf::Sprite backs(back);
	backs.setPosition(735, 5);
	backs.setColor(color);

	static bool msgshow[2] = { 0 };
	sf::Text costmsg[2];
	costmsg[0].setFont(font);
	costmsg[0].setPosition(230, 250);
	costmsg[0].setCharacterSize(15);
	costmsg[0].setColor(sf::Color::Black);
	costmsg[1].setFont(font);
	costmsg[1].setPosition(512, 250);
	costmsg[1].setCharacterSize(15);
	costmsg[1].setColor(sf::Color::Black);

	static bool act[2] = { 0 };

	sf::Event event;
	sf::Vector2<int> position;
	position = sf::Mouse::getPosition(window);
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::EventType::Closed)
			window.close();
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
			window.close();
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::BackSpace))
			scene = MENU;

		if (event.type == sf::Event::MouseMoved)
		{
			if (position.x > backs.getPosition().x&&position.x < backs.getPosition().x + back.getSize().x
				&& position.y > backs.getPosition().y&&position.y < backs.getPosition().y + back.getSize().y)
				color = sf::Color::White;
			else
				color = sf::Color::Black;

			if (position.x > skill_ups[0][0].getPosition().x&&position.x < skill_ups[0][0].getPosition().x + skill_up[0][0].getSize().x
				&& position.y > skill_ups[0][0].getPosition().y&&position.y < skill_ups[0][0].getPosition().y + skill_up[0][0].getSize().y
				&& data.skill_gold == 0 && data.skill_gem != 7)
			{
				msgshow[0] = true;
				act[0] = true;
			}
			else
			{
				msgshow[0] = false;
				act[0] = false;
			}

			if (position.x > skill_ups[1][0].getPosition().x&&position.x < skill_ups[1][0].getPosition().x + skill_up[1][0].getSize().x
				&& position.y > skill_ups[1][0].getPosition().y&&position.y < skill_ups[1][0].getPosition().y + skill_up[1][0].getSize().y
				&& data.skill_gem == 0 && data.skill_gold != 7)
			{
				msgshow[1] = true;
				act[1] = true;
			}
			else
			{
				msgshow[1] = false;
				act[1] = false;
			}
		}

		if (event.type == sf::Event::EventType::MouseButtonReleased)
		{
			if (position.x > backs.getPosition().x&&position.x < backs.getPosition().x + back.getSize().x
				&& position.y > backs.getPosition().y&&position.y < backs.getPosition().y + back.getSize().y)
				return MENU;
			if (position.x > skill_ups[0][0].getPosition().x&&position.x < skill_ups[0][0].getPosition().x + skill_up[0][0].getSize().x
				&& position.y > skill_ups[0][0].getPosition().y&&position.y < skill_ups[0][0].getPosition().y + skill_up[0][0].getSize().y
				&& data.skill_gold == 0)
			{
				if (data.SkillGemUp())
				{
					if (data.is_sound)
						skillups.play();
					scene = SCHOOL_INIT;
				}
				else
				{
					if (data.is_sound)
						errors.play();
				}
			}

			if (position.x > skill_ups[1][0].getPosition().x&&position.x < skill_ups[1][0].getPosition().x + skill_up[1][0].getSize().x
				&& position.y > skill_ups[1][0].getPosition().y&&position.y < skill_ups[1][0].getPosition().y + skill_up[1][0].getSize().y
				&& data.skill_gem == 0)
			{
				if (data.SkillGoldUp())
				{
					if (data.is_sound)
						skillups.play();
					scene = SCHOOL_INIT;
				}
				else
				{
					if (data.is_sound)
						errors.play();
				}
			}
		}
	}

	window.clear();
	window.draw(schoolbacks);
	window.draw(backs);
	window.draw(skill_gems);
	window.draw(skill_golds);
	if (data.skill_gold == 0 && data.skill_gem != 7)
	{
		if (act[0])	window.draw(skill_ups[0][1]);
		else window.draw(skill_ups[0][0]);
	}
	if (data.skill_gem == 0 && data.skill_gold != 7)
	{
		if (act[1])	window.draw(skill_ups[1][1]);
		else window.draw(skill_ups[1][0]);
	}
	if (msgshow[0] && data.skill_gem != 7)
	{
		if (data.money < Cost[data.skill_gem])	costmsg[0].setColor(sf::Color::Red);
		else    costmsg[0].setColor(sf::Color::Green);
		costmsg[0].setString(std::to_string(Cost[data.skill_gem]) + "  G");
		window.draw(costmsg[0]);
	}
	if (msgshow[1] && data.skill_gold != 7)
	{
		if (data.money < Cost[data.skill_gold])	costmsg[1].setColor(sf::Color::Red);
		else    costmsg[1].setColor(sf::Color::Green);
		costmsg[1].setString(std::to_string(Cost[data.skill_gold]) + "  G");
		window.draw(costmsg[1]);
	}

	window.draw(moneys);
	window.draw(money_text);
	window.draw(schoolmsg);
	window.display();
	return scene;
}