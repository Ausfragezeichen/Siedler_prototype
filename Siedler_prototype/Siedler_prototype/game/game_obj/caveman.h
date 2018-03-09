#pragma once

#include "../game_objects.h"
#include "../../EngineTopLvl/texture_store.h"
#include <SFML/Graphics.hpp>
#include <string> 
#include <stdlib.h>	//itoa
#include "../../EngineTopLvl/drawable.h"
#include "../../EngineTopLvl/texture_store.h"


class CaveMan : public Animatable, public Clickable, public Drawable {
private:
	std::array<int, 4> clickEventBox;
	std::array<sf::Sprite, 8> spritesWalkingSE;
	int xPos;
	int yPos;
	std::array<sf::Texture*, 8> texturesWalkingSE;

public:
	CaveMan(int xPos, int yPos) : clickEventBox({ 0, 0, 96, 96 }), xPos(xPos), yPos(yPos) {
		std::string key = "caveman_walk_se_x";
		char b[2];
		for (int i = 0; i < 8; i++) {
			//key[16] = std::to_string(i);		//should work, but windows-compiler is stuipid here
			_itoa_s(i,b,10);
			key[16] = b[0];
			std::cout << "key: " << key << "\n";
		}
		TextureStore::getInstance.
	}

	virtual void updateAnimation(sf::Int64 time_millies);

	virtual void clicked(int x, int y);

	virtual const std::array<int, 4>& getRectEventBox() const;

	virtual void draw(sf::RenderWindow& window) const;

	virtual double getYPosition() const;
};