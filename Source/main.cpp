#pragma once
#include "stdafx.h"
#include "data.h"

#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup" )

extern void init();
extern int start(sf::RenderWindow &window);
extern int menu(sf::RenderWindow &window);
extern int status(sf::RenderWindow &window, bool);
extern int unfinished(sf::RenderWindow &window);
extern int game(sf::RenderWindow &window, int, bool);
extern int bag(sf::RenderWindow &window, bool);
extern int workshop(sf::RenderWindow &window, bool);
extern int school(sf::RenderWindow &window, bool);
extern int option(sf::RenderWindow &window);

Data data;
sf::Music music;

int main()
{
	init();
	sf::RenderWindow window(sf::VideoMode(800, 450), "Game");
	window.setFramerateLimit(30);
	int scene = START;

	music.openFromFile("music/menu.ogg");
	music.setVolume(50);
	music.setLoop(true);
	music.play();

	while (window.isOpen())
	{
		switch (scene)
		{
		case START:	scene = start(window); break;
		case MENU:	scene = menu(window); break;
		case STATUS: scene = status(window,true); break;
		case STATUS_INIT: scene = status(window, false); break;
		case BAG: scene = bag(window, true); break;
		case BAG_INIT: scene = bag(window, false); break;
		case WORKSHOP: scene = workshop(window, true); break;
		case WORKSHOP_INIT: scene = workshop(window, false); break;
		case SCHOOL: scene = school(window, false); break;
		case SCHOOL_INIT: scene = school(window, true); break;
		case OPTION: scene = option(window); break;
		case UNFINISHED: scene = unfinished(window); break;
		case ONE_INIT:	 scene = game(window, ONE, false); break;
		case ONE: scene = game(window, ONE, true); break;
		case TWO_INIT:	 scene = game(window, TWO, false); break;
		case TWO: scene = game(window, TWO, true); break;
		case THREE_INIT:	 scene = game(window, THREE, false); break;
		case THREE: scene = game(window, THREE, true); break;
		case FOUR_INIT:	 scene = game(window, FOUR, false); break;
		case FOUR: scene = game(window, FOUR, true); break;
		case FIVE_INIT:	 scene = game(window, FIVE, false); break;
		case FIVE: scene = game(window, FIVE, true); break;
		}
	}
}