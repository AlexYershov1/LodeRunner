#include "staticInclude/LifeBonus.h"
#include "Controller.h"



LifeBonus::~LifeBonus()
{
}

void LifeBonus::handleCollision(Player& ply, Controller& game)
{
	ply.increaseLife();
	game.eraseObject(*this);
	ply.handleCollision(*this, game);
}
