#pragma once
#include "Caption.h"
#include "TextureHolder.h"


Caption::Caption() : m_level(0), m_score(0), m_stageTime(0)
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
	updateLevel();

	this->m_stageTimeText.setFont(*TextureHolder::instance().getFont());
	this->m_stageTimeText.setCharacterSize(CAP_CHAR_SIZE);
	this->m_stageTimeText.setPosition(BUFF_DISTANCE + WINDOW_WIDTH / 3 * 2, WINDOW_HEIGHT + BUFF_DISTANCE);
	this->m_stageTimeText.setColor(sf::Color::Green);
	this->m_stageTimeText.setOutlineColor(sf::Color::Magenta);
	this->m_stageTimeText.setOutlineThickness(CAP_OUTLINE_THICKNESS);
	updateTime(m_stageTime);
}

Caption::~Caption()
{
}

void Caption::updateTime(float time)
{
	this->m_stageTime += time;
	this->m_stageTime -= this->m_Timer.getElapsedTime().asSeconds();

	this->m_stageTimeText.setString("Time left: " + std::to_string((int)this->m_stageTime));
	this->m_Timer.restart();
}

void Caption::updateLevel()
{
	this->m_level++;
	this->m_levelText.setString("Level:" + std::to_string(this->m_level));
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

void Caption::resetLvl()
{
	m_Timer.restart();
}

void Caption::newLevel(float time)
{
	this->m_level++;
	m_stageTime = time;
}

void Caption::draw(sf::RenderWindow& window)
{
	updateTime(0);
	window.draw(this->m_scoreText);
	window.draw(this->m_levelText);
	window.draw(this->m_stageTimeText);
}
