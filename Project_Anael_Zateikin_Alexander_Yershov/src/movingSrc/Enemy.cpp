#include "movingInclude/Enemy.h"
#include "movingInclude/Player.h"

Enemy::Enemy(const sf::Texture* icon, const sf::Vector2f& position, int mapW, int mapH, std::vector<sf::Texture*>& iconVec)
	: MovingObject(icon, position, mapW, mapH, iconVec), m_direction(Direction::Left)
{
}

Enemy::~Enemy()
{
}

void Enemy::move(sf::Time& clock)
{
	// set to default icon
	m_icon.setTexture(*m_iconArsenal[(int)MovingObjTexture::enemyDefaultIcon]);
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
	m_icon.setTexture(*m_iconArsenal[(int)MovingObjTexture::charOnBarIcon]);
}

void Enemy::handleCollision(Ladder& ladderObj)
{
	m_icon.setTexture(*m_iconArsenal[(int)MovingObjTexture::enemyClimbingIcon]);
}
