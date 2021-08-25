/*
*  Choi Jinwoo
*  2019/06/26
*  BLUE ENGINE
*/

#include "Transform.h"

Transform::Transform() :Component(ComponentType_TRANSFORM)
{
}

Transform::~Transform()
{
}

void Transform::Init()
{
	translation = glm::vec2(0, 0);
	scale = glm::vec2(50, 50);
}

glm::vec2 Transform::GetTranslation() const { return translation; }

void Transform::SetTranslation(const glm::vec2 new_translation)
{
	translation = new_translation;
}

glm::vec2 Transform::GetScale() const { return scale; }

void Transform::SetScale(const glm::vec2 new_scale)
{
	scale = new_scale;
}

