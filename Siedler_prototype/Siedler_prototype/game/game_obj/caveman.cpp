#include "caveman.h"

void CaveMan::updateAnimation(sf::Int64 time_millies) {

}

void CaveMan::clicked(int x, int y) {
	std::cout << "The caveman has been clicked on!" << "\n";
}

const std::array<int, 4>& CaveMan::getRectEventBox() const {
	return this->clickEventBox;
}