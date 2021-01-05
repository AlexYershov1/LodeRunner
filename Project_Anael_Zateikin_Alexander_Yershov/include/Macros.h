#pragma once

const float BASE_SPEED = 1.0;
const float STEP = 2.0;
const int NUM_OF_LIVES = 3;
const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 800;
const float ICON_SIZE = 300;
const int SEED = 17;
const int NUM_OF_ENEMIE_TYPES = 3;
const int NUM_OF_BONUS_TYPES = 4;

enum class Elements
{
	coin, ladder, bar, wall, floor, bonus,
	enemy, player
};

enum class EnemyType
{
	dumb, mediocre, smart
};
enum class BonusType
{
	life, score, time, bad
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