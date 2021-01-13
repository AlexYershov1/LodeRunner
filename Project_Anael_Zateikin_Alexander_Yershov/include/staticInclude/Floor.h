#pragma once
#include "StaticObject.h"

class Floor : public StaticObject
{
public:
	using StaticObject::StaticObject;
	~Floor();
	virtual void handleCollision(Player&, Controller&) override;
	virtual void handleCollision(Enemy&, Controller&) override ;
	
	void dig();
	virtual void draw(sf::RenderWindow&) override;
private:
	bool m_eliminated = false;
	sf::Clock m_construction;
	sf::Vector2f m_prevPos;
};