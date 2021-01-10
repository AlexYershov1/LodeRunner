#pragma once
#include "MovingObject.h"
#include "Macros.h"

class Enemy : public MovingObject
{
public:
	Enemy(Elements, const sf::Vector2f&, int, int);
	~Enemy();

	virtual void move(sf::Time&) override;

	virtual void handleCollision(GameObject&, Controller&) override;
	virtual void handleCollision(Wall&, Controller&);
	virtual void handleCollision(Floor&, Controller&) override;
	virtual void handleCollision(Player&, Controller&);
	virtual void handleCollision(Enemy&, Controller&) override {};
	virtual void handleCollision(Bar&, Controller&) override;
	virtual void handleCollision(Ladder&, Controller&) override;
	virtual void handleCollision(Coin&, Controller&) override {};
	virtual void handleCollision(Bonus&, Controller&) override {};
	
protected:
	Direction m_direction = Direction::Left;	// direction of movement
private:
	void handleBlock();
};