#pragma once
#include "MovingObject.h"
#include "Macros.h"

class Enemy : public MovingObject
{
public:
	Enemy(const sf::Texture*, const sf::Vector2f&, int, int);
	~Enemy();
	void move(sf::Time&) override;
	virtual void handleCollision(const GameObject&) override {};
	virtual void handleCollision(const Wall&) override;
	virtual void handleCollision(const Player&) override {/*do stuff*/};
	virtual void handleCollision(const Enemy&) override {};
	virtual void handleCollision(const Bar&) override {/*do stuff*/};
	virtual void handleCollision(const Ladder&) override {/*do stuff*/};
	virtual void handleCollision(const Coin&) override {};
	virtual void handleCollision(const Bonus&) override {};
	
protected:
	Direction m_direction = Direction::Left;	// direction of movement
};