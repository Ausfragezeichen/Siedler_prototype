#pragma once

#include <vector>
#include <array>
#include "drawable.h"
#include "../properties.h"

class ZlvlRendering {
private:
	
	std::array<std::vector<Drawable*>, Z> z_lvls;

	sf::RenderWindow& window;

	sf::Sprite* mouseSprite = nullptr;

public:
	ZlvlRendering(sf::RenderWindow& window) : window(window) {

	}
	~ZlvlRendering() {};

	void addDrawable(Drawable* item, int zlvl);

	void removeDrawable(Drawable* item, int zlvl);

	void sortDrawables(int zlvl);

	void setCurser(sf::Sprite* cursorSprite);

	/**
	 * runs in different Thread! Fine, as long as all requests are handled "read-only"
	 */
	void drawLoop() const;
};