/*
*  Hyun Jina
*
*  Do not use this code for your engine
*  Make your own code.
*
*/


#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>


	Camera::Camera() :
		position_(0.0f, 0.0f),
		cameraMatrix_(1.0f),
		scale_(1),
		needMatrixUpdate_(true),
		screenWidth_(1280),
		screenHeight_(720),
		orthoMatrix_(1.0f)
	{
	}

	Camera::~Camera()
	{
	}

	void Camera::Init(int screen_width, int screen_height)
	{
		screenWidth_ = screen_width;
		screenHeight_ = screen_height;
		orthoMatrix_ = glm::ortho(-(float)screenWidth_ / 2.f, (float)screenWidth_ / 2.f, -(float)screenHeight_ / 2.f, (float)screenHeight_ / 2.f);
	}

	void Camera::setPosition(const glm::vec2& newPosition)
	{
		position_ = newPosition;
		needMatrixUpdate_ = true;
	}

	glm::vec2 Camera::getPosition()
	{
		return position_;
	}

	void Camera::SetScale(float newScale)
	{
		scale_ = newScale;
		needMatrixUpdate_ = true;
	}

	float Camera::GetScale()
	{
		return scale_;
	}

	glm::mat4 Camera::getCameraMatrix()
	{
		return cameraMatrix_;
	}

	void Camera::update()
	{
		if (needMatrixUpdate_)
		{
			glm::vec3 translate(-position_.x, -position_.y, 0.0f);
			cameraMatrix_ = glm::translate(orthoMatrix_, translate);

			glm::vec3 scale(scale_, scale_, 0.0f);
			cameraMatrix_ = glm::scale(orthoMatrix_, scale);

			needMatrixUpdate_ = false;
		}
	}
