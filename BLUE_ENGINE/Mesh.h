/*
*  Hyun Jina
*
*  Do not use this code for your engine
*  Make your own code.
*
*/

#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include "Component.h"
#include "Transform.h"


enum class PointListType
{
	Lines,
	LineStrip,
	Triangles,
	TriangleStrip,
	TriangleFan
};

enum class VertexType : int
{
	position,
	positionColor,
	count
};
struct Color
{
	float r = 1;
	float g = 1;
	float b = 1;
	float a = 1;
};
class Mesh : public Component
{
public:
	Mesh();
	~Mesh() override;

	void Init() override;
	void draw();
	void SetVertex(float x, float y);
	void SetColor(Color color);
	void ChangeColor(Color color);
private:
	std::vector<glm::vec2> vertex_{};
	std::vector<Color> color_{};

	PointListType pointListType_ = PointListType::TriangleFan;

	static const int numberofvertexobjects = static_cast<int>(VertexType::count);
	GLuint vertexBufferObject_[numberofvertexobjects];
	GLuint vertexArrayObject_;

	Transform* transform;
};

namespace mesh
{
	std::vector<glm::vec2> CreateBox(glm::vec2 size);
}



