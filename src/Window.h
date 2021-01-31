#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <png.h>

struct GLFWwindow;

class Window
{
public:
	static void Initialize(int width, int height, const char* title, bool resizable=false);
	static void Finalize();
	static void Update();
	static bool isShouldClose();
	static void setIcon(const char* filename);

private: 
	static GLFWwindow* _window;
};

