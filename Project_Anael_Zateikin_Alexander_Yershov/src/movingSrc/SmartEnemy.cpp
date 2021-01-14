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
		if (m_direction == DirectionVec[(int)Direction::Down] || m_direction == DirectionVec[(int)Direction::Up])	// found a ladder
		{
			if (this->getPos() == m_prevPos) // stuck
				m_direction = m_prevDirection;	// continue sideways (look for ladder)
		}
	}
	else
	{
		if (Player::plyLocation.x < this->getPos().x)	// player is to the left of me
		{		
			m_direction = DirectionVec[(int)Direction::Left];
		}
		else
		{	
			m_direction = DirectionVec[(int)Direction::Right];
		}
			
	}
	Enemy::move(clock);
}

void SmartEnemy::handleCollision(Ladder& ladder, Controller&)
{
	if (std::abs(ladder.Center().x - this->centerDown().x) < SIGMA + 50)
	{
		if (std::abs(Player::plyLocation.y - this->getPos().y) > SIGMA)
		{
			if (m_direction != DirectionVec[(int)Direction::Down] && m_direction != DirectionVec[(int)Direction::Up])
				m_prevDirection = m_direction;
			m_icon.setTexture(*TextureHolder::instance().getChangingIcon(MovingObjTexture::enemyClimbingIcon));
			if (Player::plyLocation.y > this->getPos().y) // player is underneath me
				this->m_direction = DirectionVec[(int)Direction::Down];
			else if (Player::plyLocation.y < this->getPos().y) // player is above me
				this->m_direction = DirectionVec[(int)Direction::Up];
		}
		if (this->getPos() == this->m_prevPos)	// stuck in ladder
		{
			this->m_icon.move(0, -1);
			this->m_direction = this->m_prevDirection;
		}
	}
}