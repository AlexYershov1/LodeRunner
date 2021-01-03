#pragma once
#include "GameObject.h"

class StaticObject : public GameObject
{
public:
	using GameObject::GameObject;
	~StaticObject();
	void foo();
protected:

private:
	
};

StaticObject::~StaticObject()
{
}

