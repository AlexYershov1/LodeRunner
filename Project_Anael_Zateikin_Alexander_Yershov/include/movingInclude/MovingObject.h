#pragma once
#include "GameObject.h"
//#include <vector>
//#include "TextureHolder.h"
class Floor;
class Controller;

class MovingObject : public GameObject
{
public:
	MovingObject(Elements, const sf::Vector2f&, int, int);
	virtual ~MovingObject() = 0;

	void fall(const sf::Time&);
	virtual void move(sf::Time&) = 0;
	sf::Vector2f getRespawnLocation() const;

	//virtual void handleCollision(GameObject&, Controller&) override;
	//virtual void handleCollision(Floor&, Controller&) override;
	const sf::Vector2f centerDown() const;
	void moveToPrevPos();

protected:
	//float m_speed; //speed per second
	sf::Vector2f m_respawnLocation;
	sf::Vector2f m_prevPos;
	
	bool outOfBounds(const sf::Vector2f&) const;
};
