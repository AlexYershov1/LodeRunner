#pragma once
#include "resourcesManager.h"

resourcesManager::resourcesManager() : m_enemySerialNumber(0), m_playerIconSerialNum(0)
{
	setImagesForObj();
	createSwitchingIcons();
	createEnemySwitchingIcons();
	createPlayerSwitchingIcons();
	createAudio();
	createMusicIcon();
	createBackgrounds();
}

resourcesManager::~resourcesManager()
{
}

resourcesManager& resourcesManager::instance()
{
	static resourcesManager inst;
	return inst;
}

// load all the object images
void resourcesManager::setImagesForObj()
{
	sf::Texture newImage;

	newImage.loadFromFile("bar.png");
	m_textures.push_back(newImage);

	newImage.loadFromFile("coin.png");
	m_textures.push_back(newImage);

	newImage.loadFromFile("0_Citizen_Walk_013.png");
	m_textures.push_back(newImage);

	newImage.loadFromFile("playerFront.png"); 
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

sf::Texture* resourcesManager::getIcon(const Elements symbol)
{
	return &this->m_textures[(int)symbol];
}

void resourcesManager::createSwitchingIcons()
{
	
	sf::Texture newImage;

	m_iconVec.push_back(this->m_textures[(int)Elements::player]);
	m_iconVec.push_back(this->m_textures[(int)Elements::enemy]);

	newImage.loadFromFile("playerBack.png");
	m_iconVec.push_back(newImage);

	newImage.loadFromFile("enemyBack.png");
	m_iconVec.push_back(newImage);

	newImage.loadFromFile("barClimbing.png");
	m_iconVec.push_back(newImage);
}

void resourcesManager::createEnemySwitchingIcons()
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

	newImage.loadFromFile("0_Citizen_Walk_025.png");
	m_enemyAnime.push_back(newImage);

}

void resourcesManager::createPlayerSwitchingIcons()
{
	sf::Texture newImage;

	newImage.loadFromFile("0_Warrior_Run_000.png");
	m_playerAnime.push_back(newImage);

	newImage.loadFromFile("0_Warrior_Run_001.png");
	m_playerAnime.push_back(newImage);

	newImage.loadFromFile("0_Warrior_Run_002.png");
	m_playerAnime.push_back(newImage);

	newImage.loadFromFile("0_Warrior_Run_003.png");
	m_playerAnime.push_back(newImage);

	newImage.loadFromFile("0_Warrior_Run_004.png");
	m_playerAnime.push_back(newImage);

	newImage.loadFromFile("0_Warrior_Run_005.png");
	m_playerAnime.push_back(newImage);

	newImage.loadFromFile("0_Warrior_Run_006.png");
	m_playerAnime.push_back(newImage);

	newImage.loadFromFile("0_Warrior_Run_007.png");
	m_playerAnime.push_back(newImage);

	newImage.loadFromFile("0_Warrior_Run_008.png");
	m_playerAnime.push_back(newImage);

	newImage.loadFromFile("0_Warrior_Run_009.png");
	m_playerAnime.push_back(newImage);

	newImage.loadFromFile("0_Warrior_Run_010.png");
	m_playerAnime.push_back(newImage);

	newImage.loadFromFile("0_Warrior_Run_011.png");
	m_playerAnime.push_back(newImage);

	newImage.loadFromFile("0_Warrior_Run_012.png");
	m_playerAnime.push_back(newImage);
}

void resourcesManager::createAudio()
{
	sf::SoundBuffer newSound;

	newSound.loadFromFile("bonusSound.wav");
	m_audioVec.push_back(newSound);

	newSound.loadFromFile("strikeSound.wav");
	m_audioVec.push_back(newSound);

	newSound.loadFromFile("winSound.wav");
	m_audioVec.push_back(newSound);

	newSound.loadFromFile("backgroundMusic.ogg");
	m_audioVec.push_back(newSound);
}

void resourcesManager::createMusicIcon()
{
	sf::Texture newImage;

	newImage.loadFromFile("musicOn.png");
	m_musicTextureVec.push_back(newImage);

	newImage.loadFromFile("musicOff.png");
	m_musicTextureVec.push_back(newImage);
}

void resourcesManager::createBackgrounds()
{
	sf::Texture newImage;

	newImage.loadFromFile("background1.jpg");
	m_backgroundVec.push_back(newImage);

	newImage.loadFromFile("background2.png");
	m_backgroundVec.push_back(newImage);
}

sf::Texture* resourcesManager::getChangingIcon(const MovingObjTexture symbol)
{
	return &this->m_iconVec[(int)symbol];
}

//to create the "run" effect
sf::Texture* resourcesManager::getEnemyChangingIcon()
{
	if (this->enemyAnimetionTimer.getElapsedTime().asMilliseconds() >= 20)
	{
		if (m_enemySerialNumber >= 12)
			m_enemySerialNumber = 0;
		m_enemySerialNumber++;
		enemyAnimetionTimer.restart();
	}
	return &this->m_enemyAnime[m_enemySerialNumber];
}

sf::Texture* resourcesManager::getPlayerRunningIcon()
{
	if (this->playerAnimationTimer.getElapsedTime().asMilliseconds() >= 20)
	{
		if (m_playerIconSerialNum >= 12)
			m_playerIconSerialNum = 0;
		m_playerIconSerialNum++;
		playerAnimationTimer.restart();
	}
	return &this->m_playerAnime[m_playerIconSerialNum];
}

sf::SoundBuffer* resourcesManager::getSound(Recording record)
{
	return &this->m_audioVec[(int)record];
}

sf::Texture* resourcesManager::getMusicIcon(bool soundOn)
{
	if (soundOn)
		return &this->m_musicTextureVec[0];
	else
		return &this->m_musicTextureVec[1];
}

const sf::Texture* resourcesManager::getbackGround(bool isFirstBG)
{
	if (isFirstBG)
		return &this->m_backgroundVec[0];
	else
		return &this->m_backgroundVec[1];
}

sf::Font* resourcesManager::getFont()
{
	return &this->m_font;
}

