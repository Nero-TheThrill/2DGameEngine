/*
*  SUMMER VACATION
*  Choi Jinwoo
*  2018/07/02
*  BLUE ENGINE
*/
#pragma once
#include<vector>
#include "System.h"
#include"LevelSystem.h"

//Define enum to manage levels.
//You have to make sure GameLevels has same order with push_back in Init() function.
enum GameLevels
{
	LV_TEST1,
	LV_TEST2
	//Add here to make more levels. (LV_Main, LV_Tutorial...etc.)
};

//This class manage the state. 
class StateManager : public System
{
public:
	StateManager();
	~StateManager();
	void Init() override;
	void Update() override;

	//You can change level with this function. To call this function, use " BLUE::STATEMANAGER->ChangeLevel(BLUE::<GameLevels>); " in Level class.
	void ChangeLevel(GameLevels changeLV);

	//Store the current level.
	GameLevels current;
	//Store the levels. You can update multiple levels at the same time with using this.
	std::vector<LevelSystem*> levels;
};
extern StateManager* STATEMANAGER;
