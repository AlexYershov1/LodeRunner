#pragma once
#include "GameObject.h"
#include "movingInclude/Player.h"
#include "movingInclude/Enemy.h"

class StaticObject : public GameObject
{
public:
	StaticObject(Elements, const sf::Vector2f&, int, int);
	~StaticObject();

	
	virtual void handleCollision(GameObject&, Controller&) override {};
	virtual void handleCollision(Wall&, Controller&) override {};
	virtual void handleCollision(Player&, Controller&) = 0;
	virtual void handleCollision(Enemy&, Controller&)  = 0;
	virtual void handleCollision(Floor&, Controller&) override {};
	virtual void handleCollision(Bar&, Controller&) override {};
	virtual void handleCollision(Ladder&, Controller&) override {};
	virtual void handleCollision(Coin&, Controller&) override {};
	virtual void handleCollision(Bonus&, Controller&) override {};
	const sf::Vector2f Center() const;
protected:

private:
	
};

