#pragma once
#include "GameObject.h"

class StaticObject : public GameObject
{
public:
	StaticObject(const sf::Texture*, const sf::Vector2f&, int, int);
	~StaticObject();

	
	virtual void handleCollision(GameObject&) override {};
	virtual void handleCollision(Wall&) override {};
	virtual void handleCollision(Player&) override {};
	virtual void handleCollision(Enemy&) override {};
	virtual void handleCollision(Bar&) override {};
	virtual void handleCollision(Ladder&) override {};
	virtual void handleCollision(Coin&) override {};
	virtual void handleCollision(Bonus&) override {};
	
protected:

private:
	
};

