#include <iostream>

#include <stdio.h>
#include <thread>

#include <SFML/Graphics.hpp>

#include <SFML/System/Time.hpp>

#include "game/TileMap.h"
#include "EngineTopLvl/z_lvl_rendering.h"
#include "game/tile.h"
#include "properties.h"
#include "EngineTopLvl/texture_store.h"
#include "game/game_objects.h"
#include "game/game_obj/caveman.h"


void renderingThread(sf::RenderWindow* window, ZlvlRendering& z)
{
	while (window->isOpen())
	{

		window->clear(sf::Color::Black);
		z.drawLoop();

		window->display();
	}
}

int main()
{
	

	sf::RenderWindow window(sf::VideoMode(800, 600),
		"Hello SFML", sf::Style::Default);
	window.setActive(false);

	ZlvlRendering zlvlRendering(window);
	sf::Texture texture;
	TextureStore& ts = TextureStore::getInstance();
	ts.loadAllTextures();

	Tile* t1 = new SandTile(100, 100);
	Tile* t2 = new GrasTile(100, 110);

	zlvlRendering.addDrawable(t1, 1);
	zlvlRendering.addDrawable(t2, 1);

	zlvlRendering.sortDrawables(1);

	CaveMan cMan(80, 40);
	zlvlRendering.addDrawable(&cMan, 1);

	//load stuff for different mouse cursor
	sf::Texture& cursor_tex = TextureStore::getInstance().getTexture(TextureStore::CURSOR_1);
	sf::Sprite cursor_1(cursor_tex);
	zlvlRendering.setCurser(&cursor_1);
	
	
	sf::Thread drawThread(std::bind(&renderingThread, &window, zlvlRendering));
	drawThread.launch();

	sf::Clock clock;

	std::vector<Animatable *> allAnimatables = { &cMan };
	std::vector<Clickable *> allRightClickables = { &cMan };



	bool useCustomCursor = false;

	while (window.isOpen())
	{
		sf::Time current_time = clock.getElapsedTime();
		sf::Int64 mu_s = current_time.asMicroseconds();
		
		//go through all animatable objects
		for (auto const& item : allAnimatables) {
			item->updateAnimation(mu_s);
		}

		if(useCustomCursor)
			cursor_1.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					for (auto const& item : allRightClickables) {
						item->clicked(event.mouseButton.x, event.mouseButton.y);
					}
				}
				if (event.mouseButton.button == sf::Mouse::Right) {
					window.setMouseCursorVisible(false); // Hide cursor#
					useCustomCursor = true;
					
				}
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}



	}


	//drawThread.join();

	/*
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
	//sprite_1.setScale(.5, .5);
	sprite_1.setPosition(20, 130);

	TileMap tileMap;
	tileMap.loadMap("../maps/simple_map_1.txt");
	tileMap.loadTextures();
	tileMap.loadSprites();
	*/
	
	
	return 0;
}