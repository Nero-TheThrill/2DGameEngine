/*
*  SUMMER VACATION
*  Choi Jinwoo
*  2018/07/02
*  BLUE ENGINE
*/
#include"TestLevel2.h"
#include "Input.h"
#include <iostream>
#include "Engine.h"
#include"StateManager.h"
#include "Graphics.h"
#include "ObjectFactory.h"


void Level2::Init()

{
	GRAPHICS->ChangeBackgroundColor(0.1f,0.1f,0.1f,0.1f);
	mouse_clicked = 0;
	key_clicked = 0;
	std::cout << "LV2 Init" << std::endl;

}

void Level2::Update()
{
	if (Input::GetInstance().IsAnyKeyTriggered())
	{
		key_clicked += 1;
		std::cout << "LV2 key pressed" << std::endl;
	}
	if (Input::GetInstance().IsKeyTriggered(SDL_SCANCODE_N))
	{
		std::cout << "Change level to Level1" << std::endl;
		Close();
		STATEMANAGER->ChangeLevel(LV_TEST1);
	}
	if (Input::GetInstance().IsKeyTriggered(SDL_SCANCODE_ESCAPE))
	{
		ENGINE->Quit();
	}
	if (Input::GetInstance().IsMouseTriggered(SDL_BUTTON_LEFT))
	{
		GRAPHICS->ChangeBackgroundColor(0, 0, 1, 1);
	}
	if (Input::GetInstance().IsMouseTriggered(SDL_BUTTON_RIGHT))
	{
		GRAPHICS->ChangeBackgroundColor(0, 1, 0, 1);
	}
	if (Input::GetInstance().IsMouseTriggered(SDL_BUTTON_MIDDLE))
	{
		GRAPHICS->ChangeBackgroundColor(1, 0, 0, 1);
	}

}


void Level2::Close()
{
	GRAPHICS->DeleteAllMeshes();
	OBJECT_FACTORY->DestroyAllObjects();
}


