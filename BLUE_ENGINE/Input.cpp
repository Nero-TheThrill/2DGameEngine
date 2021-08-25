/*
*  SUMMER VACATION
*  Choi Jinwoo
*  2018/06/29
*  BLUE ENGINE
*/
#include"Input.h"
namespace
{
    std::bitset<SDL_NUM_SCANCODES> keypressed;
    std::bitset<SDL_NUM_SCANCODES> keytriggered;
    std::bitset<SDL_NUM_SCANCODES> keyreleased;
    glm::vec2 mousePos;
    std::bitset<NUM_MOUSECODE> mousepressed;
    std::bitset<NUM_MOUSECODE> mousetriggered;
    std::bitset<NUM_MOUSECODE> mousedoubleclick;
    std::bitset<NUM_MOUSECODE> mousereleased;
}
void Input::Reset(void) {
    keyreleased.reset();
    keytriggered.reset();
	mousereleased.reset();
	mousetriggered.reset();
}
void Input::SetKeyPressed(SDL_Scancode key, SDL_EventType eType)
{
    if(eType==SDL_KEYDOWN)
    {
        keypressed.set(key);
        keytriggered.set(key);
    }
    else if (eType == SDL_KEYUP)
    {
        keyreleased.set(key);
        keypressed.reset(key);
    }
}


bool Input::IsKeyPressed(SDL_Scancode key)
{
    return keypressed[key];
}

bool Input::IsKeyTriggered(SDL_Scancode key)
{
    return keytriggered[key];
}

bool Input::IsKeyReleased(SDL_Scancode key)
{
    return keyreleased[key];
}

bool Input::IsAnyKeyPressed()
{
    return keypressed.any();
}

bool Input::IsAnyKeyTriggered()
{
    return keytriggered.any();
}

bool Input::IsAnyKeyReleased()
{
    return keyreleased.any();
}

void Input::SetMousePos(float x, float y)
{
    x, y;
}

glm::vec2 Input::GetMousePos()
{
    return { 0,0 };
}

void Input::SetMousePressed(int mButton, SDL_EventType eMouseButton)
{
    if (eMouseButton == SDL_MOUSEBUTTONDOWN)
    {
        mousepressed.set(mButton);
        mousetriggered[mButton] = true;
    }
    else if (eMouseButton == SDL_MOUSEBUTTONUP)
    {
        mousereleased.set(mButton);
        mousepressed.reset(mButton);
    }
}

bool Input::IsMousePressed(int key)
{
    return mousepressed[key];
}

bool Input::IsMouseTriggered(int key)
{
    return mousetriggered[key];
}

bool Input::IsMouseDoubleClicked(int key)
{
    key;
    return false;
}

bool Input::IsMouseReleased(int key)
{
    return mousereleased[key];
}
