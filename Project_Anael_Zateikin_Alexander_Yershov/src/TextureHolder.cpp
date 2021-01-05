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

	newImage.loadFromFile("bar.png");
	m_textures.push_back(newImage);

	newImage.loadFromFile("coin.png");
	m_textures.push_back(newImage);

	newImage.loadFromFile("enemy.png");
	m_textures.push_back(newImage);

	newImage.loadFromFile("player.png");
	m_textures.push_back(newImage);

	newImage.loadFromFile("wall.jfif");
	m_textures.push_back(newImage);

	newImage.loadFromFile("ladder.png");
	m_textures.push_back(newImage);

	newImage.loadFromFile("floor.png");
	m_textures.push_back(newImage);

	sf::Font newFont;
	newFont.loadFromFile("sansation.ttf");
	this->m_font = newFont;
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
	case Elements::floor:
		return &m_textures[6];
		break;
	default:
		break;
	}
	return nullptr;
}
