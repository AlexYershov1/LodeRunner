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
}

sf::Texture* TextureHolder::getIcon(const Elements symbol)
{
	switch (symbol)
	{
	case Elements::bar:
		return &m_textures[0];
		break;
	case Elements::coin:
		return &m_textures[1];
		break;
	case Elements::enemy:
		return &m_textures[2];
		break;
	case Elements::player:
		return &m_textures[3];
		break;
	case Elements::wall:
		return &m_textures[4];
		break;
	case Elements::ladder:
		return &m_textures[5];
		break;
	default:
		break;
	}
	return nullptr;
}
