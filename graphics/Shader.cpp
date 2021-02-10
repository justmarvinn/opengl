#include "Shader.h"

Shader::Shader()
{
	_id = glCreateProgram();
}

Shader::~Shader() 
{
	glDeleteProgram(_id);
}

void Shader::addSource(const char* filename) 
{
	GLuint shaderId;
	if (Utils::ParseFormat(filename) == ".vert")
		shaderId = glCreateShader(GL_VERTEX_SHADER);
	else if (Utils::ParseFormat(filename) == ".frag")
		shaderId = glCreateShader(GL_FRAGMENT_SHADER);
	else {
		std::cerr << "Unknown shader file extension" << std::endl;
		return;
	}
	std::string shaderCode = Utils::ParseText(filename);
	if (shaderCode == "") {
		std::cerr << "Shader source is empty or does not exist" << std::endl;
		return;
	}
	const char* code = shaderCode.c_str();
	glShaderSource(shaderId, 1, &code, nullptr);
	glCompileShader(shaderId);

	GLint status;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &status);
	if(status == GL_FALSE) {
		GLint length;
		glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &length);
		GLchar info[length];
		glGetShaderInfoLog(shaderId, length, &length, info);
		std::cerr << "Can not compile shader" << std::endl;
		std::cerr << info << std::endl;
	} else
		glAttachShader(_id, shaderId);
	glDeleteShader(shaderId);
}

void Shader::Compile()
{
	glLinkProgram(_id);
	GLint status;
	glGetProgramiv(_id, GL_LINK_STATUS, &status);
    if (status == GL_FALSE) {
		GLint length;
		glGetProgramiv(_id, GL_INFO_LOG_LENGTH, &length);
		GLchar info[length];
		glGetShaderInfoLog(_id, length, &length, info);
		std::cerr << "Can not link shader program" << std::endl;
		std::cerr << info << std::endl;
		glDeleteProgram(_id);
	}
}

void Shader::Use()
{
	glUseProgram(_id);
}

void Shader::StopUsingShader()
{
	glUseProgram(0);
}
