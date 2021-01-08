#include "staticInclude/Bonus.h"

Bonus::~Bonus()
{
}

Bonus::Bonus(Elements symbol, const sf::Vector2f& position, int mapW, int mapH)
	: StaticObject(symbol, position, mapW, mapH)
{
}
