#include "movingInclude/Enemy.h"
#include "movingInclude/Player.h"

Enemy::Enemy(Elements symbol, const sf::Vector2f& position, int mapW, int mapH)
	: MovingObject(symbol, position, mapW, mapH), m_direction(Direction::Left)
{
}

Enemy::~Enemy()
{
}

void Enemy::move(sf::Time& clock)
{
	// set to default icon
	m_icon.setTexture(*TextureHolder::instance().getChangingIcon(MovingObjTexture::enemyDefaultIcon));
	// set new position
	this->m_icon.move(DirectionVec[(int)this->m_direction] * BASE_SPEED * clock.asSeconds());
}

void Enemy::handleCollision(GameObject& obj)
{
	obj.handleCollision(*this);
}

void Enemy::handleCollision(Wall& NO_USE)
{
	if (m_direction == Direction::Left)
		m_direction = Direction::Right;
	else
		m_direction = Direction::Left;

	this->m_icon.scale(-1, 1);	// flipIcon();
}

void Enemy::handleCollision(Player& ply)
{
	ply.decreaseLife();
}

void Enemy::handleCollision(Bar& barObj)
{
	m_icon.setTexture(*TextureHolder::instance().getChangingIcon(MovingObjTexture::charOnBarIcon));
}

void Enemy::handleCollision(Ladder& ladderObj)
{
	m_icon.setTexture(*TextureHolder::instance().getChangingIcon(MovingObjTexture::enemyClimbingIcon));
}
