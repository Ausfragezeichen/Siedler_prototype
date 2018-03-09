#pragma once

#include <vector>
#include <array>
#include "drawable.h"

class ZlvlRendering {
private:
	static const int Z = 5;
	std::array<std::vector<Drawable*>, Z> z_lvls;

	sf::RenderWindow& window;

public:
	ZlvlRendering(sf::RenderWindow& window) : window(window) {

	}
	~ZlvlRendering() {};

	void addDrawable(Drawable* item, int zlvl);

	void removeDrawable(Drawable* item, int zlvl);

	void sortDrawables(int zlvl);

	/**
	 * runs in different Thread! Fine, as long as all requests are handled "read-only"
	 */
	void drawLoop() const;
};