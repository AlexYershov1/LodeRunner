#include "movingInclude/DumbEnemy.h"

DumbEnemy::~DumbEnemy()
{
}

void DumbEnemy::move(sf::Time& clock)
{
	if (m_changeDircectionAlarm.getElapsedTime().asSeconds() > 5)
	{
		auto prevd = m_direction;
		this->m_direction = (Direction)(rand() % 2);

		if (this->m_direction != prevd)
			this->m_icon.scale(-1, 1);

		m_changeDircectionAlarm.restart();
	}
	Enemy::move(clock);
}
