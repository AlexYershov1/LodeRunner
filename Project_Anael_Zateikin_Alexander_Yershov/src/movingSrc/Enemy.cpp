#include "movingInclude/Enemy.h"
#include "movingInclude/Player.h"
#include "Controller.h"

Enemy::Enemy(Elements symbol, const sf::Vector2f& position, int mapW, int mapH)
	: MovingObject(symbol, position, mapW, mapH), m_direction(Direction::Left)
{
	this->m_icon.scale(-1, 1);	// flipIcon();
}

Enemy::~Enemy()
{
}

void Enemy::move(sf::Time& clock)
{
	m_prevPos = m_icon.getPosition();
	// set to default icon
	m_icon.setTexture(*TextureHolder::instance().getChangingIcon(MovingObjTexture::enemyDefaultIcon));
	// set new position
	this->m_icon.move(DirectionVec[(int)this->m_direction] * BASE_SPEED * clock.asSeconds());
	if(outOfBounds(this->getPos()))
		handleBlock();
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
	//ALEX - maybe change to same as players collision with floor

	//if (this->getPos().y > m_prevPos.y) // trying to go down
	//{
	//	if (floor.contains(this->centerDown()))  // floor is underneath
	//		m_icon.setPosition(m_prevPos);
	//}
	//if (this->contains(floor.Center()))
	//	m_icon.setPosition(m_prevPos);

	if (floor.contains(m_prevPos) && floor.getPos().y < m_prevPos.y) //if the collision is underneath the floor
	{
		m_prevPos.y += 1.0f; //to avoid getting stuck inside a floor
	}

	//go back to previous location
	this->moveToPrevPos(); // <-----------> m_icon.setPosition(m_prevPos);
}

void Enemy::handleCollision(Player& ply, Controller& game)
{
	ply.decreaseLife();
	//game.restartLevel();
}

void Enemy::handleCollision(Bar&, Controller&)
{
	m_icon.setTexture(*TextureHolder::instance().getChangingIcon(MovingObjTexture::charOnBarIcon));
	if(m_direction == Direction::Up || m_direction == Direction::Down)
		this->m_icon.move(0, this->getIconHeight());
}

void Enemy::handleCollision(Ladder& ladder, Controller& game)
{
	if(this->contains(ladder.Center()))
		m_icon.setTexture(*TextureHolder::instance().getChangingIcon(MovingObjTexture::enemyClimbingIcon));
}

void Enemy::handleBlock() 
{
	m_icon.setPosition(m_prevPos);
	if (m_direction == Direction::Left)
		m_direction = Direction::Right;
	else
		m_direction = Direction::Left;

	this->m_icon.scale(-1, 1);	// flipIcon();
}
