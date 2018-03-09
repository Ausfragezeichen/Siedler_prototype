
#include "z_lvl_rendering.h"

#include <algorithm>
#include <functional>
#include <iostream>

void ZlvlRendering::addDrawable(Drawable* item, int zlvl) {
	this->z_lvls[zlvl].push_back(item);
}

void ZlvlRendering::removeDrawable(Drawable* item, int zlvl) {
	this->z_lvls[zlvl].erase(std::remove(this->z_lvls[zlvl].begin(), this->z_lvls[zlvl].end(), item), this->z_lvls[zlvl].end());
}

void ZlvlRendering::sortDrawables(int zlvl) {
	std::function<bool(Drawable*, Drawable*)> comp = [](Drawable* a, Drawable* b){
		return a->getYPosition() > b->getYPosition();
	};
	std::sort(this->z_lvls[zlvl].begin(), this->z_lvls[zlvl].end(), comp);
	/*std::sort(this->z_lvls[zlvl].begin(), this->z_lvls[zlvl].end(), [](const Drawable * a, const Drawable * b) -> bool
	{
		return a->getYPosition() < b->getYPosition();
	});*/
}

void ZlvlRendering::drawLoop() const {
	for (int z = 0; z < Z; z++) {
		for (auto const& element : this->z_lvls[1]) {
			element->draw(window);
		}
	}
	//render Mouse
	if(a)
		window.draw(*mouseSprite2);
	else
		window.draw(*mouseSprite2);
	
}

void ZlvlRendering::setCurser(sf::Sprite* cursorSprite1, sf::Sprite* cursorSprite2){
	this->mouseSprite1 = cursorSprite1;
	this->mouseSprite2 = cursorSprite2;
}

void ZlvlRendering::changeCursor(){
	bool a = false;
}