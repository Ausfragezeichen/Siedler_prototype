#include <iostream>

#include <stdio.h>

#include "SFML/Graphics.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600),
		"Hello SFML", sf::Style::Default);

	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

	sf::Text text;
	text.setFont(font);
	text.setPosition(200, 200);
	text.setString("Hello SFML");

	sf::Texture texture;
	if (!texture.loadFromFile("../../Siedler_prototype/sprites/env/sandTile.png")) {

	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(20, 200);

	sf::Image image;
	image.loadFromFile("../../Siedler_prototype/sprites/char/caveman/caveman 96 bitmaps/running e0000.bmp");
	image.createMaskFromColor(image.getPixel(0, 0), 0);

	sf::Texture texture_1;
	texture_1.loadFromImage(image);
	sf::Sprite sprite_1;
	sprite_1.setTexture(texture_1);
	sprite_1.setScale(.5, .5);
	sprite_1.setPosition(20, 130);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);
		window.draw(text);
		window.draw(sprite);
		window.draw(sprite_1);
		window.display();
	}

	return 0;
}