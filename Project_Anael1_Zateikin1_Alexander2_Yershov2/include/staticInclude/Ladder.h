#pragma once
#include "StaticObject.h"

class Ladder : public StaticObject
{
public:
	Ladder(Elements, const sf::Vector2f&, int, int);
	~Ladder();

	virtual void handleCollision(Player&, Controller&) override;
	virtual void handleCollision(Enemy&, Controller&) override;
};