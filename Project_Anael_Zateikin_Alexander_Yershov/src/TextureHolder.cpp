#pragma once
#include "TextureHolder.h"

TextureHolder::TextureHolder()
{
	setImagesForObj();
}

TextureHolder::~TextureHolder()
{
}

// load all the object images
void TextureHolder::setImagesForObj()
{

	sf::Texture newImage;

	newImage.loadFromFile("../../../Resource/Bar.jpg");
	m_textures.push_back(newImage);

	newImage.loadFromFile("../../../Resource/Coin.jfif");
	m_textures.push_back(newImage);

	newImage.loadFromFile("../../../Resource/Enemy.jpg");
	m_textures.push_back(newImage);

	newImage.loadFromFile("../../../Resource/Player.png");
	m_textures.push_back(newImage);

	newImage.loadFromFile("../../../Resource/Wall.jfif");
	m_textures.push_back(newImage);

	newImage.loadFromFile("../../../Resource/Ladder.png");
	m_textures.push_back(newImage);

	newImage.loadFromFile("../../../Resource/White_Background.png");
	m_textures.push_back(newImage);
}