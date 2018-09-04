#pragma once
#include "data.h"
#include "stdafx.h"
#include "iostream"

extern Data data;

extern sf::Sound pageruns;
extern sf::Sound itemups;
extern sf::Sound errors;

sf::Texture workshop_background;
sf::Sprite workshop_backgrounds;
sf::Texture workshop_frame[4];
sf::Sprite workshop_frames[4];
sf::Texture upbutton[4];
sf::Sprite upbuttons[4];
sf::Texture formula[4];
sf::Sprite formulas[4];


int count;
int curpage;
int maxpage;

extern sf::Font msgfont;
extern sf::Text msg;
extern sf::Color color;

bool workshop_init()
{
	color.r = color.g = color.b = 0;
	msgfont.loadFromFile("font/msyhbd.ttf");
	msg.setCharacterSize(20);
	msg.setPosition(350, 10);
	msg.setFont(msgfont);

	workshop_background.loadFromFile("images/workshop/workshop.png");
	workshop_backgrounds.setTexture(workshop_background);

	workshop_frame[0].loadFromFile("images/workshop/frame.png");
	workshop_frame[1].loadFromFile("images/workshop/frame.png");
	workshop_frame[2].loadFromFile("images/workshop/frame.png");
	workshop_frame[3].loadFromFile("images/workshop/frame.png");
	workshop_frames[0].setTexture(workshop_frame[0]);
	workshop_frames[1].setTexture(workshop_frame[1]);
	workshop_frames[2].setTexture(workshop_frame[2]);
	workshop_frames[3].setTexture(workshop_frame[3]);
	workshop_frames[0].setPosition(15, 50);
	workshop_frames[1].setPosition(215, 50);
	workshop_frames[2].setPosition(415, 50);
	workshop_frames[3].setPosition(615, 50);

	upbutton[0].loadFromFile("images/workshop/_up.png");
	upbutton[1].loadFromFile("images/workshop/_up.png");
	upbutton[2].loadFromFile("images/workshop/_up.png");
	upbutton[3].loadFromFile("images/workshop/_up.png");
	upbuttons[0].setTexture(upbutton[0]);
	upbuttons[1].setTexture(upbutton[1]);
	upbuttons[2].setTexture(upbutton[2]);
	upbuttons[3].setTexture(upbutton[3]);
	upbuttons[0].setPosition(115, 335);
	upbuttons[1].setPosition(315, 335);
	upbuttons[2].setPosition(515, 335);
	upbuttons[3].setPosition(715, 335);

	formula[0].loadFromFile("images/gempack/formula.png");
	formula[1].loadFromFile("images/gempack/formula.png");
	formula[2].loadFromFile("images/gempack/formula.png");
	formula[3].loadFromFile("images/gempack/formula.png");
	formulas[0].setTexture(formula[0]);
	formulas[1].setTexture(formula[1]);
	formulas[2].setTexture(formula[2]);
	formulas[3].setTexture(formula[3]);
	formulas[0].setPosition(40, 340);
	formulas[1].setPosition(240, 340);
	formulas[2].setPosition(440, 340);
	formulas[3].setPosition(640, 340);

	count = data.gempacks.size();
	curpage = 1;
	maxpage = (count - 1) / 4 + 1;

	return true;
}

void workshop_draw(sf::RenderWindow &window)
{
	window.clear();
	window.draw(workshop_backgrounds);
	if (curpage < maxpage)
	{
		for (int i = 0; i < 4; i++)
		{
			window.draw(workshop_frames[i]);
			window.draw(upbuttons[i]);
			window.draw(formulas[i]);
		}
	}
	else
	{
		for (int i = 0; i < count - 4 * (curpage - 1); i++)
		{
			window.draw(workshop_frames[i]);
			window.draw(upbuttons[i]);
			window.draw(formulas[i]);
		}
	}

	for (int i = (curpage - 1) * 4 ; i < count && i < curpage * 4; i++)
	{
		data.gempacks[i]->SetPosition(workshop_frames[i - (curpage - 1) * 4].getPosition().x, 60);
		data.gempacks[i]->Draw(window);
	}

	static int change = 5;
	if (color.b != 0)
	{
		color.b -= change;
		color.r -= change;
		color.g -= change;
		msg.setColor(color);
		window.draw(msg);
	}
}

int workshop(sf::RenderWindow &window, bool init = true)
{
	if (!init)    workshop_init();

	sf::Texture back;
	sf::Texture left;
	sf::Texture right;
	static sf::Color color_back = sf::Color::Black;
	static sf::Color color_left = sf::Color::Black;
	static sf::Color color_right = sf::Color::Black;
	back.loadFromFile("images/back.png");
	left.loadFromFile("images/left.png");
	right.loadFromFile("images/right.png");
	sf::Sprite backs(back);
	sf::Sprite lefts(left);
	sf::Sprite rights(right);
	backs.setPosition(735, 5);
	lefts.setPosition(300, 420);
	rights.setPosition(450, 420);
	backs.setColor(color_back);
	lefts.setColor(color_left);
	rights.setColor(color_right);

	sf::Font font;
	font.loadFromFile("font/msyhbd.ttf");
	sf::Text page;
	page.setPosition(370, 415);
	page.setFont(font);
	page.setCharacterSize(20);
	page.setColor(sf::Color::Black);
	page.setString(std::to_string(curpage) + " / " + std::to_string(maxpage));


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
				color_back = sf::Color::White;
			else
				color_back = sf::Color::Black;

			if (position.x > lefts.getPosition().x&&position.x < lefts.getPosition().x + left.getSize().x
				&& position.y > lefts.getPosition().y&&position.y < lefts.getPosition().y + left.getSize().y)
				color_left = sf::Color::White;
			else
				color_left = sf::Color::Black;

			if (position.x > rights.getPosition().x&&position.x < rights.getPosition().x + right.getSize().x
				&& position.y > rights.getPosition().y&&position.y < rights.getPosition().y + right.getSize().y)
				color_right = sf::Color::White;
			else
				color_right = sf::Color::Black;

			if (curpage < maxpage)
			{
				for (int i = 0; i < 4; i++)
				{
					if (position.x > upbuttons[i].getPosition().x&&position.x < upbuttons[i].getPosition().x + upbutton[i].getSize().x
						&& position.y > upbuttons[i].getPosition().y&&position.y < upbuttons[i].getPosition().y + upbutton[i].getSize().y)
					{
						upbutton[i].loadFromFile("images/workshop/up.png");
					}
					else
					{
						upbutton[i].loadFromFile("images/workshop/_up.png");
					}
				}
			}
			else
			{
				for (int i = 0; i < count - 4 * (curpage - 1); i++)
				{
					if (position.x > upbuttons[i].getPosition().x&&position.x < upbuttons[i].getPosition().x + upbutton[i].getSize().x
						&& position.y > upbuttons[i].getPosition().y&&position.y < upbuttons[i].getPosition().y + upbutton[i].getSize().y)
					{
						upbutton[i].loadFromFile("images/workshop/up.png");
					}
					else
					{
						upbutton[i].loadFromFile("images/workshop/_up.png");
					}
				}
			}
		}

		if (event.type == sf::Event::EventType::MouseButtonReleased)
		{
			if (position.x > backs.getPosition().x&&position.x < backs.getPosition().x + back.getSize().x
				&& position.y > backs.getPosition().y&&position.y < backs.getPosition().y + back.getSize().y)
				return MENU;

			if (position.x > rights.getPosition().x&&position.x < rights.getPosition().x + right.getSize().x
				&& position.y > rights.getPosition().y&&position.y < rights.getPosition().y + right.getSize().y)
			{
				if (curpage < maxpage)
				{
					curpage++;
					if (data.is_sound)	pageruns.play();
				}
			}

			if (position.x > lefts.getPosition().x&&position.x < lefts.getPosition().x + left.getSize().x
				&& position.y > lefts.getPosition().y&&position.y < lefts.getPosition().y + left.getSize().y)
			{
				if (curpage > 1)
				{
					curpage--;
					if (data.is_sound)	pageruns.play();
				}
			}

			if (curpage < maxpage)
			{
				for (int i = 0; i < 4; i++)
				{
					if (position.x > upbuttons[i].getPosition().x&&position.x < upbuttons[i].getPosition().x + upbutton[i].getSize().x
						&& position.y > upbuttons[i].getPosition().y&&position.y < upbuttons[i].getPosition().y + upbutton[i].getSize().y)
					{
						switch (data.gempacks[(curpage - 1) * 4 + i]->Up())
						{
						case -2:
							color.r = color.g = color.b = 255;
							msg.setString(L"打造失败！");
							if (data.is_sound)	errors.play(); break;
						case -1:
							color.r = color.g = color.b = 255;
							msg.setString(L"图纸不足！");
							if (data.is_sound)	errors.play(); break;
						case 0:
							color.r = color.g = color.b = 255;
							msg.setString(L"宝石不足！");
							if (data.is_sound)	errors.play(); break;
						case 1:
							color.r = color.g = color.b = 255;
							msg.setString(L"打造成功！");
							if (data.is_sound)	itemups.play(); break;
						case 2:
							color.r = color.g = color.b = 255;
							msg.setString(L"无需打造！");
							if (data.is_sound)	errors.play(); break;
						}
					}
				}
			}
			else
			{
				for (int i = 0; i < count - 4 * (curpage - 1); i++)
				{
					if (position.x > upbuttons[i].getPosition().x&&position.x < upbuttons[i].getPosition().x + upbutton[i].getSize().x
						&& position.y > upbuttons[i].getPosition().y&&position.y < upbuttons[i].getPosition().y + upbutton[i].getSize().y)
					{
						switch(data.gempacks[(curpage - 1) * 4 + i]->Up())
						{
						case -2:
							color.r = color.g = color.b = 255;
							msg.setString(L"打造失败！");
							if (data.is_sound)	errors.play(); break;
						case -1:
							color.r = color.g = color.b = 255;
							msg.setString(L"图纸不足！");
							if (data.is_sound)	errors.play(); break;
						case 0:
							color.r = color.g = color.b = 255;
							msg.setString(L"宝石不足！"); 
							if (data.is_sound)	errors.play(); break;
						case 1:
							color.r = color.g = color.b = 255;
							msg.setString(L"打造成功！"); 
							if (data.is_sound)	itemups.play(); break;
						case 2:
							color.r = color.g = color.b = 255;
							msg.setString(L"无需打造！"); 
							if (data.is_sound)	errors.play(); break;
						}
					}
				}
			}
		}
	}

	workshop_draw(window);
	window.draw(backs);
	window.draw(lefts);
	window.draw(rights);
	window.draw(page);
	window.display();
	return WORKSHOP;
}