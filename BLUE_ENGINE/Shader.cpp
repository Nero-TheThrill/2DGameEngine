/*
*  Hyun Jina
*
*  Do not use this code for your engine
*  Make your own code.
*
*/


#include "Shader.h"
#include <stdio.h>
#include <vector>
#include <glm/gtc/type_ptr.hpp>

const char * VertexShader =
"#version 330 core\n"
"layout(location = 0) in vec3 aPos;\n"
"layout(location = 1) in vec3 aColor;\n"
"uniform mat4 camera;\n"
"out vec3 ourColor;\n"
"void main()\n"
"{\n"
"    gl_Position = (camera * vec4(aPos, 1.0));\n"
"    ourColor = aColor;\n"
"}\n\0";

const char * FragmentShader =
"#version 330 core\n"
"out vec4 FragColor;\n"
"in vec3 ourColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(ourColor, 1.0);\n"
"}\n\0";

Shader::Shader() : programID_(0), numAttributes_(0) {}

Shader::~Shader()
{
	// glDeleteShader(vertexShaderID);
	// glDeleteShader(fragmentShaderID);
}

void Shader::compileShaders()
{
	programID_ = glCreateProgram();

	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	if (vertexShaderID == NULL)
		printf("Graphic_Error: Vertex shader failed to created!\n");

	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	if (fragmentShaderID == NULL)
		printf("Graphic_Error: Fragment shader failed to created!\n");

	/* default file location == Tutrial folder */
	compileShader(vertexShaderID, VertexShader);
	compileShader(fragmentShaderID, FragmentShader);

	linkShaders();
}

void Shader::addAttribute(const std::string& attributeName)
{
	glBindAttribLocation(programID_, numAttributes_++, attributeName.c_str());
}

void Shader::linkShaders()
{
	glAttachShader(programID_, vertexShaderID);
	glAttachShader(programID_, fragmentShaderID);

	glLinkProgram(programID_);

	GLint isLinked = NULL;
	glGetProgramiv(programID_, GL_LINK_STATUS, &isLinked);

	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(programID_, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<char> errorLog(maxLength);
		glGetShaderInfoLog(programID_, maxLength, &maxLength, &errorLog[0]);

		glDeleteShader(programID_);
		glDeleteShader(vertexShaderID);
		glDeleteShader(fragmentShaderID);

		printf("%s\n", &(errorLog[0]));
		printf("Shader_Error: fail to link!\n");
	}
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
}

GLint Shader::getUniformLocation(const std::string& uniformName)
{
	GLint location = glGetUniformLocation(programID_, uniformName.c_str());
	if (location == GL_INVALID_INDEX)
		printf("Shader_Error: could not find uniform in shader!\n");
	return location;
}

void Shader::SendUniformVariable(const std::string& name, const glm::vec3 vec3)
{
	glUniform3fv(getUniformLocation(name), 1, &vec3[0]);
}

void Shader::SendUniformVariable(const std::string& name, const glm::vec4 vec4)
{
	glUniform4fv(getUniformLocation(name.c_str()), 1, &vec4[0]);
}

void Shader::SendUniformVariable(const std::string& name, const glm::mat4 mat4)
{
	glUniformMatrix4fv(getUniformLocation(name.c_str()), 1, GL_FALSE, &(mat4[0][0]));
}

void Shader::use()
{
	glUseProgram(programID_);
	for (int i = 0; i < numAttributes_; i++)
	{
		glEnableVertexAttribArray(i);
	}
}

void Shader::unuse()
{
	glUseProgram(0);
	for (int i = 0; i < numAttributes_; i++)
	{
		glDisableVertexAttribArray(i);
	}
}

void Shader::compileShader(GLuint id, const char * contentSource)
{
	glShaderSource(id, 1, &contentSource, NULL);
	glCompileShader(id);

	GLint isCompiled = NULL;
	glGetShaderiv(id, GL_COMPILE_STATUS, &isCompiled);

	// check if fail 
	if (isCompiled == false)
	{
		GLint maxLength = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<char> errorLog(maxLength);
		glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

		glDeleteShader(id);

		printf("%s\n", &(errorLog[0]));
		printf("Shader_Error: fail to compile!\n");
	}
}
