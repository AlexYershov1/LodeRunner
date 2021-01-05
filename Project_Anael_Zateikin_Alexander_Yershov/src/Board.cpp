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
	case '-':
		return Elements::bar;
		break;
	case '*':
		return Elements::coin;
		break;
	case '%':
		return Elements::enemy;
		break;
	case '@':
		return Elements::player;
		break;
	case '#':
		if (this->m_map[row][col + 1] == '#' || this->m_map[row][col - 1] == '#')
			return Elements::floor;
		else
			return Elements::wall;
		break;
	case 'H':
		return Elements::ladder;
		break;
	case ' ':
		return Elements::empty;
		break;
	default:
		break;
	}
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


