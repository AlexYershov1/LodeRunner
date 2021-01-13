#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"

class Wall;
class Floor;
class Player;
class Enemy;
class Bar;
class Ladder;
class Coin;
class Bonus;
class Controller;

class GameObject
{
public:
	GameObject(Elements, const sf::Vector2f&, int, int); //should receive a board
	~GameObject();
	bool collidesWith(const GameObject&) const;

	virtual void handleCollision(GameObject&, Controller&) = 0;
	virtual void handleCollision(Wall&, Controller&) = 0;
	virtual void handleCollision(Floor&, Controller&) = 0;
	virtual void handleCollision(Player&, Controller&) = 0;
	virtual void handleCollision(Enemy&, Controller&) = 0;
	virtual void handleCollision(Bar&, Controller&) = 0;
	virtual void handleCollision(Ladder&, Controller&) = 0;
	virtual void handleCollision(Coin&, Controller&) = 0;
	virtual void handleCollision(Bonus&, Controller&) = 0;
	
	//virtual void draw(sf::RenderWindow&) const = 0;
	virtual void draw(sf::RenderWindow&);
	bool contains(const sf::Vector2f&) const;
	sf::Vector2f getPos() const;
	void setPos(const sf::Vector2f&);

	float getIconWidth() const;
	float getIconHeight() const;

protected:
	sf::Sprite m_icon;
private:
	
};

