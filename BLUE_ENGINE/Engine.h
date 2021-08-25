/*
*  SUMMER VACATION
*  Choi Jinwoo
*  2018/06/28
*  BLUE ENGINE
*/
#pragma once
#include<vector>


class System;
class Engine
{
public:
	Engine();
	~Engine();

	void Init();

	//Loop here while GAMERUN is true
	void GameLoop();

	//Stop engine. You can call with using "BLUE::ENGINE->QUIT()"
	void Quit();

	//Add systems like application, stagemanager to update all.
	void AddSystem(System* system);

private:
	std::vector<System*> Systems; //Store systems here and update all.
	bool GAMERUN;  //Check game is running. If it is false, stop the gameloop.
};
extern Engine* ENGINE; // global pointer of the instance of engine.
