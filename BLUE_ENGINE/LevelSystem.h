/*
*  SUMMER VACATION
*  Choi Jinwoo
*  2018/07/02
*  BLUE ENGINE
*/
#pragma once

class LevelSystem
{
public:

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Close() = 0;
	virtual ~LevelSystem()
	{
	}
};
