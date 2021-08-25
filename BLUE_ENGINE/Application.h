/*
*  SUMMER VACATION
*  Choi Jinwoo
*  2018/06/28
*  BLUE ENGINE
*/
#pragma once
#include "System.h"
#include <SDL.h>
#include "Input.h"


class Application : public System
{
public:
	Application();
	~Application();

	void Init() override;
	void Update() override;


	SDL_Window* GetWindow() { return pWindow; }
	SDL_Event& GetEvent() { return SDLevent; }

private:
	//Get events
	/////////////////////////////////////////////////
	void PollEvents();
	void PollWindowEvent(SDL_Event& currentEvent);
	void PollKeyboardEvent(SDL_Event& currentEvent);
	void PollMouseEvent(SDL_Event& currentEvent);
	/////////////////////////////////////////////////



	SDL_Event SDLevent;
	SDL_Window* pWindow;
	int ScreenWidth;
	int ScreenHeight;
	bool initialize_success;
	SDL_GLContext glContext = NULL;
};
