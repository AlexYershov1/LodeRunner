#include "Player.h"


Player::Player(const sf::Texture* icon, const sf::Vector2f& position, int mapW, int mapH)
	: MovingObject(icon, position, mapW, mapH), m_life(NUM_OF_LIVES)
{
}


Player::~Player()
{
}

void Player::move(sf::Time)
{
	
}

void Player::handleCollision(const GameObject&) 
{

}

void Player::handleCollision(const Wall&)
{

}
