#pragma once
#include "stdafx.h"
#include "item.h"
#include "gempack.h"

class Data
{
private:
	int money;
	std::vector<Item*> items;
	std::vector<GemPack*> gempacks;

public:
	int moneyget;
	int itemsget;
	int taskfinished;
	int skill_gem;
	int skill_gold;

public:
	bool is_music;
	bool is_sound;
	int roletype;
	int ac[6];
	int floor;
	sf::Clock clock;
	sf::Clock game_time;
	int game_score;
	int extra_time;
	sf::Clock cool_time[5];
	int cool_time_down;
	float gem_p;
	float pack_p;
	float barrier_p;

	void AddItem(int id, int num = 1);
	void DeleteItem(int id, int num = 1);
	void AddGemPack(int id, int num = 1);
	void AddMoney(int id);
	bool Compound(int id);
	void UpdateAc();
	bool SkillGemUp();
	bool SkillGoldUp();

	friend bool bag_init();
	friend bool workshop_init();
	friend bool school_init();
	friend int school(sf::RenderWindow &window , bool);
	friend int workshop(sf::RenderWindow &window, bool);
	friend void workshop_draw(sf::RenderWindow &window);
	friend class GemPack;
	Data(){ 
		items.clear(); 
		gempacks.clear(); 
		is_music = true;
		is_sound = true;
		floor = 0; 
		money = 10000;
		roletype = 0; 
		moneyget = 10000; 
		itemsget = 0; 
		taskfinished = 0; 
		skill_gem = 0;
		skill_gold = 0;
		cool_time_down = 0; 
		gem_p = 0;
		pack_p = 0;
		barrier_p = 0;
	}
};