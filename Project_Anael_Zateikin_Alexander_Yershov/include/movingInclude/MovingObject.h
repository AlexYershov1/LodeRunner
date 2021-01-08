#pragma once
#include "GameObject.h"
//#include <vector>
//#include "TextureHolder.h"

class MovingObject : public GameObject
{
public:
	MovingObject(Elements, const sf::Vector2f&, int, int);
	virtual ~MovingObject() = 0;

	
	virtual void move(sf::Time&) = 0;
protected:
	//float m_speed; //speed per second
	sf::Vector2f m_respawnLocation;
	sf::Vector2f m_prevPos;
};
