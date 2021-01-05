#pragma once
#include "GameObject.h"

class StaticObject : public GameObject
{
public:
	StaticObject(const sf::Texture*, const sf::Vector2f&, int, int);
	~StaticObject();

	
	virtual void handleCollision(const GameObject&) override {};
	virtual void handleCollision(const Wall&) override {};
	virtual void handleCollision(const Player&) override {};
	virtual void handleCollision(const Enemy&) override {};
	virtual void handleCollision(const Bar&) override {};
	virtual void handleCollision(const Ladder&) override {};
	virtual void handleCollision(const Coin&) override {};
	virtual void handleCollision(const Bonus&) override {};
	
protected:

private:
	
};

