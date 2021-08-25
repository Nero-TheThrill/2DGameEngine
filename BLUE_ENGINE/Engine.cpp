/*
*  SUMMER VACATION
*  Choi Jinwoo
*  2018/06/28
*  BLUE ENGINE
*/
#include<SDL.h>
#include <GL/glew.h>

#include <vector>
#include "Engine.h"
#include <glm/glm.hpp>
#include"Application.h"
#include <iostream>
#include "Graphics.h"
#include "StateManager.h"
#include "ObjectFactory.h"




Engine* ENGINE = nullptr;

Engine::Engine()
{
	GAMERUN = true;
	ENGINE = this;
}

Engine::~Engine()
{
	ENGINE = nullptr;
}

void Engine::Init()
{
	std::cout << "Initialize Engine" << std::endl;
	//Order is important
	AddSystem(new Application());
	AddSystem(new ObjectFactory());
	AddSystem(new Graphics());
	AddSystem(new StateManager());
	for (auto blue : Systems)
	{
		blue->Init();
	}
}

void Engine::GameLoop()
{
	while (GAMERUN)
	{
		for (auto blue : Systems)
		{
			blue->Update();
		}
	}

}

void Engine::Quit()
{
	GAMERUN = false;
}

void Engine::AddSystem(System* system)
{
	Systems.push_back(system);
}


