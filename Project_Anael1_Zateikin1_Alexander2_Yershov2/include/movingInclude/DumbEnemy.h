#pragma once
#include "Enemy.h"

class DumbEnemy : public Enemy
{
public:
	using Enemy::Enemy;
	~DumbEnemy();

	virtual void move(sf::Time&) override;
private:
	sf::Clock m_changeDircectionAlarm;
};