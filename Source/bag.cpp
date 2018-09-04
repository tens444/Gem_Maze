#pragma once
#include <iostream>
#include "data.h"
#include "stdafx.h"

extern Data data;

extern sf::Sound itemups;
extern sf::Sound actions;

std::vector<Visible_Item*> b;
std::vector<Visible_Item*>::iterator vit;

sf::Texture bagbackground;
sf::Sprite bagbackgrounds;
sf::Texture bagframe[16];
sf::Sprite bagframes[16];
sf::Texture bagframe_50[16];
sf::Sprite bagframes_50[16];
sf::Texture money;
sf::Sprite moneys;
sf::Text money_text;
sf::Text number[16];
sf::Text item_name[16];
sf::Font font;

extern sf::Font msgfont;
sf::Text compoundmsg;

bool bag_init()
{
	msgfont.loadFromFile("font/msyhbd.ttf");
	compoundmsg.setCharacterSize(15);
	compoundmsg.setPosition(210, 30);
	compoundmsg.setFont(msgfont);
	compoundmsg.setColor(sf::Color::Black);
	compoundmsg.setString(L"点击一阶宝石可合成二阶宝石，点击紫晶可分解成随机宝石");

	money.loadFromFile("images/bag/money.png");
	moneys.setTexture(money);
	moneys.setPosition(620, 400);
	money_text.setFont(font);
	money_text.setCharacterSize(15);
	money_text.setColor(sf::Color::Black);
	money_text.setString(std::to_string(data.money));
	money_text.setPosition(680, 415);
	
	bagbackground.loadFromFile("images/bag/bag.png");
	bagbackgrounds.setTexture(bagbackground);

	for (int i = 1; i <= 15; i++)
	{
		bagframe[i].loadFromFile("images/bag/bag_frame.png");
		bagframes[i].setTexture(bagframe[i]);
		if (i % 5 == 0)		bagframes[i].setPosition(100 + 5 * 100, (i / 5) * 100);
		else    bagframes[i].setPosition(100 + (i % 5) * 100, (i / 5 + 1) * 100);
	}

	for (int i = 1; i <= 15; i++)
	{
		bagframe_50[i].loadFromFile("images/bag/frame_50.png");
		bagframes_50[i].setTexture(bagframe_50[i]);
		if (i % 5 == 0)		bagframes_50[i].setPosition(100 + 5 * 100, (i / 5) * 100);
		else    bagframes_50[i].setPosition(100 + (i % 5) * 100, (i / 5 + 1) * 100);
	}

	font.loadFromFile("font/msyh.ttf");

	for (int i = 1; i <= 15; i++)
	{
		number[i].setFont(font);
		number[i].setCharacterSize(15);
		number[i].setColor(sf::Color::Black);
		item_name[i].setFont(font);
		item_name[i].setCharacterSize(12);
		item_name[i].setColor(sf::Color::Black);
		if (i % 5 == 0)		
		{
			number[i].setPosition(100 + 5 * 100 + 5, (i / 5) * 100 + 30);
			item_name[i].setPosition(80 + 5 * 100 + 20, (i / 5) * 100 + 60);
		}
		else   
		{
			number[i].setPosition(100 + (i % 5) * 100 + 5, (i / 5 + 1) * 100 + 30);
			item_name[i].setPosition(80 + (i % 5) * 100 + 20, (i / 5 + 1) * 100 + 60);
		}
	}

	std::vector<Item*>::iterator it;
	b.clear();
	int count = 0;
	for (it = data.items.begin(); it != data.items.end(); it++)
	{
		count++;
		Gem *g = new Gem((*it)->id,(*it)->num);
		if (count % 5 == 0)
			g->SetPositon(13, count / 5 * 2 + 1);
		else
			g->SetPositon(count % 5 * 2 + 3, count / 5 * 2 + 3);
		b.push_back(g);

		number[count].setString(std::to_string(g->num));
		switch ((*it)->id)
		{
		case 11: item_name[count].setString(L"一阶琥珀"); break;
		case 21: item_name[count].setString(L"一阶钻石"); break;
		case 31: item_name[count].setString(L"一阶翡翠"); break;
		case 41: item_name[count].setString(L"一阶水晶"); break;
		case 51: item_name[count].setString(L"一阶珊瑚"); break;
		case 12: item_name[count].setString(L"二阶琥珀"); break;
		case 22: item_name[count].setString(L"二阶钻石"); break;
		case 32: item_name[count].setString(L"二阶翡翠"); break;
		case 42: item_name[count].setString(L"二阶水晶"); break;
		case 52: item_name[count].setString(L"二阶珊瑚"); break;
		case 6: item_name[count].setString(L"   紫晶"); break;
		case 7: item_name[count].setString(L"   彩玉"); break;
		}
	}

	std::cout << b.size();
	return true;
}

int bag(sf::RenderWindow &window, bool init = false)
{
	if (!init) { bag_init(); }

	static bool chosen[16] = { 0 };

	sf::Texture back;
	back.setSmooth(true);
	static sf::Color color = sf::Color::Black;
	back.loadFromFile("images/back.png");
	sf::Sprite backs(back);
	backs.setPosition(735, 5);
	backs.setColor(color);

	static bool number_show[16] = { 0 };

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

			for (int i = 1; i <= 15; i++)
			{
				if (position.x > bagframes[i].getPosition().x&&position.x < bagframes[i].getPosition().x + bagframe[i].getSize().x
					&& position.y > bagframes[i].getPosition().y&&position.y < bagframes[i].getPosition().y + bagframe[i].getSize().y)
				{
					if (!chosen[i])
					{
						chosen[i] = true;
						if (i <= b.size())
						{
							number_show[i] = true;
							if(data.is_sound)	actions.play();
						}
					}
				}
				else
				{
					number_show[i] = false;
					chosen[i] = false;
				}
			}
		}

		if (event.type == sf::Event::EventType::MouseButtonReleased)
		{
			if (position.x > backs.getPosition().x&&position.x < backs.getPosition().x + back.getSize().x
				&& position.y > backs.getPosition().y&&position.y < backs.getPosition().y + back.getSize().y)
				return MENU;
			for (int i = 1; i <= 15; i++)
			{
				if (position.x > bagframes[i].getPosition().x&&position.x < bagframes[i].getPosition().x + bagframe[i].getSize().x
					&& position.y > bagframes[i].getPosition().y&&position.y < bagframes[i].getPosition().y + bagframe[i].getSize().y)
				{
					if (i <= b.size())
					{
						if (data.Compound(b[i - 1]->id))
						{
							if (data.is_sound)	itemups.play();
							return BAG_INIT;
						}
					}
				}
			}
		}
	}

	window.clear();
	window.draw(bagbackgrounds);
	window.draw(backs);

	for (vit = b.begin(); vit != b.end(); vit++)
	{
		(*vit)->Draw(window);
	}

	for (int i = 1; i <= 15; i++)
	{
		window.draw(bagframes[i]);
		if (chosen[i])
			window.draw(bagframes_50[i]);
		if (number_show[i])
		{
			window.draw(number[i]);
			window.draw(item_name[i]);
		}
	}

	window.draw(moneys);
	window.draw(money_text);
	window.draw(compoundmsg);
	window.display();
	return BAG;
}