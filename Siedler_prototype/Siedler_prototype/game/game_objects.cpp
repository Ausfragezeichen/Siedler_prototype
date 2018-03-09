
#include "game_objects.h"

void GameObjectStore::addAnimatedObj(Animatable* item) {
	this->animatedObj.push_back(item);
}

void GameObjectStore::removeAnimatedObj(Animatable* item) {
	this->animatedObj.erase(std::remove(this->animatedObj.begin(), this->animatedObj.end(), item), this->animatedObj.end());
}

void GameObjectStore::addClickableObj(Clickable* item) {
	this->clickableObj.push_back(item);
}

void GameObjectStore::removeClickableObj(Clickable* item) {
	this->clickableObj.erase(std::remove(this->clickableObj.begin(), this->clickableObj.end(), item), this->clickableObj.end());
}