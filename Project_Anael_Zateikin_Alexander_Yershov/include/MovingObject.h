#pragma once
#include "GameObject.h"
#include "Macros.h"

class MovingObject : public GameObject
{
public:
	MovingObject(const sf::Texture*, const sf::Vector2f&);
	~MovingObject();

	virtual void move() = 0;
protected:
	float m_speed; //speed per second
	sf::Vector2f m_respawnLocation;

};
