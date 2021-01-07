#pragma once
#include "StaticObject.h"

class Wall : public StaticObject
{
public:
	using StaticObject::StaticObject;
	//Wall(const sf::Texture*, const sf::Vector2f&, int, int);
	~Wall();

private:

};
