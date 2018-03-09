#pragma once

#include "../EngineTopLvl/drawable.h"
#include "../properties.h"
#include "../EngineTopLvl/texture_store.h"

#include <SFML/Graphics.hpp>

class Tile : public Drawable {
protected:
	int xPos;
	int yPos;

	int width;
	int height;

	sf::Texture& tex;		//Reference to the Texture in the Texture-Store
	sf::Sprite sprite;		//The actual sprite (no reference)
public:
	Tile(int xPos, int yPos, int width, int height, sf::Texture& tex) : xPos(xPos), yPos(yPos), width(width), height(height), tex(tex) {
		sprite.setTexture(tex);
	}

};

class SandTile : public Tile {
private:
	
public:
	SandTile(int xPos, int yPos)
		: Tile(xPos, yPos, 64, 32, TextureStore::getInstance().getTexture(TextureStore::SAND_TILE)) {
		sprite.setPosition(static_cast<float>(xPos), static_cast<float>(yPos));
	}

	virtual void draw(sf::RenderWindow& window) const;

	virtual double getYPosition() const {
		return (double)yPos;
	}
};

class GrasTile : public Tile {
private:

public:
	GrasTile(int xPos, int yPos)
		: Tile(xPos, yPos, 64, 32, TextureStore::getInstance().getTexture(TextureStore::GRAS_TILE)) {
		sprite.setPosition(static_cast<float>(xPos), static_cast<float>(yPos));
	}

	virtual void draw(sf::RenderWindow& window) const;

	virtual double getYPosition() const {
		return (double)yPos;
	}
};