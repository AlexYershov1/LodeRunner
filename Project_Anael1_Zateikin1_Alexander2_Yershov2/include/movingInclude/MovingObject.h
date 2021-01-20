#pragma once
#include "GameObject.h"

class Floor;
class Controller;

class MovingObject : public GameObject
{
public:
	MovingObject(Elements, const sf::Vector2f&, int, int);
	virtual ~MovingObject() = 0;
	virtual void move(sf::Time&) = 0;

	void fall(const sf::Time&);
	sf::Vector2f getRespawnLocation() const;

	const sf::Vector2f centerDown() const;
	void moveToPrevPos();
	void changeToCorrectDisplay(); //scale right/left
	bool outOfBounds() const;
	bool getFall() const;
	void setFall(bool);
	void respawn();
protected:
	sf::Vector2f m_respawnLocation;
	sf::Vector2f m_prevPos;
	sf::Vector2f m_direction;	// direction of movement
	bool m_falling;
};
