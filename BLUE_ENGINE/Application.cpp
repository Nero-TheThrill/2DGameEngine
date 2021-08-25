/*
*  SUMMER VACATION
*  Choi Jinwoo
*  2018/06/28
*  BLUE ENGINE
*/
#include "Application.h"
#include <GL/glew.h>
#include <iostream>
#include "Engine.h"

Application* APPLICATION = nullptr;
const GLuint DEFAULT_SCREEN_WIDTH = 1280;
const GLuint DEFAULT_SCREEN_HEIGHT = 720;
const char* GAME_TITLE = "BLUE";

Application::Application() :ScreenWidth(DEFAULT_SCREEN_WIDTH), ScreenHeight(DEFAULT_SCREEN_HEIGHT)
{

	APPLICATION = this;
	initialize_success = false;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER | SDL_INIT_HAPTIC | SDL_INIT_JOYSTICK | SDL_INIT_TIMER) < 0)
	{
		initialize_success = false;
	}

	else
	{
		std::cout << "New Application" << std::endl;
		//Use OpenGL 3.3 core
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
		SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

		//Create a window with OpenGL
		pWindow = SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			ScreenWidth, ScreenHeight, SDL_WINDOW_OPENGL);

		if (pWindow == nullptr)
		{
			initialize_success = false;
		}
		else
		{
			//Create context
			glContext = SDL_GL_CreateContext(pWindow);
			SDL_GL_SetSwapInterval(true);
			if (glContext == NULL)
			{
				initialize_success = false;
			}
		}
	}


}

Application::~Application()
{
	std::cout << "Destruct Application" << std::endl;
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(pWindow);
	pWindow = nullptr;

	SDL_Quit();
}

void Application::Init()
{
	std::cout << "Initialize Application" << std::endl;
}

void Application::Update()
{
	Input::GetInstance().Reset();
	PollEvents();
}

void Application::PollEvents()
{
	while (SDL_PollEvent(&SDLevent) != 0)
	{
		PollWindowEvent(SDLevent);
		PollKeyboardEvent(SDLevent);
		PollMouseEvent(SDLevent);
	}
}

void Application::PollWindowEvent(SDL_Event& currentEvent)
{
	if (currentEvent.type == SDL_WINDOWEVENT)
	{
		SDL_GetWindowSize(pWindow, &ScreenWidth, &ScreenHeight);
	}
	else if (currentEvent.type == SDL_QUIT)
	{
		ENGINE->Quit();
	}
}

void Application::PollKeyboardEvent(SDL_Event& currentEvent)
{
	if (currentEvent.type == SDL_KEYDOWN || currentEvent.type == SDL_KEYUP)
	{
		Input::GetInstance().SetKeyPressed(currentEvent.key.keysym.scancode, (SDL_EventType)currentEvent.type);
	}
}

void Application::PollMouseEvent(SDL_Event& currentEvent)
{
	if (currentEvent.type == SDL_MOUSEBUTTONDOWN || currentEvent.type == SDL_MOUSEBUTTONUP)
	{
		Input::GetInstance().SetMousePressed(currentEvent.button.button, (SDL_EventType)currentEvent.type);
	}
}

