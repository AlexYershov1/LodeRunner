#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include "Macros.h"
#include "StaticObject.h"
#include <memory>
#include "LifeBonus.h"
#include "ScoreBonus.h"
#include "TimeBonus.h"
#include "BadBonus.h"
#include "Ladder.h"
#include "Floor.h"
#include "Bar.h"
#include "Coin.h"
#include "MovingObject.h"

class Board
{
public:
	Board();
	~Board();
	
	void readLvlMap();
	std::unique_ptr<StaticObject> createStaticObject(Elements, sf::Texture*, sf::Vector2f);
	void checkCollision(MovingObject&);
	// get functions
	int getWidth() const;
	int getHeight() const;
	Elements getSymbol(int, int);
	void draw(sf::RenderWindow&);
private:
	std::ifstream m_fRead;
	std::vector<std::string> m_map;
	std::vector<std::unique_ptr<StaticObject>> m_staticObj;
	int m_height;
	int m_width;

	void readLvlSize();
	bool checkIfFloorSymbol(int, int) const;
};
static std::unique_ptr<Bonus> selectBonusType(sf::Texture*, sf::Vector2f, int, int);