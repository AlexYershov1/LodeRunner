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
		{
			if (m_direction != Direction::Left)
			{
				//m_icon.scale(-1, 1);
				//m_prevPos.x += m_icon.getGlobalBounds().width;      //to correct the previous location after mirroring the sprite
				//m_icon.move(m_icon.getGlobalBounds().width, 0);
			}
				
			m_direction = Direction::Left;
		}
		else
		{
			if (m_direction != Direction::Right)
			{
				//m_icon.scale(-1, 1);
				//m_prevPos.x -= m_icon.getGlobalBounds().width;  //to correct the previous location after mirroring the sprite
				//m_icon.move(-m_icon.getGlobalBounds().width, 0);
			}
			
			m_direction = Direction::Right;
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
			if (m_direction != Direction::Down && m_direction != Direction::Up)
				m_prevDirection = m_direction;
			m_icon.setTexture(*TextureHolder::instance().getChangingIcon(MovingObjTexture::enemyClimbingIcon));
			if (Player::plyLocation.y > this->getPos().y) // player is underneath me
				this->m_direction = Direction::Down;
			else if (Player::plyLocation.y < this->getPos().y) // player is above me
				this->m_direction = Direction::Up;
		}
		if (this->getPos() == this->m_prevPos)	// stuck in ladder
		{
			this->m_icon.move(0, -1);
			this->m_direction = this->m_prevDirection;
		}
	}

	//if (std::abs(ladder.Center().x - this->centerDown().x) < SIGMA + 50)
	//{
	//	m_icon.setTexture(*TextureHolder::instance().getChangingIcon(MovingObjTexture::enemyClimbingIcon));

	//	if (m_direction != Direction::Down && m_direction != Direction::Up)
	//		m_prevDirection = m_direction;

	//	if (Player::plyLocation.y > this->getPos().y) // player is underneath me
	//		this->m_direction = Direction::Down;

	//	else if (Player::plyLocation.y < this->getPos().y) // player is above me
	//		this->m_direction = Direction::Up;

	//	this->m_icon.setPosition(ladder.getPos().x, this->getPos().y);
	//}
}