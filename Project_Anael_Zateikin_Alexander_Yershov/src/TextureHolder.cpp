#pragma once
#include "TextureHolder.h"

TextureHolder::TextureHolder()
{
	setImagesForObj();
	createSwitchingIcons();
}

TextureHolder::~TextureHolder()
{
}

TextureHolder& TextureHolder::instance()
{
	static TextureHolder inst;
	return inst;
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

	this->m_font.loadFromFile("SundayMorning.ttf");
}

sf::Texture* TextureHolder::getIcon(const Elements symbol)
{
	return &this->m_textures[(int)symbol];
}

void TextureHolder::createSwitchingIcons()
{
	
	sf::Texture newImage;

	m_iconVec.push_back(this->m_textures[(int)Elements::player]);
	m_iconVec.push_back(this->m_textures[(int)Elements::enemy]);

	newImage.loadFromFile("climbingPlayer.png");
	m_iconVec.push_back(newImage);

	newImage.loadFromFile("climbingLadder.png");
	m_iconVec.push_back(newImage);

	newImage.loadFromFile("barClimbing.png");
	m_iconVec.push_back(newImage);
}

sf::Texture* TextureHolder::getChangingIcon(const MovingObjTexture symbol)
{
	return &this->m_iconVec[(int)symbol];
}