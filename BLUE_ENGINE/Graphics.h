/*
*  Hyun Jina, Choi Jinwoo
*
*  Do not use this code for your engine
*  Make your own code.
*/



#pragma once

#include "System.h"
#include <vector>
#include <map>
#include "Object.h"
#include "Shader.h"
#include "Camera.h"

class Mesh;

class Graphics : public System
{
public:
	Graphics();
	~Graphics();
	void Init() override;
	void Update() override;
	void ChangeBackgroundColor(float r, float g, float b, float a);
	void AddMesh(Mesh* mesh);
	void DeleteMesh(Mesh* mesh);
	void DeleteAllMeshes();
private:
	std::map<ObjectID, Mesh*> MeshMap;
	std::vector<Mesh*> MeshsToBeDeleted;
	Shader shader;
	Camera cam;
};

extern Graphics* GRAPHICS;

