#pragma once

#include <SFML/System/Time.hpp>
#include <array>
#include <vector>
#include <iostream>
#include <string>
#include "../properties.h"

/*interface*/
class Animatable {
public:
	virtual ~Animatable() {}

	virtual void updateAnimation(sf::Int64 time_millies) = 0;
};
/*interface*/
class Clickable {
public:
	virtual ~Clickable() {}

	virtual void clicked(int x, int y) = 0;

	virtual bool isClicked(int x, int y) const = 0;
};


/* abstract superclass of all Game Objects*/
class GameObject {
protected:

public :

};

/* holds all game objects and references to them in various lists for quick access*/
class GameObjectStore {
private:
	std::vector<Animatable *> animatedObj;
	std::array<std::vector<Clickable *>, Z> clickableLeftObj;
	std::array<std::vector<Clickable *>, Z> clickableRightObj;
public:
	enum class MouseButtons {
		LEFT, RIGHT
	};

	GameObjectStore() {}
	~GameObjectStore() {}

	void addAnimatedObj(Animatable* item);

	void removeAnimatedObj(Animatable* item);

	void addClickableObj(Clickable* item, GameObjectStore::MouseButtons mb, int zlvl);

	void removeClickableObj(Clickable* item, GameObjectStore::MouseButtons mb, int zlvl);

	void findClickedObject(int x, int y, GameObjectStore::MouseButtons mb);
};