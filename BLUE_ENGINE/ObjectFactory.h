/*
*  Choi Jinwoo
*  2018/09/25
*  BLUE ENGINE
*/
#pragma once
#include"System.h"
#include<map>
#include <string>
#include<vector>

class Object;
using ObjectID = unsigned;

class ObjectFactory : public System
{
public:
	ObjectFactory();
	~ObjectFactory();

	void Init() override {}
	void Update() override;

	void Destroy(Object* gameObject);

	void GiveObjectID(Object* gameObject);

	Object* CreateEmptyObject();

	void DestroyAllObjects();

	Object* FindObjectwithName(std::string& name) const;
	Object* FindObjectwithID(ObjectID id) const;

private:
	ObjectID last_objectID;

	std::map<ObjectID, Object*> ObjectIDMap;
	std::vector<Object*> ObjectsToBeDeleted;
};

extern ObjectFactory* OBJECT_FACTORY;
