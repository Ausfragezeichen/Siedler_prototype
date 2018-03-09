#include "texture_store.h"
#include "../properties.h"


void TextureStore::loadAllTextures() {
	sf::Texture* temp = new sf::Texture();
	temp->loadFromFile(Gras_Tile_Tex);
	this->textures.insert(std::pair<std::string, sf::Texture*>(GRAS_TILE, temp));
	
	temp = new sf::Texture();
	temp->loadFromFile(Sand_Tile_Tex);
	this->textures.insert(std::pair<std::string, sf::Texture*>(SAND_TILE, temp));
}

sf::Texture& TextureStore::getTexture(std::string key) {
	return *(textures[key]);
}

const std::string TextureStore::GRAS_TILE = "gras_tile";
const std::string TextureStore::SAND_TILE = "sand_tile";