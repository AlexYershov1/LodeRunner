#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class TextureHolder
{
public:
	TextureHolder();
	~TextureHolder();
	void setImagesForObj();

private:
	std::vector<sf::Texture> m_textures;
};

