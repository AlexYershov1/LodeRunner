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
	sf::Vector2f m_prevDirection = DirectionVec[(int)Direction::Left];
};