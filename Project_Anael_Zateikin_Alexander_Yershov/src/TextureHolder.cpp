#pragma once
#include "TextureHolder.h"

TextureHolder::TextureHolder() : m_enemySerialNumber(0)
{
	setImagesForObj();
	createSwitchingIcons();
	createEnemySwitchingIcons();
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

	newImage.loadFromFile("enemyBack.png");
	m_iconVec.push_back(newImage);

	newImage.loadFromFile("barClimbing.png");
	m_iconVec.push_back(newImage);
}

void TextureHolder::createEnemySwitchingIcons()
{
	sf::Texture newImage;

	newImage.loadFromFile("0_Citizen_Walk_013.png");
	m_enemyAnime.push_back(newImage);

	newImage.loadFromFile("0_Citizen_Walk_014.png");
	m_enemyAnime.push_back(newImage);

	newImage.loadFromFile("0_Citizen_Walk_015.png");
	m_enemyAnime.push_back(newImage);

	newImage.loadFromFile("0_Citizen_Walk_016.png");
	m_enemyAnime.push_back(newImage);

	newImage.loadFromFile("0_Citizen_Walk_017.png");
	m_enemyAnime.push_back(newImage);

	newImage.loadFromFile("0_Citizen_Walk_018.png");
	m_enemyAnime.push_back(newImage);

	newImage.loadFromFile("0_Citizen_Walk_019.png");
	m_enemyAnime.push_back(newImage);

	newImage.loadFromFile("0_Citizen_Walk_020.png");
	m_enemyAnime.push_back(newImage);

	newImage.loadFromFile("0_Citizen_Walk_021.png");
	m_enemyAnime.push_back(newImage);

	newImage.loadFromFile("0_Citizen_Walk_022.png");
	m_enemyAnime.push_back(newImage);

	newImage.loadFromFile("0_Citizen_Walk_023.png");
	m_enemyAnime.push_back(newImage);

	newImage.loadFromFile("0_Citizen_Walk_024.png");
	m_enemyAnime.push_back(newImage);

}

sf::Texture* TextureHolder::getChangingIcon(const MovingObjTexture symbol)
{
	return &this->m_iconVec[(int)symbol];
}

sf::Texture* TextureHolder::getEnemyChangingIcon()
{
	if (this->enemyAnimetionTimer.getElapsedTime().asMilliseconds() >= 20)
	{
		if (m_enemySerialNumber >= 11)
			m_enemySerialNumber = 0;
		m_enemySerialNumber++;
		enemyAnimetionTimer.restart();
	}
	return &this->m_enemyAnime[m_enemySerialNumber];
}

