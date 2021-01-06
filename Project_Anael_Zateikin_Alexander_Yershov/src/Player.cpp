#include "Player.h"
#include "Macros.h"

Player::Player(const sf::Texture* icon, const sf::Vector2f& position, int mapW, int mapH)
	: MovingObject(icon, position, mapW, mapH), m_life(NUM_OF_LIVES)
{
}


Player::~Player()
{
}

void Player::decreaseLife()
{
	this->m_life--;
}

void Player::move(sf::Time& clock)
{
	return;
}

void Player::handleCollision(GameObject&) 
{

}

void Player::handleCollision(Wall&)
{

}
