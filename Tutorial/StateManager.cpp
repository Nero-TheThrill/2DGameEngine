/*
*  SUMMER VACATION
*  Choi Jinwoo
*  2018/07/02
*  BLUE ENGINE
*/
#include "StateManager.h"
#include "TestLevel1.h"
#include "TestLevel2.h"

StateManager* STATEMANAGER = nullptr;
StateManager::StateManager()
{
	STATEMANAGER = this;
}
StateManager::~StateManager()
{
}
void StateManager::Init()
{
	current = LV_TEST1;
	levels.push_back(new Level1());
	levels.push_back(new Level2());
	levels.at(current)->Init();
}
void StateManager::Update()
{
	levels.at(current)->Update();
}

void StateManager::ChangeLevel(GameLevels changeLV)
{
	current = changeLV;
	levels.at(current)->Init();
}

