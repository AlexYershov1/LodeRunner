#include "staticInclude/StaticObject.h"





StaticObject::StaticObject(Elements symbol, const sf::Vector2f& position, int mapW, int mapH)
	: GameObject(symbol, position, mapW, mapH)
{
}

StaticObject::~StaticObject()
{
}

const sf::Vector2f StaticObject::Center() const
{
	const auto rect = this->m_icon.getGlobalBounds();
	sf::Vector2f ladderCenter = { this->getPos().x + rect.width / 2, this->getPos().y + rect.height / 2 };
	return ladderCenter;
}
