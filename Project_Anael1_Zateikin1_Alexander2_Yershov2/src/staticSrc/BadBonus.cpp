#include "staticInclude/BadBonus.h"
#include "Controller.h"


BadBonus::~BadBonus()
{
}

void BadBonus::handleCollision(Player& ply, Controller& game)
{
	game.addEnemy();
	game.eraseObject(*this); //remove from statics vector
	ply.handleCollision(*this, game);
}
