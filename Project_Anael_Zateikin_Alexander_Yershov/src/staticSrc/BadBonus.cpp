#include "staticInclude/BadBonus.h"
#include "Controller.h"


BadBonus::~BadBonus()
{
}

void BadBonus::handleCollision(Player& ply, Controller& game)
{
	game.addEnemy();
}
