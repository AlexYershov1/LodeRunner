#include "movingInclude/DumbEnemy.h"

DumbEnemy::~DumbEnemy()
{
}

void DumbEnemy::move(sf::Time& clock)
{
	this->m_direction = (Direction)(rand() % 4);
	Enemy::move(clock);
}
