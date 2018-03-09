#pragma once

#include <map>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class TextureStore {
private:
	TextureStore() {}	//singleton!

	std::map<std::string, sf::Texture* > textures;
	std::map<std::string, std::vector<sf::Texture *>> animations;
public:
	static const std::string CURSOR_1;
	static const std::string CURSOR_2;
	static const std::string CURSOR_3;
	static const std::string GRAS_TILE;
	static const std::string SAND_TILE;
	static const std::string CAVEMAN_WALKING_SE;

	TextureStore(TextureStore const&) = delete;
	void operator=(TextureStore const&) = delete;

	static TextureStore& getInstance() {
		static TextureStore instance;
		return instance;
	}

	void loadAllTextures();

	sf::Texture& getTexture(std::string key);

	std::vector<sf::Texture *>& getManyTextures(std::string key);
};