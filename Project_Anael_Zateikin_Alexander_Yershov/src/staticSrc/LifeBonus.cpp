#include "staticInclude/LifeBonus.h"




LifeBonus::~LifeBonus()
{
}

void LifeBonus::handleCollision(Player& ply, Controller& game)
{
	ply.increaseLife();
}
