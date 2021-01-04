#pragma once

const float BASE_SPEED = 1.0;
const float STEP = 2.0;

enum class Elements
{
	coin, ladder, bar, wall, floor,
	enemy, player
};

enum class Direction
{
	Left, Right, Up, Down
};

bool isStaticObj(const Elements symbol)
{
	return (symbol == Elements::coin || symbol == Elements::bar ||
			symbol == Elements::ladder || symbol == Elements::floor ||
			symbol == Elements::wall);
}