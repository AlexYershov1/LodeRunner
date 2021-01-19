#include "movingInclude/Enemy.h"
#include "movingInclude/Player.h"
#include "Controller.h"

Enemy::Enemy(Elements symbol, const sf::Vector2f& position, int mapW, int mapH)
	: MovingObject(symbol, position, mapW, mapH)	
{
	m_direction = DirectionVec[(int)Direction::Left];	// direction of movement
	m_icon.scale(0.9f, 0.9f);
}

Enemy::~Enemy()
{
}

void Enemy::move(sf::Time& clock)
{
	m_prevPos = m_icon.getPosition();

	// set to default icon
	m_icon.setTexture(*resourcesManager::instance().getEnemyChangingIcon());

	//change the scale to face the right direction
	changeToCorrectDisplay();

	// set new position
	if (this->getFall())
		m_direction = DirectionVec[(int)Direction::Down];
	this->m_icon.move(this->m_direction * BASE_SPEED * clock.asSeconds());

	if(outOfBounds())
		handleBlock();

	this->setFall(false);
}

void Enemy::handleCollision(GameObject& obj, Controller& game)
{
	obj.handleCollision(*this, game);
}

void Enemy::handleCollision(Wall&, Controller&)
{
	handleBlock();
}

void Enemy::handleCollision(Floor& floor, Controller&)
{
	if (!floor.contains(this->centerDown()) && !(m_prevPos.y < getPos().y))  //if not after fall
	 //collision from side
	{
		if ((floor.getPos().y - this->centerDown().y) < 1.0f && //close to top
			m_prevPos.y == this->getPos().y)  //not after fall
		{
			m_prevPos = this->getPos();//questionable
			m_icon.move(0, -1); //move one pixel up
		}
	}
	else if (floor.contains(this->centerDown()) && (m_prevPos.y == getPos().y))
	{
		m_icon.setPosition(this->getPos().x, floor.getPos().y - 1.0f - this->getIconHeight()); //move above floor
	}
	else
		this->moveToPrevPos(); //case of after falling

	if(m_direction == DirectionVec[(int)Direction::Down]) //if regular enemy after fall
		m_direction = DirectionVec[(int)Direction::Left];

}

void Enemy::handleCollision(Player&, Controller& game)
{
	static sf::Sound effect;
	game.strike(effect);
}

void Enemy::handleCollision(Bar&, Controller&)
{
	m_icon.setTexture(*resourcesManager::instance().getChangingIcon(MovingObjTexture::charOnBarIcon));
	if(m_direction == DirectionVec[(int)Direction::Up] || m_direction == DirectionVec[(int)Direction::Down])
		this->m_icon.move(0, this->getIconHeight());
}

void Enemy::handleCollision(Ladder& ladder, Controller&)
{
	if(this->contains(ladder.Center()))
		m_icon.setTexture(*resourcesManager::instance().getChangingIcon(MovingObjTexture::enemyClimbingIcon));
}

void Enemy::handleBlock() 
{
	m_icon.setPosition(m_prevPos);
	if (m_direction == DirectionVec[(int)Direction::Left])
		m_direction = DirectionVec[(int)Direction::Right];
	else
		m_direction = DirectionVec[(int)Direction::Left];
}
