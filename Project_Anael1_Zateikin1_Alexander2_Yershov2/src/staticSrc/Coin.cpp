#include "staticInclude/Coin.h"
#include "Controller.h"

//int Coin::coinsLeft = 0;

Coin::Coin(Elements symbol, const sf::Vector2f& position, int mapW, int mapH)
	:StaticObject(symbol, position, mapW, mapH)
{
	//coinsLeft++;
}

Coin::~Coin()
{
	//coinsLeft--;
}

void Coin::handleCollision(Player&, Controller& game)
{
	game.eraseObject(*this);
	game.increaseScore();
}
/*
//returns true if at least one coin still exists
bool Coin::checkCoinsStatus()
{
	return coinsLeft > 0 ; 
}
*/
