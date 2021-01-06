#pragma once
#include "MovingObject.h"
#include "Macros.h"

class Enemy : public MovingObject
{
public:
	Enemy(const sf::Texture*, const sf::Vector2f&, int, int);
	~Enemy();
	void move(sf::Time&) override;
	virtual void handleCollision(GameObject&) override;
	virtual void handleCollision(Wall&) override;
	virtual void handleCollision(Player&) override;
	virtual void handleCollision(Enemy&) override {};
	virtual void handleCollision(Bar&) override {/*do stuff*/};
	virtual void handleCollision(Ladder&) override {/*do stuff*/};
	virtual void handleCollision(Coin&) override {};
	virtual void handleCollision(Bonus&) override {};
	
protected:
	Direction m_direction = Direction::Left;	// direction of movement
};