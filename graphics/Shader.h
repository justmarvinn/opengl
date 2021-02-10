#pragma once

#define GL_GLEXT_PROTOTYPES

#include <iostream>

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GLFW/glfw3.h>

#include "../Utils.h"

class Shader
{
private:
	GLuint _id;

public:
	Shader();
	Shader(const char* filename);
	~Shader();
	void addSource(const char* filename);
	void Compile();
	void Use();
	static void StopUsingShader();
};
