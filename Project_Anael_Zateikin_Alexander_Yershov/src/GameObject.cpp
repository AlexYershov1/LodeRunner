#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

bool GameObject::collidesWith(const GameObject& obj)
{
	return m_icon.getGlobalBounds().intersects(obj.m_icon.getGlobalBounds());
}
