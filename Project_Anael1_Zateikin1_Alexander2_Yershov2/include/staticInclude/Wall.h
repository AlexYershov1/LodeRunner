#pragma once
#include "StaticObject.h"

class Wall : public StaticObject
{
public:
	using StaticObject::StaticObject;
	//Wall(const sf::Texture*, const sf::Vector2f&, int, int);
	~Wall();
	virtual void handleCollision(Player&, Controller&) override;
	virtual void handleCollision(Enemy&, Controller&) override;

private:

};
