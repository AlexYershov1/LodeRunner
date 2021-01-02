#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Board.h"
//#include "Enemy.h"
#include "MovingObject.h"
#include "StaticObject.h"

class Controller
{
public:
	Controller();
	~Controller();
	void run();
	void move();
	void checkCollision();
private:
	Board m_map;
	std::vector<std::unique_ptr<MovingObject>> m_movingObj;
	std::vector<std::unique_ptr<StaticObject>> m_staticObj;

	sf::RenderWindow m_gameWindow;
	sf::Clock m_stageTime;
	int m_level;
};
