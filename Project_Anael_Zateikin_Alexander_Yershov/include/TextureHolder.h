#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Macros.h"

class TextureHolder
{
public:
	TextureHolder();
	~TextureHolder();
	void setImagesForObj();
	sf::Texture* getIcon(const Elements);
	std::vector<sf::Texture*> createSwitchingIcons();
private:
	std::vector<sf::Texture> m_textures;
	sf::Font m_font;
};

