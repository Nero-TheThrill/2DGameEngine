/*
*  Choi Jinwoo
*  2018/09/25
*  BLUE ENGINE
*/
#include "ObjectFactory.h"
#include <cassert>
#include "Object.h"
#include <iostream>


extern ObjectFactory* OBJECT_FACTORY = nullptr;

ObjectFactory::ObjectFactory()
{
	std::cout << "ObjectFactory constructor called" << std::endl;
	assert(OBJECT_FACTORY == nullptr && "ObjectFactory is already created");
	OBJECT_FACTORY = this;
	last_objectID = 0;
}

ObjectFactory::~ObjectFactory()
{
	//DestroyAllObjects();
}

void ObjectFactory::Update()
{

	for (auto obj : ObjectsToBeDeleted)
	{
		if (obj == nullptr)
			continue;

		auto delete_objID = ObjectIDMap.find(obj->objectID);

		if (delete_objID != ObjectIDMap.end())
		{
			delete obj;
			ObjectIDMap.erase(delete_objID);
		}
	}
	ObjectsToBeDeleted.clear();
}

void ObjectFactory::Destroy(Object* obj)
{
	ObjectsToBeDeleted.push_back(obj);
}

void ObjectFactory::GiveObjectID(Object* obj)
{
	++last_objectID;
	obj->objectID = last_objectID;

	ObjectIDMap[last_objectID] = obj;
}

Object* ObjectFactory::CreateEmptyObject()
{
	Object* obj = new Object();

	GiveObjectID(obj);

	return obj;
}

void ObjectFactory::DestroyAllObjects()
{
	Update();
	for (auto blue : ObjectIDMap)
		delete blue.second;

	ObjectIDMap.clear();
}
Object* ObjectFactory::FindObjectwithName(std::string& name) const
{
	for (const auto obj : ObjectIDMap)
	{
		if (obj.second->objName == name)
			return obj.second;
	}
	return nullptr;
}
Object* ObjectFactory::FindObjectwithID(ObjectID id) const
{
	for (const auto obj : ObjectIDMap)
	{
		if (obj.second->GetObjectID() == id)
			return obj.second;
	}
	return nullptr;
}
