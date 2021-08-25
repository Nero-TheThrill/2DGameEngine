/*
*  Choi Jinwoo
*  2018/09/25
*  BLUE ENGINE
*/
#pragma once

#include"ComponentType.h"

class Object;
class Component
{
public:
	Component(ComponentType ctype) :ComponentType(ctype) {}
	virtual ~Component() {}
	virtual void Init() {}
	void SetOwner(Object* pobj)
	{
		pObject = pobj;
	}
	Object* GetOwner()
	{
		return pObject;
	}
	ComponentType GetComponentType()
	{
		return ComponentType;
	}

private:
	friend class Object;
	Component() = delete;
	Object* pObject = nullptr;
	ComponentType ComponentType;
};
