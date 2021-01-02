#pragma once
#include <SFML/Graphics.hpp>

class Wall;
class Floor;
class Player;
class Enemy;
class Bar;
class Ladder;
class Coin;
class Bonus;

class GameObject
{
public:
	GameObject();
	~GameObject();
	bool collidesWith(const GameObject&);
	virtual void handleCollision(const GameObject&) = 0;
	virtual void handleCollision(const Wall&) = 0;
	// virtual void handleCollision(const Floor&) = 0;	// maybe relevent
	virtual void handleCollision(const Player&) = 0;
	virtual void handleCollision(const Enemy&) = 0;
	virtual void handleCollision(const Bar&) = 0;
	virtual void handleCollision(const Ladder&) = 0;
	virtual void handleCollision(const Coin&) = 0;
	virtual void handleCollision(const Bonus&) = 0;
	

private:
	sf::Sprite m_icon;
};

