#pragma once

#include <SFML/System/Time.hpp>
#include <array>
#include <vector>
#include <iostream>
#include <string>

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

	virtual const std::array<int, 4>& getRectEventBox() const = 0;
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
	std::vector<Clickable *> clickableObj;
public:
	GameObjectStore() {}
	~GameObjectStore() {}

	void addAnimatedObj(Animatable* item);

	void removeAnimatedObj(Animatable* item);

	void addClickableObj(Clickable* item);

	void removeClickableObj(Clickable* item);
};