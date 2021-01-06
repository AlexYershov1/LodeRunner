#pragma once
#include "GameObject.h"
//#include <vector>
//#include "TextureHolder.h"

class MovingObject : public GameObject
{
public:
	MovingObject(const sf::Texture*, const sf::Vector2f&, int, int, std::vector<sf::Texture*>&);
	virtual ~MovingObject() = 0;

	

	virtual void move(sf::Time&) = 0;
protected:
	//float m_speed; //speed per second
	sf::Vector2f m_respawnLocation;
	std::vector<sf::Texture*> m_iconArsenal;
};
