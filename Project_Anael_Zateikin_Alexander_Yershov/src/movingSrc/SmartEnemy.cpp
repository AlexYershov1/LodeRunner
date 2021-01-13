#include "movingInclude/SmartEnemy.h"
#include "movingInclude/Player.h"
#include "staticInclude/Ladder.h"

SmartEnemy::~SmartEnemy()
{
}

void SmartEnemy::move(sf::Time& clock)
{
	if (std::abs(Player::plyLocation.y - this->getPos().y) > SIGMA) // player is not at the same level as me
	{
		if (m_direction == Direction::Down || m_direction == Direction::Up)	// found a ladder
		{
			if (this->getPos() == m_prevPos) // stuck
				m_direction = m_prevDirection;	// continue sideways (look for ladder)
		}
	}
	else
	{
		if (Player::plyLocation.x < this->getPos().x)	// player is to the left of me
			m_direction = Direction::Left;
		else
			m_direction = Direction::Right;
	}
	Enemy::move(clock);
}

void SmartEnemy::handleCollision(Ladder& ladder, Controller&)
{
	if (this->contains(ladder.Center()))
		m_icon.setTexture(*TextureHolder::instance().getChangingIcon(MovingObjTexture::enemyClimbingIcon));
	
	if (m_direction != Direction::Down && m_direction != Direction::Up)
		m_prevDirection = m_direction;

	if (Player::plyLocation.y > this->getPos().y) // player is underneath me
		this->m_direction = Direction::Down;
	else if (Player::plyLocation.y < this->getPos().y) // player is above me
		this->m_direction = Direction::Up;
}
