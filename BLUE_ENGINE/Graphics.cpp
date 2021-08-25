/*
*  Hyun Jina, Choi Jinwoo
*
*  Do not use this code for your engine
*  Make your own code.
*/


#include"Graphics.h"
#include <iostream>
#include <SDL.h>

Graphics* GRAPHICS = nullptr;

Graphics::Graphics()
{
	std::cout << "Graphics constructor called" << std::endl;
	GRAPHICS = this;
}

Graphics::~Graphics()
{
	delete GRAPHICS;
}

void Graphics::Init()
{
	glewInit();
	glClearColor(0.5f, 0.5f, 0.9f, 1.0f);

	int screenWidth = 0, screenHeight = 0;
	SDL_GetWindowSize(SDL_GL_GetCurrentWindow(), &screenWidth, &screenHeight);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	cam.Init(screenWidth, screenHeight);
	shader.compileShaders();
}

void Graphics::Update()
{
	for (auto obj : MeshsToBeDeleted)
	{
		if (obj == nullptr)
			continue;

		auto delete_objID = MeshMap.find(obj->GetOwner()->GetObjectID());

		if (delete_objID != MeshMap.end())
		{
			delete obj;
			obj = nullptr;
			MeshMap.erase(delete_objID);
		}
	}
	MeshsToBeDeleted.clear();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	shader.use();
	cam.update();
	shader.SendUniformVariable("camera", cam.getCameraMatrix());

	for (auto mesh : MeshMap)
	{
		if (mesh.second != nullptr)
			mesh.second->draw();
	}


	SDL_GL_SwapWindow(SDL_GL_GetCurrentWindow());
}

void Graphics::ChangeBackgroundColor(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}

void Graphics::AddMesh(Mesh* mesh)
{
	std::cout << mesh->GetOwner()->GetObjectID() << std::endl;
	MeshMap[mesh->GetOwner()->GetObjectID()] = mesh;
}

void Graphics::DeleteMesh(Mesh* mesh)
{
	MeshsToBeDeleted.push_back(mesh);
}

void Graphics::DeleteAllMeshes()
{
	Update();
	for (auto blue : MeshMap)
	{
		delete blue.second;
		blue.second = nullptr;
	}

	MeshMap.clear();
}
