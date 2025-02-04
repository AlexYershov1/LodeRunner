#include "Board.h"
#include "Controller.h"
#include <typeinfo>

Board::Board() : m_height(0), m_width(0) , m_initLevelTime(0)
{
	this->m_fRead.open("board.txt", std::ios_base::in);
}

Board::~Board()
{
}

bool Board::readLvlMap()
{
	readLvlSize();
	if (this->m_fRead.eof())
		return false;
	auto line = std::string();
	for (int row = 0; row < m_height; row++)
	{
		getline(m_fRead, line);
		m_map.push_back(line);
	}
	return true;
}

std::unique_ptr<StaticObject> Board::createStaticObject(Elements type, sf::Vector2f position)
{
	switch (type)
	{
	case Elements::wall:
		m_staticObj.push_back(std::make_unique<Wall>(type, position, m_width, m_height));
		break;
	case Elements::floor:
		m_staticObj.push_back(std::make_unique<Floor>(type, position, m_width, m_height));
		break;
	case Elements::ladder:
		m_staticObj.push_back(std::make_unique<Ladder>(type, position, m_width, m_height));
		break;
	case Elements::bar:
		m_staticObj.push_back(std::make_unique<Bar>(type, position, m_width, m_height));
		break;
	case Elements::coin:
		m_staticObj.push_back(std::make_unique<Coin>(type, position, m_width, m_height));
		break;
	case Elements::bonus:
		m_staticObj.push_back(selectBonusType(position, m_width, m_height));
		break;
	}
	return nullptr;
}

void Board::checkCollision(MovingObject& thisObj, Controller& game, const sf::Time& deltaTime)
{
	bool collided = false;

	// check collision between moving objects and static objects
	for (auto& unmovable : m_staticObj)
	{
		if ( unmovable != nullptr && thisObj.collidesWith(*unmovable))
		{
			thisObj.handleCollision(*unmovable, game);

			collided = true;
		}
	}
	if (!collided)	//if no collisions occurred
	{
		thisObj.fall(deltaTime);  //fall 
		for (auto& unmovable : m_staticObj)
		{
			if (unmovable != nullptr && thisObj.collidesWith(*unmovable))
			{
				collided = true;
				//if above ladder, let float above to be able to go to floor
				if (typeid(*unmovable) == typeid(Ladder))
				{
					thisObj.moveToPrevPos(); 
				}
					
				thisObj.handleCollision(*unmovable, game);
			}
		}
		if (thisObj.outOfBounds())
			thisObj.moveToPrevPos();

		if (!collided)
			thisObj.setFall(true);
	}
}

std::unique_ptr<Bonus> selectBonusType(sf::Vector2f position, int mapW, int mapH)
{
	int choice = rand() % NUM_OF_BONUS_TYPES; //choose one of three enemy types

	switch ((BonusType)choice)
	{
	case BonusType::life:
		return std::make_unique<LifeBonus>(Elements::bonus, position, mapW, mapH);
	case BonusType::score:
		return std::make_unique<ScoreBonus>(Elements::bonus, position, mapW, mapH);
	case BonusType::time:
		return std::make_unique<TimeBonus>(Elements::bonus, position, mapW, mapH);
	case BonusType::bad:
		return std::make_unique<BadBonus>(Elements::bonus, position, mapW, mapH);
	}
	return nullptr;
}

int Board::getWidth() const
{
	return this->m_width;
}

int Board::getHeight() const
{
	return this->m_height;
}

int Board::getInitLevelTime() const
{
	return m_initLevelTime;
}

Elements Board::getSymbol(int row, int col)
{
	char symbol = this->m_map[row][col];

	switch (symbol)
	{
	case BAR_C:
		return Elements::bar;
		break;
	case COIN_C:
		return Elements::coin;
		break;
	case ENEMY_C:
		return Elements::enemy;
		break;
	case PLAYER_C:
		return Elements::player;
		break;
	case WALL_C:
		//distinguish floor / wall
		if (checkIfFloorSymbol(row, col)) 
			return Elements::floor;
		else
			return Elements::wall;
		break;
	case LADDER_C:
		return Elements::ladder;
		break;
	case BONUS_C:
		return Elements::bonus;
		break;
	case EMPTY_C:
		return Elements::empty;
		break;
	default:
		break;
	}
	return Elements::empty;	// to avoid warning
}

void Board::draw(sf::RenderWindow& window)
{
	//draw stastics
	for (auto& unmovable : m_staticObj)
		unmovable->draw(window);
}

void Board::eraseObject(StaticObject& staticObj)
{
	auto staticPtr = this->m_staticObj.begin();
	for (; staticPtr != m_staticObj.end(); staticPtr++)
	{
		if ((*staticPtr)->getPos() == staticObj.getPos())
		{
			m_staticObj.erase(staticPtr);
			break;
		}			
	}
}

//The function takes the first static object and returns the wanted dimention (height / width)
float Board::getStaticIconInfo(bool isWidth) const
{
	if (this->m_staticObj.size() != 0)
	{
		auto it = this->m_staticObj.begin();
		while (*it == nullptr)
		{
			if (it == this->m_staticObj.end())
				return 0;
			it++;
		}
		if (isWidth)
			return (**it).getIconWidth();
		else
			return (**it).getIconHeight();
	}
	return NULL;	// to avoid warning
}

bool Board::LvlWon() const
{
	for (auto& unmoveble : m_staticObj)
	{
		if (typeid(*unmoveble) == typeid(Coin))
			return false;
	}
	return true;
}

void Board::resetLvlMap()
{
	m_staticObj.clear();

	for (int row = m_height - 1; row >= 0; row--)
		m_map.pop_back();
}

void Board::dig(const sf::Vector2f& Location)
{
	for (auto& unmovable : m_staticObj)
	{
		if ((*unmovable).contains(Location))
		{
			StaticObject* ptr = unmovable.get(); //get pointer to object
			if (dynamic_cast<Floor*>(ptr))
			{
				dynamic_cast<Floor*>(ptr)->dig();
			}
		}
	}
}

void Board::resetStreamPtr()
{
	this->m_fRead.clear();
	this->m_fRead.seekg(std::ios_base::beg);
}

void Board::readLvlSize()
{
	std::string number;

	// first number - height
	this->m_fRead >> number;
	if (m_fRead.eof())
		return;
	this->m_height = std::stoi(number, nullptr);
	// second number - width
	this->m_fRead >> number;
	this->m_width = std::stoi(number, nullptr);
	// third number - level time
	this->m_fRead >> number;
	this->m_initLevelTime = std::stoi(number, nullptr);
	this->m_fRead.ignore();
}

bool Board::checkIfFloorSymbol(int row, int col) const
{
	if(row == 0 ) //ceiling
		return false;
	int rowIndex = row - 1;	// correct row index
	if (m_map[rowIndex][col] == WALL_C) //check if there is a wall above
		return false;

	return true; //is a floor
}