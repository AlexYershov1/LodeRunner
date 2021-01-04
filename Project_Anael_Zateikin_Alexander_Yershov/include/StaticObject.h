#pragma once
#include "GameObject.h"

class StaticObject : public GameObject
{
public:
	using GameObject::GameObject;
	~StaticObject();

protected:

private:
	
};

StaticObject::~StaticObject()
{
}

