#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include "Macros.h"

class Board
{
public:
	Board();
	~Board();
	
	void readLvlMap();

	// get functions
	int getWidth() const;
	int getHeight() const;
	Elements getSymbol(int, int);

private:
	std::ifstream m_fRead;
	std::vector<std::string> m_map;
	int m_height;
	int m_width;

	void readLvlSize();
	bool checkIfFloorSymbol(int, int) const;
};
