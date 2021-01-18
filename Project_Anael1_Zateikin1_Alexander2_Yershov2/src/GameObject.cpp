#include "GameObject.h"
#include "Macros.h"

GameObject::GameObject(Elements symbol, const sf::Vector2f& location, int mapWidth, int mapHeight)
{
	auto texturePtr = resourcesManager::instance().getIcon(symbol);
	m_icon.setTexture(*texturePtr);
	
	auto xScaleValue = (float)WINDOW_WIDTH / ((float)ICON_SIZE * (float)mapWidth);
	auto yScaleValue = (float)WINDOW_HEIGHT / ((float)ICON_SIZE * (float)mapHeight);

	m_icon.scale(xScaleValue, yScaleValue);
	m_icon.setPosition(location);
}

GameObject::~GameObject()
{
}

bool GameObject::collidesWith(const GameObject& obj) const
{
	return m_icon.getGlobalBounds().intersects(obj.m_icon.getGlobalBounds());
}

void GameObject::draw(sf::RenderWindow& window)
{
	window.draw(m_icon);
}

sf::Vector2f GameObject::getPos() const
{
	return m_icon.getPosition() ;
}

void GameObject::setPos(const sf::Vector2f& position)
{
	m_icon.setPosition(position);
}

float GameObject::getIconWidth() const
{
	return m_icon.getGlobalBounds().width;
}

float GameObject::getIconHeight() const
{
	return m_icon.getGlobalBounds().height;
}

bool GameObject::contains(const sf::Vector2f& Location) const
{
	if (this->m_icon.getGlobalBounds().contains(Location))
		return true;
	return false;
}
