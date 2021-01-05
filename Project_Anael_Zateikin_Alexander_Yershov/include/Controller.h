#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Board.h"
#include "MovingObject.h"
#include "StaticObject.h"
#include "TextureHolder.h"
#include "Player.h"
#include "Enemy.h"
#include "DumbEnemy.h"
#include "MediocreEnemy.h"
#include "SmartEnemy.h"
#include "Wall.h"
#include "Ladder.h"
#include "Bar.h"
#include "Coin.h"
#include "Bonus.h"
#include "LifeBonus.h"
#include "ScoreBonus.h"
#include "TimeBonus.h"
#include "BadBonus.h"


class Controller
{
public:
	Controller();
	~Controller();
	void run();
	void move(sf::Time);
	bool checkCollision(MovingObject&);
	void draw();
private:
	void createObject();
	std::unique_ptr<StaticObject> createStaticObject(Elements, sf::Texture* , sf::Vector2f , int, int);
	//std::unique_ptr<MovingObject> createMovingObject(Elements, sf::Texture*, sf::Vector2f, int, int);

	Board m_map;
	std::vector<std::unique_ptr<MovingObject>> m_movingObj;
	std::vector<std::unique_ptr<StaticObject>> m_staticObj;

	TextureHolder m_textures;
	sf::RenderWindow m_gameWindow;
	sf::Clock m_stageTime;
	int m_level;
};
static std::unique_ptr<MovingObject> createMovingObject(Elements, sf::Texture*, sf::Vector2f, int, int);
static std::unique_ptr<Enemy> selectEnemyType(sf::Texture*, sf::Vector2f, int, int);
static std::unique_ptr<Bonus> selectBonusType(sf::Texture*, sf::Vector2f, int, int);