/*
*  SUMMER VACATION
*  Choi Jinwoo
*  2018/07/01
*  BLUE ENGINE
*/
#include"TestLevel1.h"
#include "Input.h"
#include <iostream>
#include "Engine.h"
#include"StateManager.h"
#include "Timer.h"
#include "Graphics.h"
#include "ObjectFactory.h"

int x_iterator, y_iterator;

void Level1::Init()
{
	GRAPHICS->ChangeBackgroundColor(0.5f, 0.5f, 0.9f, 1.0f);
	Timer::GetInstance().Init();
	mouse_clicked = 0;
	key_clicked = 0;

	obj = OBJECT_FACTORY->CreateEmptyObject();
	obj->AddComponent(new Transform());
	obj->AddComponent(new Mesh());

	obj->Init();

	obj->mesh->ChangeColor({ 0,0.3f,0.5f,1 });


	player = OBJECT_FACTORY->CreateEmptyObject();
	player->AddComponent(new Transform());
	player->AddComponent(new Mesh());

	player->Init();
	player->mesh->ChangeColor({ 0,0,1,1 });
	std::cout << "LV1 Init" << std::endl;
	x_iterator = 1;
	y_iterator = 1;
}

void Level1::Update()
{
	//  std::cout << Timer::GetInstance().GetTime() << std::endl;


	if (Input::GetInstance().IsKeyTriggered(SDL_SCANCODE_N))
	{
		std::cout << "Change level to Level2" << std::endl;
		Close();
		STATEMANAGER->ChangeLevel(LV_TEST2);

	}
	if (Input::GetInstance().IsKeyTriggered(SDL_SCANCODE_ESCAPE))
	{
		ENGINE->Quit();
	}



	//////////////////////////////////////////////////////////////////////////
	//moving object
	float obj1x = obj->transform->GetTranslation().x;
	if (obj1x == 250 || obj1x == -250)
		x_iterator *= -1;

	if (obj1x == 250 || obj1x == -250 || obj1x == 125 || obj1x == -125 || obj1x == 0)
		y_iterator *= -1;
	float ColorValue = (obj1x + 250) / 500.f;
	obj->mesh->ChangeColor({ 0,0.3f,ColorValue,1 });
	obj->transform->SetTranslation(glm::vec2{ obj1x + 5.f*x_iterator, obj->transform->GetTranslation().y + 5.f*y_iterator });
	//////////////////////////////////////////////////////////////////////////



	//////////////////////////////////////////////////////////////////////////
	//player move
	if (Input::GetInstance().IsKeyTriggered(SDL_SCANCODE_D))
	{
		right = true;
	}
	if (Input::GetInstance().IsKeyReleased(SDL_SCANCODE_D))
	{
		right = false;
	}
	if (Input::GetInstance().IsKeyTriggered(SDL_SCANCODE_A))
	{
		left = true;
	}
	if (Input::GetInstance().IsKeyReleased(SDL_SCANCODE_A))
	{
		left = false;
	}
	if (Input::GetInstance().IsKeyTriggered(SDL_SCANCODE_W))
	{
		up = true;
	}
	if (Input::GetInstance().IsKeyReleased(SDL_SCANCODE_W))
	{
		up = false;
	}
	if (Input::GetInstance().IsKeyTriggered(SDL_SCANCODE_S))
	{
		down = true;
	}
	if (Input::GetInstance().IsKeyReleased(SDL_SCANCODE_S))
	{
		down = false;
	}

	Transform* transform = player->transform;
	if (down)
	{
		transform->SetTranslation({ transform->GetTranslation().x,transform->GetTranslation().y - 3 });
	}
	if (up)
	{
		transform->SetTranslation({ transform->GetTranslation().x,transform->GetTranslation().y + 3 });
	}
	if (left)
	{
		transform->SetTranslation({ transform->GetTranslation().x - 3,transform->GetTranslation().y });
	}
	if (right)
	{
		transform->SetTranslation({ transform->GetTranslation().x + 3,transform->GetTranslation().y });
	}
	//////////////////////////////////////////////////////////////////////////

}

void Level1::Close()
{
	GRAPHICS->DeleteAllMeshes();
	OBJECT_FACTORY->DestroyAllObjects();
}


