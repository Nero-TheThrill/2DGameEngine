/*
*  Hyun Jina
*
*  Do not use this code for your engine
*  Make your own code.
*/


#pragma once
#include <glm/glm.hpp>

	class Camera
	{
	public:
		Camera();
		~Camera();

		void Init(int screen_width, int screen_height);

		void setPosition(const glm::vec2& newPosition);
		glm::vec2 getPosition();

		void SetScale(float newScale);
		float GetScale();

		glm::mat4 getCameraMatrix();

		void update();

	private:
		int screenWidth_, screenHeight_;
		bool needMatrixUpdate_;

		glm::vec2 position_;
		glm::mat4 cameraMatrix_;

		float scale_;
		glm::mat4 orthoMatrix_;
	};
