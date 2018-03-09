
#include "TileMap.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>

void TileMap::loadMap(std::string map_directory){
	std::ifstream infile(map_directory);
	std::string line;
	int counter = 0;
	while (std::getline(infile, line)){
		switch (counter){
		case 0:
			this->xDim = std::stoi(line);
			break;
		case 1:
			this->yDim = std::stoi(line);
			break;
		default:
			std::cout << line << "\n";
			for (int i = 0; i < xDim-1; i++) {
				map_char_rep.push_back(line.at(i));
			}
			break;
		}
		counter++;
	}
	std::cout << "map dimensions: " << xDim << " " << yDim << "\n";
}

void TileMap::loadTextures() {
	sf::Texture* temp_tex = new sf::Texture();
	temp_tex->loadFromFile("../../Siedler_prototype/sprites/env/grassTile.png");
	map_textures.push_back(temp_tex);
	sf::Texture* temp_tex_1 = new sf::Texture();
	temp_tex_1->loadFromFile("../../Siedler_prototype/sprites/env/sandTile.png");
	map_textures.push_back(temp_tex_1);
}

void TileMap::loadSprites() {
	int counter = 0;
	int a = 0;
	int b = 0;
	bool inc_b = false;
	for (auto const& item : map_char_rep) {
		sf::Sprite* temp_sprite = new sf::Sprite();
		if (item == 'g') {
			temp_sprite->setTexture(*map_textures.at(0));
		}
		else if (item == 's') {
			temp_sprite->setTexture(*map_textures.at(1));
		}
		if (b%2 == 0)
			temp_sprite->setPosition(a * 64, b/2 * 32);
		else {
			temp_sprite->setPosition(a * 64+32, b /2 * 32 + 16);
		}
		map_sprites.push_back(temp_sprite);
		counter++;
		a++;
		if (counter % xDim == 0) {
			b++;
			a = 0;
		}
	}
}

void TileMap::drawMap(sf::RenderWindow &window){
	for(auto const& item : map_sprites)
		window.draw(*item);
}