#include "Enemy.h"
#include "Player.h"

Enemy::Enemy(const sf::Texture* icon, const sf::Vector2f& position, int mapW, int mapH, std::vector<sf::Texture*>& iconVec)
	: MovingObject(icon, position, mapW, mapH, iconVec), m_direction(Direction::Left)
{
}

Enemy::~Enemy()
{
}

void Enemy::move(sf::Time& clock)
{
	auto currPos = this->m_icon.getPosition();	// enemy position

	switch (this->m_direction)
	{
	case Direction::Left:
		this->m_icon.setPosition(currPos.x - STEP * clock.asSeconds(), currPos.y);
		break;
	case Direction::Right:
		this->m_icon.setPosition(currPos.x + STEP * clock.asSeconds(), currPos.y);
		break;
	case Direction::Down:
		this->m_icon.setPosition(currPos.x, currPos.y - STEP * clock.asSeconds());
		break;
	case Direction::Up:
		this->m_icon.setPosition(currPos.x, currPos.y + STEP * clock.asSeconds());
		break;
	}
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

	// flipIcon();
}

void Enemy::handleCollision(Player& ply)
{
	ply.decreaseLife();
}
