#pragma once
#define GL_GLEXT_PROTOTYPES

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GLFW/glfw3.h>

#include <iostream>

class Window
{
public:
	static void Initialize(int width, int height, const char* title, bool resizable=false);
	static void Finalize();
	static bool isShouldClose();
	static void Update();
	//static void setIcon(const char* filename);
private:
	static GLFWwindow* _window;
	static void onResize(GLFWwindow* win, int width, int height);
};
