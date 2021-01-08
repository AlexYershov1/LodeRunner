#include "GameObject.h"
#include "Macros.h"

GameObject::GameObject(Elements symbol, const sf::Vector2f& location, int mapWidth, int mapHeight)
{
	auto texturePtr = TextureHolder::instance().getIcon(symbol);
	m_icon.setTexture(*texturePtr);
	//this section should be in a seperate function - will be called in a new level
	
	auto xScaleValue = (float)WINDOW_WIDTH / ((float)ICON_SIZE * (float)mapWidth);
	auto yScaleValue = (float)WINDOW_HEIGHT / ((float)ICON_SIZE * (float)mapHeight);

	m_icon.scale(xScaleValue, yScaleValue);
	m_icon.setPosition(location);
	
	//set origin
	//const auto rect = m_icon.getGlobalBounds();			//for now - taking this down. Easier to place the sprites with default origin
	//m_icon.setOrigin(rect.width / 2, rect.height / 2);
}

GameObject::~GameObject()
{
}

bool GameObject::collidesWith(const GameObject& obj) const
{
	return m_icon.getGlobalBounds().intersects(obj.m_icon.getGlobalBounds());
}

void GameObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_icon);
}
