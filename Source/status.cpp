#pragma once
#include "data.h"
#include "Role.h"
#include "stdafx.h"

extern Data data;

extern sf::Sound actions;

Role statusrole;

sf::Texture statusbackground;
sf::Sprite statusbackgrounds;
sf::Texture statusframe;
sf::Sprite statusframes;
sf::Texture ac[6];
sf::Sprite acs[6];
sf::Font textfont;
sf::Text text0;
sf::Text text1;

bool status_init()
{
	if (data.roletype)    statusrole.Update(data.roletype);
	statusrole.SetPosition(14, 5);

	statusbackground.loadFromFile("images/status.png");
	statusbackgrounds.setTexture(statusbackground);
	statusframe.loadFromFile("images/status/frame.png");
	statusframes.setTexture(statusframe);
	statusframes.setPosition(30, 70);

	textfont.loadFromFile("font/msyhbd.ttf");
	text0.setFont(textfont);
	text0.setCharacterSize(18);
	text0.setPosition(80, 160);
	text0.setString(L"ÿһö���·�Ϊ������ͭ����Ʒ�ʣ�ͨ����ͬ����Ϸ�ɾ���������\n\n�ﵽÿ���ȼ����ܹ������Ӧ�ӳɣ���껬�������¼��ɲ鿴��\n\n����������ʱ���ܹ������µ���������ͨ�����������������\n");

	textfont.loadFromFile("font/msyhbd.ttf");
	text1.setFont(textfont);
	text1.setCharacterSize(15);
	text1.setPosition(645, 265);
	text1.setColor(sf::Color::Green);
	text1.setString(L"��ǰ��ɫ");

	data.UpdateAc();

	for (int i = 0; i < 6; i++)
	{
		switch (data.ac[i])
		{
		case 0:ac[i].loadFromFile("images/status/medalempty.png"); break;
		case 1:ac[i].loadFromFile("images/status/medal" + std::to_string(i + 1) + "1.png"); break;
		case 2:ac[i].loadFromFile("images/status/medal" + std::to_string(i + 1) + "2.png"); break;
		case 3:ac[i].loadFromFile("images/status/medal" + std::to_string(i + 1) + "3.png"); break;
		}
		acs[i].setTexture(ac[i]);
		acs[i].setPosition(30 + i * 130, 330);
	}

	return true;
}

int status(sf::RenderWindow &window, bool init = false)
{
	if (!init)	status_init();

	sf::Texture back;
	back.setSmooth(true);
	static sf::Color color = sf::Color::Black;
	back.loadFromFile("images/back.png");
	sf::Sprite backs(back);
	backs.setPosition(735, 5);
	backs.setColor(color);

	sf::Font font;
	font.loadFromFile("font/msyhbd.ttf");
	sf::Text time;
	time.setFont(font);
	time.setCharacterSize(25);
	time.setString(L"��Ϸʱ��");
	time.setPosition(285, 50);
	time.setColor(sf::Color::White);

	int sec = (int)data.clock.getElapsedTime().asSeconds();
	sf::Text _time;
	_time.setFont(font);
	_time.setCharacterSize(25);
	_time.setString(std::to_string(sec / 3600) + " : " + std::to_string(sec % 3600 / 60) + " : " + std::to_string(sec % 60));
	_time.setPosition(450, 50);
	_time.setColor(sf::Color::White);

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

			if (position.x > acs[0].getPosition().x&&position.x < acs[0].getPosition().x + ac[0].getSize().x
				&& position.y > acs[0].getPosition().y&&position.y < acs[0].getPosition().y + ac[0].getSize().y)
			{
				text0.setString(L"ͭ����Ϸʱ���ﵽ10���ӡ� ��> ��ͼ��ȴʱ������60�롣\n\n������Ϸʱ���ﵽ30���ӡ� ��> ��ͼ��ȴʱ������150�롣\n\n����Ϸʱ���ﵽ1Сʱ�� ��> ��ͼ��ȴʱ��������\n");
				statusrole.Update(1);
				text1.setPosition(655, 265);
				text1.setColor(sf::Color::Red);
				if (data.roletype == 1){
					text1.setPosition(645, 265);
					text1.setColor(sf::Color::Green);
					text1.setString(L"��ǰ��ɫ");
				}
				else if (data.ac[0] == 3)	text1.setString(L"δ����");
				else text1.setString(L"δ���");
			}
			else if (position.x > acs[1].getPosition().x&&position.x < acs[1].getPosition().x + ac[1].getSize().x
				&& position.y > acs[1].getPosition().y&&position.y < acs[1].getPosition().y + ac[1].getSize().y)
			{
				text0.setString(L"ͭ����ù�10000��ҡ� ��> ����ħ��ѧԺ��\n\n������ù�50000��ҡ� ��> ���������������ͼ��\n\n�𣺻�ù�200000��ҡ� ��> ���������������ͼ��\n");
				statusrole.Update(2);
				text1.setPosition(655, 265);
				text1.setColor(sf::Color::Red);
				if (data.roletype == 2){
					text1.setPosition(645, 265);
					text1.setColor(sf::Color::Green);
					text1.setString(L"��ǰ��ɫ");
				}
				else if (data.ac[1] == 3)	text1.setString(L"δ����");
				else text1.setString(L"δ���");
			}
			else if (position.x > acs[2].getPosition().x&&position.x < acs[2].getPosition().x + ac[2].getSize().x
				&& position.y > acs[2].getPosition().y&&position.y < acs[2].getPosition().y + ac[2].getSize().y)
			{
				text0.setString(L"ͭ����ù�100�ű�ʯ�� ��> ��ʯ��������20%\n\n������ù�500�ű�ʯ�� ��> ��ʯ��������50%\n\n�𣺻�ù�2000�ű�ʯ�� ��> ��ʯ��������100%\n");
				statusrole.Update(3);
				text1.setPosition(655, 265);
				text1.setColor(sf::Color::Red);
				if (data.roletype == 3){
					text1.setPosition(645, 265);
					text1.setColor(sf::Color::Green);
					text1.setString(L"��ǰ��ɫ");
				}
				else if (data.ac[2] == 3)	text1.setString(L"δ����");
				else text1.setString(L"δ���");
			}
			else if (position.x > acs[3].getPosition().x&&position.x < acs[3].getPosition().x + ac[3].getSize().x
				&& position.y > acs[3].getPosition().y&&position.y < acs[3].getPosition().y + ac[3].getSize().y)
			{
				text0.setString(L"ͭ��ӵ��5�ִ����Ʒ�� ��> ͼֽ��������20%\n\n����ӵ��15�ִ����Ʒ�� ��> ͼֽ��������50%\n\n��ӵ��35�ִ����Ʒ�� ��> ͼֽ��������100%\n");
				statusrole.Update(4);
				text1.setPosition(655, 265);
				text1.setColor(sf::Color::Red);
				if (data.roletype == 4){
					text1.setPosition(645, 265);
					text1.setColor(sf::Color::Green);
					text1.setString(L"��ǰ��ɫ");
				}
				else if (data.ac[3] == 3)	text1.setString(L"δ����");
				else text1.setString(L"δ���");
			}
			else if (position.x > acs[4].getPosition().x&&position.x < acs[4].getPosition().x + ac[4].getSize().x
				&& position.y > acs[4].getPosition().y&&position.y < acs[4].getPosition().y + ac[4].getSize().y)
			{
				text0.setString(L"ͭ��ӵ��2�Ų�ʯ�� ��> �ϰ������10%\n\n����ӵ��5�Ų�ʯ�� ��> �ϰ������30%\n\n��ӵ��10�Ų�ʯ�� ��> �ϰ������50%\n");
				statusrole.Update(5);
				text1.setPosition(655, 265);
				text1.setColor(sf::Color::Red);
				if (data.roletype == 5)	{
					text1.setPosition(645, 265);
					text1.setColor(sf::Color::Green);
					text1.setString(L"��ǰ��ɫ");
				}
				else if (data.ac[4] == 3)	text1.setString(L"δ����");
				else text1.setString(L"δ���");
			}
			else if (position.x > acs[5].getPosition().x&&position.x < acs[5].getPosition().x + ac[5].getSize().x
				&& position.y > acs[5].getPosition().y&&position.y < acs[5].getPosition().y + ac[5].getSize().y)
			{
				text0.setString(L"��ʾר��\n");
				statusrole.Update(6);
				text1.setPosition(655, 265);
				text1.setColor(sf::Color::Red);
				if (data.roletype == 6)	{
					text1.setPosition(645, 265);
					text1.setColor(sf::Color::Green);
					text1.setString(L"��ǰ��ɫ");
				}
				else if (data.ac[5] == 3)	text1.setString(L"δ����");
				else text1.setString(L"δ���");
			}
			else
			{
				text0.setString(L"ÿһö���·�Ϊ������ͭ����Ʒ�ʣ�ͨ����ͬ����Ϸ�ɾ���������\n\n�ﵽÿ���ȼ����ܹ������Ӧ�ӳɣ���껬�������¼��ɲ鿴��\n\n����������ʱ���ܹ������µ���������ͨ�����������������\n");
				statusrole.Update(data.roletype);
				text1.setPosition(645, 265);
				text1.setColor(sf::Color::Green);
				text1.setString(L"��ǰ��ɫ");
			}
		}

		if (event.type == sf::Event::EventType::MouseButtonPressed)
		{
			if (position.x > acs[0].getPosition().x&&position.x < acs[0].getPosition().x + ac[0].getSize().x
				&& position.y > acs[0].getPosition().y&&position.y < acs[0].getPosition().y + ac[0].getSize().y)
			{
				if (data.ac[0] == 3)
				{
					data.roletype = 1;
					text1.setPosition(645, 265);
					text1.setColor(sf::Color::Green);
					text1.setString(L"��ǰ��ɫ");
				}
			}
			else if (position.x > acs[1].getPosition().x&&position.x < acs[1].getPosition().x + ac[1].getSize().x
				&& position.y > acs[1].getPosition().y&&position.y < acs[1].getPosition().y + ac[1].getSize().y)
			{
				if (data.ac[1] == 3)
				{
					data.roletype = 2;
					text1.setPosition(645, 265);
					text1.setColor(sf::Color::Green);
					text1.setString(L"��ǰ��ɫ");
				}
			}
			else if (position.x > acs[2].getPosition().x&&position.x < acs[2].getPosition().x + ac[2].getSize().x
				&& position.y > acs[2].getPosition().y&&position.y < acs[2].getPosition().y + ac[2].getSize().y)
			{
				if (data.ac[2] == 3)
				{
					data.roletype = 3;
					text1.setPosition(645, 265);
					text1.setColor(sf::Color::Green);
					text1.setString(L"��ǰ��ɫ");
				}
			}
			else if (position.x > acs[3].getPosition().x&&position.x < acs[3].getPosition().x + ac[3].getSize().x
				&& position.y > acs[3].getPosition().y&&position.y < acs[3].getPosition().y + ac[3].getSize().y)
			{
				if (data.ac[3] == 3)
				{
					data.roletype = 4;
					text1.setPosition(645, 265);
					text1.setColor(sf::Color::Green);
					text1.setString(L"��ǰ��ɫ");
				}
			}
			else if (position.x > acs[4].getPosition().x&&position.x < acs[4].getPosition().x + ac[4].getSize().x
				&& position.y > acs[4].getPosition().y&&position.y < acs[4].getPosition().y + ac[4].getSize().y)
			{
				if (data.ac[4] == 3)
				{
					data.roletype = 5;
					text1.setPosition(645, 265);
					text1.setColor(sf::Color::Green);
					text1.setString(L"��ǰ��ɫ");
				}
			}
			else if (position.x > acs[5].getPosition().x&&position.x < acs[5].getPosition().x + ac[5].getSize().x
				&& position.y > acs[5].getPosition().y&&position.y < acs[5].getPosition().y + ac[5].getSize().y)
			{
				if (data.ac[5] == 3)
				{
					data.roletype = 6;
					text1.setPosition(645, 265);
					text1.setColor(sf::Color::Green);
					text1.setString(L"��ǰ��ɫ");
				}
			}
		}

		if (event.type == sf::Event::EventType::MouseButtonReleased)
		{
			if (position.x > backs.getPosition().x&&position.x < backs.getPosition().x + back.getSize().x
				&& position.y > backs.getPosition().y&&position.y < backs.getPosition().y + back.getSize().y)
				return MENU;
		}
	}

	window.clear();
	window.draw(statusbackgrounds);
	window.draw(backs);
	window.draw(time);
	window.draw(_time);
	window.draw(statusframes);
	window.draw(text0);
	window.draw(text1);
	for (int i = 0; i < 6; i++)	window.draw(acs[i]);
	statusrole.Draw(window);
	window.display();
	return STATUS;
}