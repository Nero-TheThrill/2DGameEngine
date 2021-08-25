/*
*  Choi Jinwoo
*  2019/06/26
*  BLUE ENGINE
*/

#pragma once
#include <glm/glm.hpp>
#include "Component.h"


class Transform : public Component
{
public:
	Transform();
	~Transform() override;

	void Init() override;
	glm::vec2 GetTranslation() const;
	void SetTranslation(const glm::vec2 new_translation);

	glm::vec2 GetScale() const;
	void SetScale(const glm::vec2 new_scale);

private:
	glm::vec2 translation{};
	glm::vec2 scale{};
};
