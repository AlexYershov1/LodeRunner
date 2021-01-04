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

private:
	std::vector<sf::Texture> m_textures;
};

