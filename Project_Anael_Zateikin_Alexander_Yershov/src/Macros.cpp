#include "Macros.h"

bool isStaticObj(const Elements symbol)
{
	return (symbol == Elements::coin || symbol == Elements::bar ||
		symbol == Elements::ladder || symbol == Elements::floor ||
		symbol == Elements::wall);
}