/*
*  SUMMER VACATION
*  Choi Jinwoo
*  2018/06/28
*  BLUE ENGINE
*/
#pragma once
class System
{
public:
	//Initialize the System
	virtual void Init() = 0;

	//All Systems are updated every frame
	virtual void Update() = 0;

	//All Systems need a virtual destructor to their destructors called
	virtual ~System()
	{
	}
};

;