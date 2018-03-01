#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class TileMap {
private:

public:

	void loadMap(std::string);

	void drawMap(sf::RenderWindow &window);
};