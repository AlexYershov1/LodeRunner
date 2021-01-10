#pragma once
#include "Enemy.h"

class SmartEnemy : public Enemy
{
public:
	using Enemy::Enemy;
	~SmartEnemy();
	virtual void move(sf::Time&) override;
	virtual void handleCollision(Ladder&, Controller&) override;
private:
	Direction m_prevDirection = Direction::Left;
};