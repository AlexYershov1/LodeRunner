#include "staticInclude/Ladder.h"

Ladder::Ladder(Elements symbol, const sf::Vector2f& position, int mapW, int mapH)
	: StaticObject(symbol, position, mapW, mapH)
{
	this->m_icon.move(0, -2);
}

Ladder::~Ladder()
{
}

void Ladder::handleCollision(Player& ply, Controller& game)
{
	ply.handleCollision(*this, game);
}

void Ladder::handleCollision(Enemy& enemy, Controller& game)
{
	enemy.handleCollision(*this, game);
}
