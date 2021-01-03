#include "GameObject.h"

GameObject::GameObject(const sf::Texture* texturePtr)
{
	m_icon.setTexture(*texturePtr);
	m_icon.scale(0.2f, 0.2f);
	//set origin
	const auto rect = m_icon.getLocalBounds();
	m_icon.setOrigin(rect.width / 2, rect.height / 2);
}

GameObject::~GameObject()
{
}

bool GameObject::collidesWith(const GameObject& obj)
{
	return m_icon.getGlobalBounds().intersects(obj.m_icon.getGlobalBounds());
}

void GameObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_icon);
}
