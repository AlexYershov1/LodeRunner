#pragma once
#include "StaticObject.h"

class Coin : public StaticObject
{
public:
	//using::StaticObject::StaticObject;
	Coin(Elements, const sf::Vector2f&, int, int);
	~Coin();
	virtual void handleCollision(Player&, Controller&) override;
	virtual void handleCollision(Enemy&, Controller&) override {};

	static bool checkCoinsStatus() ; //returns true if at least one coin still exists
private:
	static int coinsLeft;
};