#pragma once

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

class TextureStore {
private:
	TextureStore() {}	//singleton!

	std::map<std::string, sf::Texture* > textures;
public:
	static const std::string GRAS_TILE;
	static const std::string SAND_TILE;

	TextureStore(TextureStore const&) = delete;
	void operator=(TextureStore const&) = delete;

	static TextureStore& getInstance() {
		static TextureStore instance;
		return instance;
	}

	void loadAllTextures();

	sf::Texture& getTexture(std::string key);
};