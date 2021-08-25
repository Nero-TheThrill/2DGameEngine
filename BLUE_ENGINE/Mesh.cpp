/*
*  Hyun Jina
*  
*  Do not use this code for your engine
*  Make your own code.
*  
*/

#include "Mesh.h"
#include "Object.h"
#include "Graphics.h"
#include <glm/gtc/matrix_transform.hpp>


GLenum GetDrawMode(PointListType pointListType)
{
	switch (pointListType)
	{
	case PointListType::Lines:
		return GL_LINES;
	case PointListType::LineStrip:
		return GL_LINE_STRIP;
	case PointListType::Triangles:
		return GL_TRIANGLES;
	case PointListType::TriangleStrip:
		return GL_TRIANGLE_STRIP;
	case PointListType::TriangleFan:
		return GL_TRIANGLE_FAN;
	default:
		return GL_POINTS;
	}
}
Mesh::Mesh() : Component(ComponentType_MESH), vertexArrayObject_(0)
{
	for (int i = 0; i < numberofvertexobjects; i++)
		vertexBufferObject_[i] = 0;
	transform = nullptr;
	vertex_.clear();
	color_.clear();
}

Mesh::~Mesh()
{
	glDeleteBuffers(numberofvertexobjects, vertexBufferObject_);
}

void Mesh::Init()
{
	transform = (Transform*)GetOwner()->transform;

	vertex_ = mesh::CreateBox(transform->GetScale());
	SetColor({ 255, 0, 0, 255 });

	glGenVertexArrays(1, &vertexArrayObject_);
	glBindVertexArray(vertexArrayObject_);

	if (vertexBufferObject_[0] == 0)
		glGenBuffers(1, &vertexBufferObject_[0]);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject_[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * vertex_.size(), &vertex_.at(0), GL_DYNAMIC_DRAW);

	if (vertexBufferObject_[1] == 0)
		glGenBuffers(1, &vertexBufferObject_[1]);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject_[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Color)*color_.size(), &color_.at(0), GL_DYNAMIC_DRAW);
}

void Mesh::draw()
{
	SetVertex(transform->GetTranslation().x, transform->GetTranslation().y);

	/* Position */
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject_[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * vertex_.size(), &vertex_.at(0), GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(glm::vec2), (void*)0);
	glEnableVertexAttribArray(0);

	/* Color */
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject_[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Color) * color_.size(), &color_.at(0), GL_DYNAMIC_DRAW);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (void*)0);
	glEnableVertexAttribArray(1);

	glDrawArrays(GetDrawMode(pointListType_), 0, static_cast<GLsizei>(vertex_.size()));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Mesh::SetVertex(float x, float y)
{
	vertex_.at(0) = { x + transform->GetScale().x / 2, y - transform->GetScale().y / 2 };
	vertex_.at(1) = { x + transform->GetScale().x / 2, y + transform->GetScale().y / 2 };
	vertex_.at(2) = { x - transform->GetScale().x / 2, y + transform->GetScale().y / 2 };
	vertex_.at(3) = { x - transform->GetScale().x / 2, y - transform->GetScale().y / 2 };
	vertex_.at(4) = { x + transform->GetScale().x / 2, y - transform->GetScale().y / 2 };
}

void Mesh::ChangeColor(Color color)
{
	for (size_t i = 0; i < color_.size(); ++i)
	{
		color_.at(i) = color;
	}
}

void Mesh::SetColor(Color color)
{
	for (size_t i = 0; i < vertex_.size(); ++i)
	{
		color_.push_back(color);
	}
}

std::vector<glm::vec2> mesh::CreateBox(glm::vec2 size)
{
	std::vector<glm::vec2> vertex_{};

	vertex_.push_back(glm::vec2{ +size.x, -size.y });
	vertex_.push_back(glm::vec2{ +size.x, +size.y });
	vertex_.push_back(glm::vec2{ -size.x, +size.y });
	vertex_.push_back(glm::vec2{ -size.x, -size.y });
	vertex_.push_back(glm::vec2{ +size.x, -size.y });

	return vertex_;
}
