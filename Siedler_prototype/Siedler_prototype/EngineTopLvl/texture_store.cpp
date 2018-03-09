#include "texture_store.h"
#include "../properties.h"
#include <iostream>


void TextureStore::loadAllTextures() {
	//laod simple textures
	sf::Texture* temp = new sf::Texture();
	temp->loadFromFile(Gras_Tile_Tex);
	this->textures.insert(std::pair<std::string, sf::Texture*>(GRAS_TILE, temp));
	
	temp = new sf::Texture();
	temp->loadFromFile(Sand_Tile_Tex);
	this->textures.insert(std::pair<std::string, sf::Texture*>(SAND_TILE, temp));

	//cursor textures
	temp = new sf::Texture();
	temp->loadFromFile(Cursor_1_Tex);
	this->textures.insert(std::pair<std::string, sf::Texture*>(CURSOR_1, temp));

	//load animation textures
	char b[2];
	sf::Image temp_img;
	std::vector<sf::Texture *> tex_bundle;		//wird dann kopiert..
	for (int i = 0; i < 8; i++) {
		
		temp = new sf::Texture();
		_itoa_s(i, b, 10);
		std::string path = std::string(Caveman_walking_se_tex) + std::string(b) + std::string(".bmp");
		temp_img.loadFromFile(path);
		temp_img.createMaskFromColor(temp_img.getPixel(0, 0), 0);
		temp->loadFromImage(temp_img);
		tex_bundle.push_back(temp);
	}
	this->animations.insert(std::pair<std::string, std::vector<sf::Texture*>>(CAVEMAN_WALKING_SE, tex_bundle));
}

sf::Texture& TextureStore::getTexture(std::string key) {
	return *(textures[key]);
}

std::vector<sf::Texture*> & TextureStore::getManyTextures(std::string key){
	return this->animations[key];
}


const std::string TextureStore::CURSOR_1 = "cursor_1";
const std::string TextureStore::GRAS_TILE = "gras_tile";
const std::string TextureStore::SAND_TILE = "sand_tile";
const std::string TextureStore::CAVEMAN_WALKING_SE = "caveman_w_se";