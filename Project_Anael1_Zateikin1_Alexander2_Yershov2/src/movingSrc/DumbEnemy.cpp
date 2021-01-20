#include "movingInclude/DumbEnemy.h"

DumbEnemy::~DumbEnemy()
{
}

//this enemy changes its direction randomly after a constant anount of seconds
void DumbEnemy::move(sf::Time& clock)
{
	if (m_changeDircectionAlarm.getElapsedTime().asSeconds() > DELTA_TIME)
	{
		
		this->m_direction = DirectionVec[(rand() % 2)];

		m_changeDircectionAlarm.restart();
	}
	Enemy::move(clock);
}