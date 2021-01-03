#pragma once
#include "GameObject.h"

class MovingObject : public GameObject
{
public:
	MovingObject();
	~MovingObject();

	virtual void move() = 0;
protected:
	float m_speed; //speed per second
	sf::Vector2f m_respawnLocation;

};

MovingObject::MovingObject()
{
}

MovingObject::~MovingObject()
{
}