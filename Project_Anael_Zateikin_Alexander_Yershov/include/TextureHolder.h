#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Macros.h"

class TextureHolder
{
public:
	~TextureHolder();
	static TextureHolder& instance();
	
	// get functions
	sf::Texture* getIcon(const Elements);
	sf::Texture* getChangingIcon(MovingObjTexture);
private:
	TextureHolder();
	TextureHolder(const TextureHolder&) = default;
	TextureHolder& operator=(const TextureHolder&) = default;

	void setImagesForObj();
	void createSwitchingIcons();
	std::vector<sf::Texture> m_textures;
	std::vector<sf::Texture> m_iconVec;
	sf::Font m_font;
};

