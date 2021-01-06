#pragma once
#include "MovingObject.h"
#include "Macros.h"

class Enemy : public MovingObject
{
public:
	Enemy(const sf::Texture*, const sf::Vector2f&, int, int, std::vector<sf::Texture*>&);
	~Enemy();

	virtual void move(sf::Time&) override;

	virtual void handleCollision(GameObject&);
	virtual void handleCollision(Wall&);
	virtual void handleCollision(Player&);
	virtual void handleCollision(Enemy&) override {};
	virtual void handleCollision(Bar&) override;
	virtual void handleCollision(Ladder&);
	virtual void handleCollision(Coin&) override {};
	virtual void handleCollision(Bonus&) override {};
	
protected:
	Direction m_direction = Direction::Left;	// direction of movement
};