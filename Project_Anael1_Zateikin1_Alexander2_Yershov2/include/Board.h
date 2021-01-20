#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include "Macros.h"
#include <memory>
#include "staticInclude/LifeBonus.h"
#include "staticInclude/ScoreBonus.h"
#include "staticInclude/TimeBonus.h"
#include "staticInclude/BadBonus.h"
#include "staticInclude/Ladder.h"
#include "staticInclude/Floor.h"
#include "staticInclude/Bar.h"
#include "staticInclude/Coin.h"
#include "staticInclude/Wall.h"
#include "movingInclude/MovingObject.h"

class Board
{
public:
	Board();
	~Board();
	
	bool readLvlMap();		//read a level
	std::unique_ptr<StaticObject> createStaticObject(Elements, sf::Vector2f);
	void checkCollision(MovingObject&, Controller&, const sf::Time& );

	// get functions
	int getWidth() const;
	int getHeight() const;
	int getInitLevelTime() const;
	Elements getSymbol(int, int);
	void draw(sf::RenderWindow&);
	float getStaticIconInfo(bool) const;

	void eraseObject(StaticObject&);
	bool LvlWon() const;
	void resetLvlMap();
	void dig(const sf::Vector2f&);
	void resetStreamPtr();	//return stream pointer to begining of file
private:
	std::ifstream m_fRead;
	std::vector<std::string> m_map;
	std::vector<std::unique_ptr<StaticObject>> m_staticObj;
	int m_height;
	int m_width;
	int m_initLevelTime;

	void readLvlSize();
	bool checkIfFloorSymbol(int, int) const;
	//bool checkFloorUnder(const MovingObject&, const StaticObject&) const;
};
static std::unique_ptr<Bonus> selectBonusType(sf::Vector2f, int, int);