#pragma once
#include <iostream>
#include "data.h"

extern std::map<int, int> Cost;

void Data::AddItem(int id, int num)
{
	std::vector<Item*>::iterator it;
	for (it = items.begin(); it != items.end(); it++)
	{
		if ((*it)->id == id)
		{
			(*it)->num += num; 
			itemsget += num; break;
		}
	}
	if (it == items.end())
	{
		items.push_back(new Item(id, num));
		itemsget += num;
	}
}

void Data::DeleteItem(int id, int num)
{
	std::vector<Item*>::iterator it;
	for (it = items.begin(); it != items.end(); it++)
	{
		if ((*it)->id == id)
		{
			(*it)->num -= num; 
			if ((*it)->num == 0)
				it = items.erase(it);
			break;
		}
	}
}

void Data::AddGemPack(int id, int num)
{
	std::vector<GemPack*>::iterator it;
	for (it = gempacks.begin(); it != gempacks.end(); it++)
	{
		if ((*it)->id == id)
		{
			(*it)->num += num; break;
		}
	}
	if (it == gempacks.end())
	{
		gempacks.push_back(new GemPack(id, num));
	}
}

void Data::AddMoney(int num)
{
	money += num;
	moneyget += num;
}

bool Data::SkillGemUp()
{
	if (skill_gem >= 7 || money < Cost[skill_gem])return false;
	money -= Cost[skill_gem];
	skill_gem++; 
	AddItem(6, skill_gem * 10);
	return true;
}

bool Data::SkillGoldUp()
{
	if (skill_gold >= 7 || money < Cost[skill_gold])return false;
	money -= Cost[skill_gold];
	skill_gold++; return true;
}

bool Data::Compound(int id)
{
	std::vector<Item*>::iterator it;
	if (id == 6)
	{
		for (it = items.begin(); it != items.end(); it++)
		{
			if ((*it)->id == id)
			{
				for (int i = 0; i <= 10; i++)
				{
					srand(clock.getElapsedTime().asMicroseconds());
					switch (rand() % 10)
					{
					case 0:AddItem(11, 1); break;
					case 1:AddItem(21, 1); break;
					case 2:AddItem(31, 1); break;
					case 3:AddItem(41, 1); break;
					case 4:AddItem(51, 1); break;
					case 5:AddItem(12, 1); break;
					case 6:AddItem(22, 1); break;
					case 7:AddItem(32, 1); break;
					case 8:AddItem(42, 1); break;
					case 9:AddItem(52, 1); break;
					}
				}
				DeleteItem(id, 1);
				break;
			}
		}
		return true;
	}

	if (id % 10 != 1)	return false;

	for (it = items.begin(); it != items.end(); it++)
	{
		if ((*it)->id == id)
		{
			if ((*it)->num >= 3)
			{
				DeleteItem(id, 3);
				AddItem(id + 1, 1);
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}

void Data::UpdateAc()
{
	if (clock.getElapsedTime().asSeconds() > 3600)
	{
		ac[0] = 3;
	}
	else if (clock.getElapsedTime().asSeconds() > 1800)
	{
		ac[0] = 2;
		cool_time_down = 150;
	}
	else if (clock.getElapsedTime().asSeconds() > 600)
	{
		ac[0] = 1;
		cool_time_down = 60;
	}

	if (moneyget > 200000)
		ac[1] = 3;
	else if (moneyget > 50000)
		ac[1] = 2;
	else if (moneyget > 10000)
		ac[1] = 1;
	else
		ac[1] = 0;

	if (itemsget > 2000)
	{
		ac[2] = 3;
		gem_p = 1;
	}
	else if (itemsget > 500)
	{
		ac[2] = 2;
		gem_p = 0.5;
	}
	else if (itemsget > 100)
	{
		ac[2] = 1;
		gem_p = 0.2;
	}
	else
		ac[2] = 0;

	int count = 0;
	for (std::vector<GemPack*>::iterator it = gempacks.begin(); it != gempacks.end(); it++)
	{
		if ((*it)->statue == 1)
			count++;
	}
	if (count > 35)
	{
		ac[3] = 3;
		pack_p = 1;
	}
	else if (count > 15)
	{
		ac[3] = 2;
		pack_p = 0.5;
	}
	else if (count > 5)
	{
		ac[3] = 1;
		pack_p = 0.2;
	}
	else
		ac[3] = 0;

	count = 0;
	for (std::vector<Item*>::iterator it = items.begin(); it != items.end(); it++)
	{
		if ((*it)->id == 7)
			count = (*it)->num;
	}
	if (count >= 10)
	{
		ac[4] = 3;
		barrier_p = 0.5;
	}
	else if (count >= 5)
	{
		ac[4] = 2;
		barrier_p = 0.3;
	}
	else if (count >= 2)
	{
		ac[4] = 1;
		barrier_p = 0.1;
	}
	else
		ac[4] = 0;

	ac[5] = 3;
}