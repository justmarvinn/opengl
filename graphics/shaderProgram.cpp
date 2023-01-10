#include "shaderProgram.h"

using namespace jengine::graphics;

ShaderProgram::ShaderProgram()
{
    _id = glCreateProgram();
}

ShaderProgram::ShaderProgram(unsigned int numShaders, ...) //, std::string filename, ...)
{
    _id = glCreateProgram();
    va_list args;
    va_start(args, numShaders);
    while (numShaders--) {
        addSource(va_arg(args, const char*));
    }
    va_end(args);
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(_id);
    for (auto s : _shaders)
        glDeleteShader(s);
}

void ShaderProgram::addSource(std::string filename) 
{
	unsigned int shaderId;
    std::string extension = utils::parseFormat(filename);
	if (extension == ".vert")
		shaderId = glCreateShader(GL_VERTEX_SHADER);
	else if (extension == ".frag")
		shaderId = glCreateShader(GL_FRAGMENT_SHADER);
	else {
		std::cerr << "Unknown shader file extension: " << extension << std::endl;
		return;
	}
	std::string shaderCode = utils::parseText(filename);
	if (shaderCode == "") {
		std::cerr << "Shader source is empty or does not exist: " << filename << std::endl;
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
		std::cerr << "Can not compile " << filename <<  " shader" << std::endl;
		std::cerr << info << std::endl;
	} else {
		glAttachShader(_id, shaderId);
        _shaders.push_back(shaderId);
    }
	glDeleteShader(shaderId);
}

void ShaderProgram::link()
{
	glLinkProgram(_id);
	GLint status;
	glGetProgramiv(_id, GL_LINK_STATUS, &status);
    if (status == GL_FALSE) {
		GLint length;
		glGetProgramiv(_id, GL_INFO_LOG_LENGTH, &length);
		GLchar info[length];
		glGetShaderInfoLog(_id, length, &length, info);
		std::cerr << "Can not link shader program\n";
		std::cerr << info << std::endl;
		glDeleteProgram(_id);
	}
    for (auto s : _shaders)
        glDeleteShader(s);
}

void ShaderProgram::use()
{
	glUseProgram(_id);
}

void ShaderProgram::useNoShader()
{
	glUseProgram(0);
}

void ShaderProgram::setUniform(std::string name, float x)
{
    int location = glGetUniformLocation(_id, name.c_str());
    /* if (location == -1) { */
    /*     std::cerr << "Cannot find uniform by name " << name << std::endl; */
    /*     return; */
    /* } */
    glUniform1f(location, x);
}

void ShaderProgram::setUniform(std::string name, float x, float y)
{
    int location = glGetUniformLocation(_id, name.c_str());
    /* if (location == -1) { */
    /*     std::cerr << "Cannot find uniform by name " << name << std::endl; */
    /*     return; */
    /* } */
    glUniform2f(location, x, y);
}

void ShaderProgram::setUniform(std::string name, float x, float y, float z)
{
    int location = glGetUniformLocation(_id, name.c_str());
    /* if (location == -1) { */
    /*     std::cerr << "Cannot find uniform by name " << name; */
    /*     return; */
    /* } */
    glUniform3f(location, x, y, z);
}

void ShaderProgram::setUniform(std::string name, float x, float y, float z, float w)
{
    int location = glGetUniformLocation(_id, name.c_str());
    /* if (location == -1) { */
    /*     std::cerr << "Cannot find uniform by name " << name << std::endl; */
    /*     return; */
    /* } */
    glUniform4f(location, x, y, z, w);
}

void ShaderProgram::setUniform(std::string name, int x)
{
    int location = glGetUniformLocation(_id, name.c_str());
    /* if (location == -1) { */
    /*     std::cerr << "Cannot find uniform by name " << name << std::endl; */
    /*     return; */
    /* } */
    glUniform1i(location, x);
}

void ShaderProgram::setUniform(std::string name, int x, int y)
{
    int location = glGetUniformLocation(_id, name.c_str());
    /* if (location == -1) { */
    /*     std::cerr << "Cannot find uniform by name " << name << std::endl; */
    /*     return; */
    /* } */
    glUniform2i(location, x, y);
}

void ShaderProgram::setUniform(std::string name, glm::mat4& mat, bool needTransparent)
{
    int location = glGetUniformLocation(_id, name.c_str());
    glUniformMatrix4fv(location, 1, needTransparent, glm::value_ptr(mat));
}

void ShaderProgram::setUniformTexture(std::string name, texture2d& texture)
{
    texture.use();
    int location = glGetUniformLocation(_id, name.c_str());
    glUniform1i(location, texture.channel());
}
