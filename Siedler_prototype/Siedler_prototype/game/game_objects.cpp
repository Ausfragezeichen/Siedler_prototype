
#include "game_objects.h"

void GameObjectStore::addAnimatedObj(Animatable* item) {
	this->animatedObj.push_back(item);
}

void GameObjectStore::removeAnimatedObj(Animatable* item) {
	this->animatedObj.erase(std::remove(this->animatedObj.begin(), this->animatedObj.end(), item), this->animatedObj.end());
}

void GameObjectStore::addClickableObj(Clickable* item, GameObjectStore::MouseButtons mb, int zlvl) {
	if (mb == GameObjectStore::MouseButtons::LEFT) {
		this->clickableLeftObj[zlvl].push_back(item);
	}
	else if (mb == GameObjectStore::MouseButtons::RIGHT) {
		this->clickableRightObj[zlvl].push_back(item);
	}
}

void GameObjectStore::removeClickableObj(Clickable* item, GameObjectStore::MouseButtons mb, int zlvl) {
	if (mb == GameObjectStore::MouseButtons::LEFT) {
		this->clickableLeftObj[zlvl].erase(std::remove(this->clickableLeftObj[zlvl].begin(), this->clickableLeftObj[zlvl].end(), item), this->clickableLeftObj[zlvl].end());
	}
	else if (mb == GameObjectStore::MouseButtons::RIGHT) {
		this->clickableRightObj[zlvl].erase(std::remove(this->clickableRightObj[zlvl].begin(), this->clickableRightObj[zlvl].end(), item), this->clickableRightObj[zlvl].end());
	}
	
}

void GameObjectStore::findClickedObject(int x, int y, GameObjectStore::MouseButtons mb){
	if (mb == GameObjectStore::MouseButtons::LEFT) {
		for (int z = Z - 1; z >= 0; z--) {
			for (auto const& item : clickableLeftObj[z]) {
				if (item->isClicked(x, y)) {
					//break loop and handle the event.
				}
			}
		}
	}
	else if (mb == GameObjectStore::MouseButtons::RIGHT) {

	}
}