#pragma once
#pragma warning (disable : 4996)
#include "Caption.h"
#include "resourcesManager.h"


Caption::Caption() : m_level(0), m_score(0), m_stageTime(10), m_timelessLevel(false)
{
	this->m_scoreText.setFont(*resourcesManager::instance().getFont());
	this->m_scoreText.setCharacterSize(CAP_CHAR_SIZE);
	this->m_scoreText.setPosition(BUFF_DISTANCE, WINDOW_HEIGHT + BUFF_DISTANCE);
	this->m_scoreText.setColor(sf::Color::Green);
	this->m_scoreText.setOutlineColor(sf::Color::Magenta);
	this->m_scoreText.setOutlineThickness(CAP_OUTLINE_THICKNESS);
	updateScore(m_score);

	this->m_levelText.setFont(*resourcesManager::instance().getFont());
	this->m_levelText.setCharacterSize(CAP_CHAR_SIZE);
	this->m_levelText.setPosition(BUFF_DISTANCE + WINDOW_WIDTH / 4, WINDOW_HEIGHT + BUFF_DISTANCE);
	this->m_levelText.setColor(sf::Color::Green);
	this->m_levelText.setOutlineColor(sf::Color::Magenta);
	this->m_levelText.setOutlineThickness(CAP_OUTLINE_THICKNESS);

	this->m_livesText.setFont(*resourcesManager::instance().getFont());
	this->m_livesText.setCharacterSize(CAP_CHAR_SIZE);
	this->m_livesText.setPosition(BUFF_DISTANCE + WINDOW_WIDTH / 4 * 2, WINDOW_HEIGHT + BUFF_DISTANCE);
	this->m_livesText.setColor(sf::Color::Green);
	this->m_livesText.setOutlineColor(sf::Color::Magenta);
	this->m_livesText.setOutlineThickness(CAP_OUTLINE_THICKNESS);
	updateLife(NUM_OF_LIVES);

	this->m_stageTimeText.setFont(*resourcesManager::instance().getFont());
	this->m_stageTimeText.setCharacterSize(CAP_CHAR_SIZE);
	this->m_stageTimeText.setPosition(BUFF_DISTANCE + WINDOW_WIDTH / 4 * 3, WINDOW_HEIGHT + BUFF_DISTANCE);
	this->m_stageTimeText.setColor(sf::Color::Green);
	this->m_stageTimeText.setOutlineColor(sf::Color::Magenta);
	this->m_stageTimeText.setOutlineThickness(CAP_OUTLINE_THICKNESS);
	
	this->m_musicIcon.setTexture(*resourcesManager::instance().getMusicIcon(true));
	this->m_musicIcon.setPosition(WINDOW_WIDTH - MUSIC_ICON_POS, WINDOW_HEIGHT + CAPTION_HEIGHT - MUSIC_ICON_POS);
	this->m_musicIcon.scale(MUSIC_ICON_SCALE);

}

Caption::~Caption()
{
}

void Caption::updateTime(float time)
{
	
	if (!m_timelessLevel)
	{
		this->m_stageTime += time;
		this->m_stageTime -= this->m_Timer.getElapsedTime().asSeconds();

		this->m_stageTimeText.setString("Time left: " + std::to_string((int)this->m_stageTime));
		

		this->m_Timer.restart();
	}
}

void Caption::updateLevel(int time)
{
	if (time == -1)
	{
		m_timelessLevel = true;
		this->m_stageTimeText.setString("Time left: ----");
		this->m_stageTime++;
	}
	else
		m_stageTime = time;
	this->m_level++;
	this->m_levelText.setString("Level:" + std::to_string(this->m_level));
	this->m_Timer.restart();
}

void Caption::updateScore(int addedScore)
{
	this->m_score += addedScore;
	this->m_scoreText.setString("Score:" + std::to_string(this->m_score));
}

void Caption::updateLife(int lifeLeft)
{
	this->m_livesText.setString("Lives:" + std::to_string(lifeLeft));
}

int Caption::getLvl() const
{
	return this->m_level;
}

float Caption::getTime() const
{
	if (m_timelessLevel)
		return 1; 

	return this->m_stageTime;
}

void Caption::resetLvl()
{
	m_Timer.restart();
}

void Caption::resetTime(int time)
{
	m_stageTime = time;
}


void Caption::draw(sf::RenderWindow& window)
{
	updateTime(0);
	window.draw(this->m_scoreText);
	window.draw(this->m_levelText);
	window.draw(this->m_livesText);
	window.draw(this->m_stageTimeText);
	window.draw(this->m_musicIcon);
}

void Caption::resetLevelNum()
{
	m_level = 0;
	//updateLevel(stageTime);
}

void Caption::setTimelessOff()
{
	this->m_timelessLevel = false;
}

void Caption::resetScore()
{
	m_score = 0;
	updateScore(0);
}

bool Caption::MusicIconContains(const sf::Event& evnt) const
{
	if (this->m_musicIcon.getGlobalBounds().contains(evnt.mouseButton.x, evnt.mouseButton.y))
		return true;
	return false;
}

void Caption::setMusicIcon(bool isSoundOn)
{
	this->m_musicIcon.setTexture(*resourcesManager::instance().getMusicIcon(isSoundOn));
}
