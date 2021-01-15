#pragma once
#include <memory>
#include "Board.h"
#include "TextureHolder.h"
#include "movingInclude/Player.h"
#include "movingInclude/DumbEnemy.h"
#include "movingInclude/MediocreEnemy.h"
#include "movingInclude/SmartEnemy.h"
#include "StartScreen.h"
#include "Caption.h"


class Controller
{
public:
	Controller();
	~Controller();
	void run();
	void move(sf::Time);
	void checkCollision(MovingObject&, sf::Time);
	void draw();
	//erase coin
	void eraseCoin(Coin&);
	void increaseScore();
	void addEnemy(); 
	void addTime();

private:
	void dig(bool);
	void createObject();
	std::unique_ptr<MovingObject> createMovingObject(Elements, sf::Vector2f, int, int);

	Board m_map;
	std::vector<std::unique_ptr<MovingObject>> m_movingObj;

	//TextureHolder m_textures;
	sf::RenderWindow m_gameWindow;
	sf::Clock m_timer;
	StartScreen m_menu;
	Caption m_caption;
};
static std::unique_ptr<Enemy> selectEnemyType(sf::Vector2f, int, int);
