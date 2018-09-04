#include <map>
#include "data.h"

std::map<int, std::string> ID;
std::map<int, int> Cost;
sf::SoundBuffer action;
sf::Sound actions;
sf::SoundBuffer pagerun;
sf::Sound pageruns;
sf::SoundBuffer itemget;
sf::Sound itemgets;
sf::SoundBuffer itemup;
sf::Sound itemups;
sf::SoundBuffer skillup;
sf::Sound skillups;
sf::SoundBuffer error;
sf::Sound errors;
extern Data data;

void init()
{
	ID[11] = "gem1a";
	ID[12] = "gem1b";
	ID[21] = "gem2a";
	ID[22] = "gem2b";
	ID[31] = "gem3a";
	ID[32] = "gem3b";
	ID[41] = "gem4a";
	ID[42] = "gem4b";
	ID[51] = "gem5a";
	ID[52] = "gem5b";
	ID[6] = "gem6";
	ID[7] = "gem7";

	Cost[0] = 1000;
	Cost[1] = 2000;
	Cost[2] = 5000;
	Cost[3] = 12000;
	Cost[4] = 30000;
	Cost[5] = 80000;
	Cost[6] = 150000;


	ID[10001] = "token/1.png";
	ID[10002] = "token/2.png";
	ID[10003] = "token/3.png";
	ID[10004] = "token/4.png";

	ID[1000001] = "energy/1";
	ID[1000002] = "energy/2";
	ID[1000003] = "energy/3";

	ID[1000000001] = "time/1";
	ID[1000000002] = "time/2";
	ID[1000000003] = "time/3";

	ID[101] = "Gempack";

	action.loadFromFile("music/action.wav");
	actions.setBuffer(action);

	pagerun.loadFromFile("music/pagerun.wav");
	pageruns.setBuffer(pagerun);

	itemget.loadFromFile("music/get.wav");
	itemgets.setBuffer(itemget);

	itemup.loadFromFile("music/itemup.wav");
	itemups.setBuffer(itemup);

	skillup.loadFromFile("music/itemup.wav");
	skillups.setBuffer(skillup);

	error.loadFromFile("music/error.wav");
	errors.setBuffer(error);

	data.AddGemPack(1, 2);
}