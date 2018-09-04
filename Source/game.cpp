#pragma once
#include "stdafx.h"
#include "map.h"
#include "Role.h"
#include "Item.h"
#include "data.h"
#include <random>
#include <iostream>

std::vector<Visible_Item*> v;
std::vector<Visible_Item*>::iterator it;

extern std::map<int, std::string> ID;
extern Data data;

extern sf::Sound itemgets;

static Map map;
static Back back;
static Role role;

sf::Font msgfont;
sf::Text msg;
sf::Color color;

static int flag = 0;

void game_init(int _map)
{
	data.floor++;

	color.r = color.g = color.b = 0;
	msgfont.loadFromFile("font/msyhbd.ttf");
	msg.setCharacterSize(18);
	msg.setPosition(320, 20);
	msg.setFont(msgfont);

	if (data.roletype)
		role.Update(data.roletype);

	v.clear();
	role.SetPosition(1, 2);

	if (_map == FIVE)
	{
		if (data.game_score > 10000)
		{
			map.Create0();
			back.SetPositon(16, 9);
			v.clear();
			Gem *g = new Gem(7);
			v.push_back(g);
			g->SetPositon(8, 5);
			map.mapitem[8][5] = 7;
			return;
		}
		else
		{
			flag = 0;
			data.game_score = 0;
			map.Create0();
		}
		return;
	}

	if (_map == FOUR)
	{
		if (data.floor == 30)
		{
			map.Create0();
			back.SetPositon(16, 9);
			v.clear();
			Gem *g = new Gem(7);
			v.push_back(g);
			g->SetPositon(8, 5);
			map.mapitem[8][5] = 7;
			return;
		}
		map.Create4(data.floor, back);
	}
	else { back.SetPositon(16, 9); map.Create(data.floor); }

	int r_x, r_y;

	switch (_map)
	{
	case ONE:
		for (int i = 1; i <= 5 + (1+data.gem_p) * data.floor * 3; i++)
		{
			srand(data.clock.getElapsedTime().asMilliseconds() * i);
			int random = rand() % 10000;
			r_x = rand() % 16;
			r_y = rand() % 9;
			if (random < 2500)
			{
				if (map.mapitem[r_x][r_y] != 0)
					continue;
				Gem* g;
				if (random < 500)	g = new Gem(51);
				else if (random < 1000)	 g = new Gem(41);
				else if (random < 1500)	 g = new Gem(31);
				else if (random < 2000)	 g = new Gem(21);
				else	g = new Gem(11);
				v.push_back(g);
				g->SetPositon(r_x, r_y);
				map.mapitem[r_x][r_y] = g->id;
			}
		}
		break;
	case TWO:
		for (int i = 1; i <= 5 + (1 + data.gem_p) * data.floor * 3; i++)
		{
			srand(data.clock.getElapsedTime().asMilliseconds() * i);
			int random = rand() % 10000;
			r_x = rand() % 16;
			r_y = rand() % 9;
			if (random < 2500)
			{
				if (map.mapitem[r_x][r_y] != 0)
					continue;
				Gem* g;
				if (random < 500)	g = new Gem(52);
				else if (random < 1000)	 g = new Gem(42);
				else if (random < 1500)	 g = new Gem(32);
				else if (random < 2000)	 g = new Gem(22);
				else	g = new Gem(12);
				v.push_back(g);
				g->SetPositon(r_x, r_y);
				map.mapitem[r_x][r_y] = g->id;
			}
		}
		break;
	case THREE:
		for (int i = 1; i <= 5 + (1 + data.gem_p) * data.floor * 3; i++)
		{
			srand(data.clock.getElapsedTime().asMilliseconds() * i);
			int random = rand() % 10000;
			r_x = rand() % 16;
			r_y = rand() % 9;
			if (random < 500)
			{
				if (map.mapitem[r_x][r_y] != 0)
					continue;
				Gem* g;
				g = new Gem(6);
				v.push_back(g);
				g->SetPositon(r_x, r_y);
				map.mapitem[r_x][r_y] = g->id;
			}
		}
		break;
	}

	for (int i = 1; i <= data.skill_gold * 2 - data.floor; i++)
	{
		srand(data.clock.getElapsedTime().asMilliseconds() * i);
		int random = rand() % 10000;
		r_x = rand() % 16;
		r_y = rand() % 9;
		if (random < 1000)
		{
			if (map.mapitem[r_x][r_y] != 0)
				continue;
			Time *t;
			if (random < 200)	 t = new Time(1000000001);
			else if (random < 500)	 t = new Time(1000000002);
			else	 t = new Time(1000000003);
			v.push_back(t);
			t->SetPositon(r_x, r_y);
			map.mapitem[r_x][r_y] = t->id;
		}
	}

	for (int i = 1; i <= data.floor * 3; i++)
	{
		srand(data.clock.getElapsedTime().asMilliseconds() * i);
		int random = rand() % 10000;
		r_x = rand() % 16;
		r_y = rand() % 9;
		if (random < 1000)
		{
			if (map.mapitem[r_x][r_y] != 0)
				continue;
			Token *t;
			if (random < 50)	 t = new Token(10004);
			else if (random < 200)	 t = new Token(10003);
			else if (random < 500)	 t = new Token(10002);
			else	t = new Token(10001);
			v.push_back(t);
			t->SetPositon(r_x, r_y);
			map.mapitem[r_x][r_y] = t->id;
		}
	}

	srand(data.clock.getElapsedTime().asMilliseconds());
	int random = rand() % 10000;
	if (random < 5000 * (1 + data.pack_p))
	{
		r_x = rand() % 16;
		r_y = rand() % 9;
		if (map.mapitem[r_x][r_y] == 0)
		{
			Pack *p = new Pack;
			v.push_back(p);
			p->SetPositon(r_x, r_y);
			map.mapitem[r_x][r_y] = p->id;
		}
	}
}

void five(sf::RenderWindow &window)
{
	static sf::Clock flash;
	int sec = flash.getElapsedTime().asMilliseconds();
	static int d = 0;

	if (sec > 500)
	{
		d++;
		flash.restart();
		for (int i = 1; i <= 2; i++)
		{
			srand(data.clock.getElapsedTime().asMilliseconds() * i);
			int random = rand() % 10000;
			int r_x = rand() % 16;
			int r_y = rand() % 9;
			if (map.mapitem[r_x][r_y] != 0)
				continue;
			Gem* g;
			if (random < 3333)	g = new Gem(1000001);
			else if (random < 6666)	 g = new Gem(1000002);
			else	g = new Gem(1000003);
			v.push_back(g);
			g->SetPositon(r_x, r_y);
			map.mapitem[r_x][r_y] = g->id;
		}
	}
	if (d == 2)
	{
		d = 0;
		v.erase(v.begin() + rand() % v.size());
	}
}

void draw(sf::RenderWindow &window)
{
	map.Draw(window);

	back.Draw(window);

	for (it = v.begin(); it != v.end(); it++)
		(*it)->Draw(window);

	role.Draw(window);

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

int event(Role &role, Map &map)
{
	int x = role.GetPositionX();
	int y = role.GetPositionY();
	int id = map.mapitem[x][y];
	if (id != 0)
	{
		if (id == -1)    return 1;
		else if (id < 100)
		{
			Visible_Item* temp;
			for (it = v.begin(); it != v.end(); it++)
			{
				if ((*it)->GetPositionX() == role.GetPositionX() && (*it)->GetPositionY() == role.GetPositionY())
				{
					temp = *it;
					map.mapitem[role.GetPositionX()][role.GetPositionY()] = 0;
					data.AddItem(id,1);
					it = v.erase(it);
					delete temp;
					color.r = color.g = color.b = 255;
					switch (id)
					{
					case 11: msg.setString(L"获得 一阶琥珀 * 1"); break;
					case 21: msg.setString(L"获得 一阶翡翠 * 1"); break;
					case 31: msg.setString(L"获得 一阶钻石 * 1"); break;
					case 41: msg.setString(L"获得 一阶水晶 * 1"); break;
					case 51: msg.setString(L"获得 一阶珊瑚 * 1"); break;
					case 12: msg.setString(L"获得 二阶琥珀 * 1"); break;
					case 22: msg.setString(L"获得 二阶钻石 * 1"); break;
					case 32: msg.setString(L"获得 二阶翡翠 * 1"); break;
					case 42: msg.setString(L"获得 二阶水晶 * 1"); break;
					case 52: msg.setString(L"获得 二阶珊瑚 * 1"); break;
					case 6: msg.setString(L"获得 紫晶 * 1"); break;
					case 7: msg.setString(L"获得 彩玉 * 1"); return 2; break;
					}
					if (data.is_sound)	itemgets.play();
					break;
				}
			}
		}
		else if (id > 1000000000)
		{
			Visible_Item* temp;
			for (it = v.begin(); it != v.end(); it++)
			{
				if ((*it)->GetPositionX() == role.GetPositionX() && (*it)->GetPositionY() == role.GetPositionY())
				{
					temp = *it;
					map.mapitem[role.GetPositionX()][role.GetPositionY()] = 0;
					it = v.erase(it);
					delete temp;
					color.r = color.g = color.b = 255;
					switch (id)
					{
					case 1000000001:	data.extra_time += 5; msg.setString(L"迷宫时间 + 5s"); break;
					case 1000000002:	data.extra_time += 10; msg.setString(L"迷宫时间 + 10s"); break;
					case 1000000003:	data.extra_time += 15; msg.setString(L"迷宫时间 + 15s"); break;
					}
					if (data.is_sound)	itemgets.play();
					break;
				}
			}
		}
		else if (id > 1000000)
		{
			Visible_Item* temp;
			for (it = v.begin(); it != v.end(); it++)
			{
				if ((*it)->GetPositionX() == role.GetPositionX() && (*it)->GetPositionY() == role.GetPositionY())
				{
					temp = *it;
					map.mapitem[role.GetPositionX()][role.GetPositionY()] = 0;
					switch (id)
					{
					case 1000001: 	data.game_score += 50; msg.setString(L"积分 + 50"); break;
					case 1000002: 	data.game_score += 100; msg.setString(L"积分 + 100"); break;
					case 1000003: 	data.game_score += 200; msg.setString(L"积分 + 200"); break;
					}
					color.r = color.g = color.b = 255;
					it = v.erase(it);
					delete temp;
					if (data.is_sound)	itemgets.play();
					break;
				}
			}
		}
		else if (id > 10000)
		{
			Visible_Item* temp;
			for (it = v.begin(); it != v.end(); it++)
			{
				if ((*it)->GetPositionX() == role.GetPositionX() && (*it)->GetPositionY() == role.GetPositionY())
				{
					temp = *it;
					map.mapitem[role.GetPositionX()][role.GetPositionY()] = 0;
					switch (id)
					{
					case 10001: 	data.AddMoney(200); msg.setString(L"获得 金币 * 200"); break;
					case 10002: 	data.AddMoney(500); msg.setString(L"获得 金币 * 500"); break;
					case 10003: 	data.AddMoney(1000); msg.setString(L"获得 金币 * 1000"); break;
					case 10004: 	data.AddMoney(2000); msg.setString(L"获得 金币 * 2000"); break;
					}
					color.r = color.g = color.b = 255;
					it = v.erase(it);
					delete temp;
					if (data.is_sound) itemgets.play();
					break;
				}
			}
		}
		else
		{
			Visible_Item* temp;
			for (it = v.begin(); it != v.end(); it++)
			{
				if ((*it)->GetPositionX() == role.GetPositionX() && (*it)->GetPositionY() == role.GetPositionY())
				{
					temp = *it;
					map.mapitem[role.GetPositionX()][role.GetPositionY()] = 0;
					data.AddGemPack(rand() % 40 + 1, 1);
					msg.setString(L"获得 未知图纸 * 1");
					color.r = color.g = color.b = 255;
					it = v.erase(it);
					delete temp;
					if (data.is_sound)	itemgets.play();
					break;
				}
			}
		}
	}

	return 0;
}

int game(sf::RenderWindow &window, int _map, bool init = true)
{
	int scene = _map;

	if (!init)
		game_init(_map);

	if (_map == FIVE)
	{
		if (data.game_score > 10000)
		{
			if (flag == 0)
			{
				flag = 1;
				game_init(_map);
			}
		}
		else five(window);
	}

	sf::Font font;
	font.loadFromFile("font/msyhbd.ttf");
	sf::Text time;
	time.setFont(font);
	time.setCharacterSize(15);
	time.setString(L"剩余时间：");
	time.setPosition(650, 30);

	int sec = data.game_time.getElapsedTime().asSeconds();
	sf::Text _time;
	_time.setFont(font);
	_time.setCharacterSize(15);
	_time.setString(std::to_string(60 + data.extra_time - sec));
	if (sec - data.extra_time >= 60)	return MENU;
	if (60 + data.extra_time - sec < 10)
	{
		if (sec % 2 == 1)	{ time.setColor(sf::Color::Red); _time.setColor(sf::Color::Red); }
		else    { time.setColor(sf::Color::White); _time.setColor(sf::Color::White); }
	}
	_time.setPosition(730, 30);

	sf::Text floor;
	floor.setFont(font);
	floor.setCharacterSize(15);
	floor.setString(L"当前层数：");
	floor.setPosition(0, 30);

	sf::Text _floor;
	_floor.setFont(font);
	_floor.setCharacterSize(15);
	_floor.setString(std::to_string(data.floor));
	_floor.setPosition(80, 30);

	sf::Text textscore;
	textscore.setColor(sf::Color::Green);
	textscore.setFont(font);
	textscore.setCharacterSize(15);
	textscore.setString(L"当前积分：");
	textscore.setPosition(100, 30);

	sf::Text _score;
	_score.setColor(sf::Color::Green);
	_score.setFont(font);
	_score.setCharacterSize(15);
	_score.setString(std::to_string(data.game_score));
	_score.setPosition(180, 30);

	sf::Event e;
	while (window.pollEvent(e))
	{
		if (e.type == sf::Event::EventType::Closed)
			window.close();
		if ((e.type == sf::Event::KeyPressed))
		{
			switch (e.key.code)
			{
			case sf::Keyboard::BackSpace:return MENU; break;
			case sf::Keyboard::Enter: return _map - 1; break;
			case sf::Keyboard::Escape:window.close(); break;
			case sf::Keyboard::Left:role.MoveLeft(map); break;
			case sf::Keyboard::Right:role.MoveRight(map); break;
			case sf::Keyboard::Up:role.MoveUp(map); break;
			case sf::Keyboard::Down:role.MoveDown(map); break;
			case sf::Keyboard::A:role.MoveLeft(map); break;
			case sf::Keyboard::D:role.MoveRight(map); break;
			case sf::Keyboard::W:role.MoveUp(map); break;
			case sf::Keyboard::S:role.MoveDown(map); break;
			}
			switch (event(role, map))
			{
			case 0:break;
			case 1:scene = _map - 1; break;
			case 2:scene = MENU; break;
			}
		}
	}

	window.clear(sf::Color::White);
	draw(window);
	window.draw(time);
	window.draw(_time);
	window.draw(floor);
	window.draw(_floor);
	if (scene == FIVE){
		window.draw(textscore);
		window.draw(_score);
	}
	window.display();
	return scene;
}