#include "stdafx.h"

int unfinished(sf::RenderWindow &window)
{
	sf::Texture backgrand;
	backgrand.loadFromFile("images/unfinished.png");
	sf::Sprite backgrands(backgrand);

	sf::Texture back;
	back.setSmooth(true);
	static sf::Color color = sf::Color::Black;
	back.loadFromFile("images/back.png");
	sf::Sprite backs(back);
	backs.setPosition(735, 5);
	backs.setColor(color);

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
		}

		if (event.type == sf::Event::EventType::MouseButtonReleased)
		{
			if (position.x > backs.getPosition().x&&position.x < backs.getPosition().x + back.getSize().x
				&& position.y > backs.getPosition().y&&position.y < backs.getPosition().y + back.getSize().y)
				return MENU;
		}
	}

	window.clear();
	window.draw(backgrands);
	window.draw(backs);
	window.display();
	return UNFINISHED;
}