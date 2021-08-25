/*
*  SUMMER VACATION
*  Choi Jinwoo
*  2018/07/02
*  BLUE ENGINE
*/
#pragma once
#include "LevelSystem.h"

class Level2 : public LevelSystem
{
public:
	Level2() {};
	void Init() override;
	void Update() override;
	void Close() override;
	~Level2() {};
private:
	int key_clicked; //count key press
	int mouse_clicked; //count mouse press
};