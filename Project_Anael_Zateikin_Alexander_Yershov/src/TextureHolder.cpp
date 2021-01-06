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

	newImage.loadFromFile("wall.png");
	m_textures.push_back(newImage);

	newImage.loadFromFile("ladder.png");
	m_textures.push_back(newImage);

	newImage.loadFromFile("floor.png");
	m_textures.push_back(newImage);

	newImage.loadFromFile("bonus.png");
	m_textures.push_back(newImage);

	newImage.loadFromFile("barClimbing.png");
	m_textures.push_back(newImage);

	newImage.loadFromFile("climbingLadder.png");
	m_textures.push_back(newImage);

	newImage.loadFromFile("climbingPlayer.png");
	m_textures.push_back(newImage);

	this->m_font.loadFromFile("SundayMorning.ttf");
}

sf::Texture* TextureHolder::getIcon(const Elements symbol)
{
	switch (symbol)
	{
	case Elements::bar:
		return &m_textures[(int)Elements::bar];
		break;
	case Elements::coin:
		return &m_textures[(int)Elements::coin];
		break;
	case Elements::enemy:
		return &m_textures[(int)Elements::enemy];
		break;
	case Elements::player:
		return &m_textures[(int)Elements::player];
		break;
	case Elements::wall:
		return &m_textures[(int)Elements::wall];
		break;
	case Elements::ladder:
		return &m_textures[(int)Elements::ladder];
		break;
	case Elements::floor:
		return &m_textures[(int)Elements::floor];
		break;
	default:
		break;
	}
	return nullptr;
}

std::vector<sf::Texture*> TextureHolder::createSwitchingIcons()
{
	std::vector<sf::Texture*> iconVec;
	iconVec.push_back(&this->m_textures[(int)Elements::player]);
	iconVec.push_back(&this->m_textures[10]);
	iconVec.push_back(&this->m_textures[(int)Elements::enemy]);
	iconVec.push_back(&this->m_textures[9]);
	iconVec.push_back(&this->m_textures[8]);

	return iconVec;
}
