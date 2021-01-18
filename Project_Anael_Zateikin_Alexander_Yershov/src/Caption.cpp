#pragma once
#include "Caption.h"
#include "TextureHolder.h"


Caption::Caption() : m_level(0), m_score(0), m_stageTime(10), m_timelessLevel(false)
{
	this->m_scoreText.setFont(*TextureHolder::instance().getFont());
	this->m_scoreText.setCharacterSize(CAP_CHAR_SIZE);
	this->m_scoreText.setPosition(BUFF_DISTANCE, WINDOW_HEIGHT + BUFF_DISTANCE);
	this->m_scoreText.setColor(sf::Color::Green);
	this->m_scoreText.setOutlineColor(sf::Color::Magenta);
	this->m_scoreText.setOutlineThickness(CAP_OUTLINE_THICKNESS);
	updateScore(m_score);

	this->m_levelText.setFont(*TextureHolder::instance().getFont());
	this->m_levelText.setCharacterSize(CAP_CHAR_SIZE);
	this->m_levelText.setPosition(BUFF_DISTANCE + WINDOW_WIDTH / 3, WINDOW_HEIGHT + BUFF_DISTANCE);
	this->m_levelText.setColor(sf::Color::Green);
	this->m_levelText.setOutlineColor(sf::Color::Magenta);
	this->m_levelText.setOutlineThickness(CAP_OUTLINE_THICKNESS);

	this->m_stageTimeText.setFont(*TextureHolder::instance().getFont());
	this->m_stageTimeText.setCharacterSize(CAP_CHAR_SIZE);
	this->m_stageTimeText.setPosition(BUFF_DISTANCE + WINDOW_WIDTH / 3 * 2, WINDOW_HEIGHT + BUFF_DISTANCE);
	this->m_stageTimeText.setColor(sf::Color::Green);
	this->m_stageTimeText.setOutlineColor(sf::Color::Magenta);
	this->m_stageTimeText.setOutlineThickness(CAP_OUTLINE_THICKNESS);
	
	this->m_musicIcon.setTexture(*TextureHolder::instance().getMusicIcon(true));
	this->m_musicIcon.setPosition(WINDOW_WIDTH - MUSIC_ICON_POS, WINDOW_HEIGHT + CAPTION_HEIGHT - MUSIC_ICON_POS);
	this->m_musicIcon.scale(0.07, 0.07);

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

void Caption::updateLevel(float time)
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
	//m_timelessLevel = false;
	this->m_Timer.restart();
}

void Caption::updateScore(int addedScore)
{
	this->m_score += addedScore;
	this->m_scoreText.setString("Score:" + std::to_string(this->m_score));
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


void Caption::draw(sf::RenderWindow& window)
{
	updateTime(0);
	window.draw(this->m_scoreText);
	window.draw(this->m_levelText);
	window.draw(this->m_stageTimeText);
	window.draw(this->m_musicIcon);
}

void Caption::resetLevel(float stageTime)
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
	this->m_musicIcon.setTexture(*TextureHolder::instance().getMusicIcon(isSoundOn));
}
