#pragma once
#include "StaticObject.h"

class Bonus : public StaticObject
{
public:
	Bonus(Elements, const sf::Vector2f&, int, int);
	virtual ~Bonus() {};

	virtual void handleCollision(Enemy&, Controller&) override {};
private:

};

