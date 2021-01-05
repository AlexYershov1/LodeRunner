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
	GameObject(const sf::Texture *, const sf::Vector2f&, int, int); //should receive a board
	~GameObject();
	bool collidesWith(const GameObject&) const;
	virtual void handleCollision(const GameObject&) = 0;
	virtual void handleCollision(const Wall&) = 0;
	// virtual void handleCollision(const Floor&) = 0;	// maybe relevent
	virtual void handleCollision(const Player&) = 0;
	virtual void handleCollision(const Enemy&) = 0;
	virtual void handleCollision(const Bar&) = 0;
	virtual void handleCollision(const Ladder&) = 0;
	virtual void handleCollision(const Coin&) = 0;
	virtual void handleCollision(const Bonus&) = 0;
	
	//virtual void draw(sf::RenderWindow&) const = 0;
	void draw(sf::RenderWindow&) const ;
	sf::Sprite m_icon;
protected:
	
private:
	
};

