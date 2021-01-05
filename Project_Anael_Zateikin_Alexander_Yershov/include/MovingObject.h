#pragma once
#include "GameObject.h"
#include "Macros.h"

class MovingObject : public GameObject
{
public:
	MovingObject(const sf::Texture*, const sf::Vector2f&, int, int);
	~MovingObject();

	virtual void move(sf::Time) = 0;
protected:
	float m_speed; //speed per second
	sf::Vector2f m_respawnLocation;

};
