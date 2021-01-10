#include "movingInclude/DumbEnemy.h"

DumbEnemy::~DumbEnemy()
{
}

void DumbEnemy::move(sf::Time& clock)
{
	if (m_changeDircectionAlarm.getElapsedTime().asSeconds() > 3)
	{
		this->m_direction = (Direction)(rand() % 2);
		m_changeDircectionAlarm.restart();
	}
	Enemy::move(clock);
}
