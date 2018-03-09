#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class TileMap {
private:
	int xDim;
	int yDim;

	std::vector<char> map_char_rep;

	std::vector<sf::Texture *> map_textures;
	std::vector<sf::Sprite *> map_sprites;

public:
	TileMap() :xDim(0), yDim(0) {};

	/**
	* expects the directory of a file, where the first 2 lines specify the dimension of the map, afterwards the map in char representation
	*/
	void loadMap(std::string map_direction);

	void loadTextures();

	void loadSprites();

	void drawMap(sf::RenderWindow &window);
};