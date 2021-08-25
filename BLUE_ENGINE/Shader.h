/*
*  Hyun Jina
*
*  Do not use this code for your engine
*  Make your own code.
*/



#pragma once
#include <GL/glew.h>
#include <string>
#include <glm/glm.hpp>

class Shader
{
public:
	Shader();
	~Shader();
	void compileShaders();
	void addAttribute(const std::string& attributeName);
	GLint getUniformLocation(const std::string& uniformName);


	//// Uncomment when you need this function
	//void SetVec3(const std::string &name, const glm::vec3 vec3);
	//void SetVec3(const std::string &name, float x, float y, float z);
	//void SetVec4(const std::string &name, const glm::vec3 vec4);
	//void SetVec4(const std::string &name, float x, float y, float z, float w);
	void SendUniformVariable(const std::string& name, const glm::vec3 vec3);

	void SendUniformVariable(const std::string& name, const glm::vec4 vec4);

	void SendUniformVariable(const std::string& name, const glm::mat4 mat4);

	void use();
	void unuse();
private:
	void linkShaders();
	
	void compileShader(GLuint id, const char * contentSource);
	std::string fileContents = "";
	GLuint programID_;
	GLuint vertexShaderID;
	GLuint fragmentShaderID;
	int numAttributes_;
};
