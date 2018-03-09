#pragma once

#include "SFML/Graphics.hpp"

/**
 * Every Object, which wants to be drawn to the screen, has to implement this interface. 
 */
class Drawable {
public:
	virtual ~Drawable() {};
	
	virtual void draw(sf::RenderWindow& window) const = 0;

	virtual double getYPosition() const = 0;
};