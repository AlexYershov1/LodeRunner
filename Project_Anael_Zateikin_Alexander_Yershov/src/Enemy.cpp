#include "Enemy.h"

Enemy::~Enemy()
{
}

void Enemy::move()
{
	auto currPos = this->m_icon.getPosition();	// enemy position

	switch (this->m_direction)
	{
	case Direction::Left:
		this->m_icon.setPosition(currPos.x - STEP, currPos.y);
		break;
	case Direction::Right:
		this->m_icon.setPosition(currPos.x + STEP, currPos.y);
		break;
	case Direction::Down:
		this->m_icon.setPosition(currPos.x, currPos.y - STEP);
		break;
	case Direction::Up:
		this->m_icon.setPosition(currPos.x, currPos.y + STEP);
		break;
	}
}

void Enemy::handleCollision(const Wall& NO_USE)
{
	if (m_direction == Direction::Left)
		m_direction = Direction::Right;
	else
		m_direction = Direction::Left;
}