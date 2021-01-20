#pragma once
#include "StaticObject.h"

class Coin : public StaticObject
{
public:
	Coin(Elements, const sf::Vector2f&, int, int);
	~Coin();
	virtual void handleCollision(Player&, Controller&) override;
	virtual void handleCollision(Enemy&, Controller&) override {};
};