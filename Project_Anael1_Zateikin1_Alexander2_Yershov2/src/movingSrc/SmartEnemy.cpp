#include "movingInclude/SmartEnemy.h"
#include "movingInclude/Player.h"
#include "staticInclude/Ladder.h"
#include "staticInclude/Floor.h"
#include "Controller.h"


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

void SmartEnemy::handleCollision(Ladder& ladder, Controller& game)
{
	auto sigma = game.getStaticIconInfo(GET_WIDTH) / (SIGMA + 1); 

	if (std::abs(ladder.Center().x - this->centerDown().x) < sigma) //if close to the center of the ladder
	{
		if (std::abs(Player::plyLocation.y - this->getPos().y) > sigma)	//if player is not on the same level as enemy
		{
			m_icon.setTexture(*resourcesManager::instance().getChangingIcon(MovingObjTexture::enemyClimbingIcon));

			if (m_direction != DirectionVec[(int)Direction::Down] && m_direction != DirectionVec[(int)Direction::Up])
				m_prevDirection = m_direction;																	
			
			if (Player::plyLocation.y > this->getPos().y) // player is underneath me
				this->m_direction = DirectionVec[(int)Direction::Down];
			else if (Player::plyLocation.y < this->getPos().y) // player is above me
				this->m_direction = DirectionVec[(int)Direction::Up];
		}
		
		if (this->getPos() == this->m_prevPos)	// stuck in ladder
		{
			this->m_icon.move(0, -1);			//lift up
			this->m_direction = this->m_prevDirection;
		}	
	}
}

void SmartEnemy::handleCollision(Floor& floor, Controller&)
{
	if (!floor.contains(this->centerDown()) && !(m_prevPos.y < getPos().y))  //if not after fall
	 //collision from side
	{
		if ((floor.getPos().y - this->centerDown().y) < 1.0f && //close to top
			m_prevPos.y == this->getPos().y)  //not after fall
		{
			m_prevPos = this->getPos();
			m_icon.move(0, -1); //move one pixel up
		}
		else if (m_direction == DirectionVec[(int)Direction::Right])
		{
			//check if should save old direction
			m_prevDirection = m_direction;
			m_direction = DirectionVec[(int)Direction::Left];
			this->moveToPrevPos();			
		}
		else if (m_direction == DirectionVec[(int)Direction::Left])
		{
			m_prevDirection = m_direction;
			m_direction = DirectionVec[(int)Direction::Right];
			this->moveToPrevPos();			
		}
	}
	else if (floor.contains(this->centerDown()) && (m_prevPos.y == getPos().y)) //stuck inside a floor
	{
		m_icon.setPosition(this->getPos().x, floor.getPos().y - 1.0f - this->getIconHeight()); //move above floor
	}
	else 
		this->moveToPrevPos(); //case of after falling
}
