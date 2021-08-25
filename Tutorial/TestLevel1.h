/*
*  SUMMER VACATION
*  Choi Jinwoo
*  2018/07/01
*  BLUE ENGINE
*/
#pragma once
#include "LevelSystem.h"
#include "Object.h"

class Level1 : public LevelSystem
{
public:
	Level1() {};
	void Init() override;
	void Update() override;
	void Close() override;
	~Level1() {};
private:
	int key_clicked; //count key press
	int mouse_clicked; //count mouse press
	Object* obj, *player;
	bool up, down, left, right;
};
