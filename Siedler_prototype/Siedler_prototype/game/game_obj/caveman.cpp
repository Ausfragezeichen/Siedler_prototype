#include "caveman.h"

void CaveMan::updateAnimation(sf::Int64 time_millies) {
	if (this->status == 0) {	//walking
		if (time_millies - lastUpdate > 200*1000) {
			currentFrameIndex = (currentFrameIndex + 1) % 8;
			this->currentSprite = &spritesWalkingSE[currentFrameIndex];
			lastUpdate = time_millies;
		}
	}
}

void CaveMan::clicked(int x, int y) {
	if (xPos + clickEventBox[0] < x && xPos + clickEventBox[2] > x) {
		if (yPos + clickEventBox[1] < y && yPos + clickEventBox[3] > y) {
			std::cout << "The caveman has been clicked on!" << "\n";
		}
	}
}

bool CaveMan::isClicked(int x, int y) const {
	if (xPos + clickEventBox[0] < x && xPos + clickEventBox[2] > x) {
		if (yPos + clickEventBox[1] < y && yPos + clickEventBox[3] > y) {
			return true;
		}
	}
	return false;
}

void CaveMan::draw(sf::RenderWindow& window) const {
	if (currentSprite != nullptr) {
		window.draw(*(this->currentSprite));
	}
}

double CaveMan::getYPosition() const {
	return this->yPos;
}