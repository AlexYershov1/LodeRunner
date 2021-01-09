#include "movingInclude/Enemy.h"
#include "movingInclude/Player.h"
#include "Controller.h"

Enemy::Enemy(Elements symbol, const sf::Vector2f& position, int mapW, int mapH)
	: MovingObject(symbol, position, mapW, mapH), m_direction(Direction::Left)
{
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
}

void Enemy::handleCollision(GameObject& obj, Controller& game)
{
	obj.handleCollision(*this, game);
}

void Enemy::handleCollision(Wall& NO_USE, Controller& game)
{
	m_icon.setPosition(m_prevPos);
	if (m_direction == Direction::Left)
		m_direction = Direction::Right;
	else
		m_direction = Direction::Left;

	this->m_icon.scale(-1, 1);	// flipIcon();
}

void Enemy::handleCollision(Floor&, Controller&)
{
	//m_icon.setPosition(m_prevPos);
	m_icon.move({ 0,-0.1 });
	// TODO BOM
}

void Enemy::handleCollision(Player& ply, Controller& game)
{
	ply.decreaseLife();
	//game.restartLevel();
}

void Enemy::handleCollision(Bar& barObj, Controller& game)
{
	m_icon.setTexture(*TextureHolder::instance().getChangingIcon(MovingObjTexture::charOnBarIcon));
}

void Enemy::handleCollision(Ladder& ladderObj, Controller& game)
{
	m_icon.setTexture(*TextureHolder::instance().getChangingIcon(MovingObjTexture::enemyClimbingIcon));
}
