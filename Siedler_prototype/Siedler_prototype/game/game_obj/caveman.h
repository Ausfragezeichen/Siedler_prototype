#pragma once

#include "../game_objects.h"
#include "../../EngineTopLvl/texture_store.h"
#include <SFML/Graphics.hpp>
#include <string> 
#include <stdlib.h>	//itoa


class CaveMan : public Animatable, public Clickable {
private:
	std::array<int, 4> clickEventBox;
	std::array<sf::Sprite, 8> spritesWalkingSE;
	int xPos;
	int yPos;

public:
	CaveMan(int xPos, int yPos) : clickEventBox({ 0, 0, 96, 96 }), xPos(xPos), yPos(yPos) {
		std::string key = "caveman_walk_se_x";
		char b[2];
		for (int i = 0; i < 8; i++) {
			//key[16] = std::to_string(i);		//should work, but win-compiler is stuipid here
			_itoa_s(i,b,10);
			key[16] = b[0];
			std::cout << "key: " << key << "\n";
		}
		
	}

	virtual void updateAnimation(sf::Int64 time_millies);

	virtual void clicked(int x, int y);

	virtual const std::array<int, 4>& getRectEventBox() const;
};