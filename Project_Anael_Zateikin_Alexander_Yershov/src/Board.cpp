#include "Board.h"

Board::Board() : m_height(0), m_width(0)
{
	this->m_fRead.open("board.txt", std::ios_base::in);
	// maybe call read size and read map
}

Board::~Board()
{
}

void Board::readLvlMap()
{
	readLvlSize();
	auto line = std::string();
	for (int row = 0; row < m_height; row++)
	{
		getline(m_fRead, line);
		m_map.push_back(line);
	}
}

std::unique_ptr<StaticObject> Board::createStaticObject(Elements type, sf::Texture* icon, sf::Vector2f position)
{
	switch (type)
	{
	case Elements::wall:
		m_staticObj.push_back(std::make_unique<Wall>(icon, position, m_width, m_height));
		break;
	case Elements::floor:
		m_staticObj.push_back(std::make_unique<Floor>(icon, position, m_width, m_height));
		break;
	case Elements::ladder:
		m_staticObj.push_back(std::make_unique<Ladder>(icon, position, m_width, m_height));
		break;
	case Elements::bar:
		m_staticObj.push_back(std::make_unique<Bar>(icon, position, m_width, m_height));
		break;
	case Elements::coin:
		m_staticObj.push_back(std::make_unique<Coin>(icon, position, m_width, m_height));
		break;
	case Elements::bonus:
		m_staticObj.push_back(selectBonusType(icon, position, m_width, m_height));
		break;
	}
	return nullptr;
}

void Board::checkCollision(MovingObject& thisObj)
{
	// check collision between moving objects and static objects
	for (auto& unmovable : m_staticObj)
	{
		if (thisObj.collidesWith(*unmovable))
			thisObj.handleCollision(*unmovable);
	}
}

std::unique_ptr<Bonus> selectBonusType(sf::Texture* icon, sf::Vector2f position, int mapW, int mapH)
{
	int choice = rand() % NUM_OF_BONUS_TYPES; //choose one of three enemy types

	switch ((BonusType)choice)
	{
	case BonusType::life:
		return std::make_unique<LifeBonus>(icon, position, mapW, mapH);
	case BonusType::score:
		return std::make_unique<ScoreBonus>(icon, position, mapW, mapH);
	case BonusType::time:
		return std::make_unique<TimeBonus>(icon, position, mapW, mapH);
	case BonusType::bad:
		return std::make_unique<BadBonus>(icon, position, mapW, mapH);
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
}

void Board::draw(sf::RenderWindow& window)
{
	//draw stastics
	for (auto& unmovable : m_staticObj)
		unmovable->draw(window);
}

void Board::readLvlSize()
{
	std::string number;

	// first number - height
	this->m_fRead >> number;
	this->m_height = std::stoi(number, nullptr);
	// second number - width
	this->m_fRead >> number;
	this->m_width = std::stoi(number, nullptr);
	this->m_fRead.ignore();
}

bool Board::checkIfFloorSymbol(int row, int col) const
{
	if(row == 0 ) //ceiling
		return false;
	if (m_map[row - 1][col] == WALL_C) //check if there is a wall above
		return false;

	return true; //is a floor
}


