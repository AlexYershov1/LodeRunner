#include "staticInclude/Coin.h"
#include "Controller.h"

Coin::Coin(Elements symbol, const sf::Vector2f& position, int mapW, int mapH)
	:StaticObject(symbol, position, mapW, mapH)
{
}

Coin::~Coin()
{
}

void Coin::handleCollision(Player&, Controller& game)
{
	game.eraseObject(*this);
	game.increaseScore();
}