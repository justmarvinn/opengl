#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "graphics/camera.h"
#include "window.h"

namespace jengine
{
    bool init();
    void stop();
}

void init_glfw();
void init_glad();
void init_opengl();

void glfw_error_callback(int err, const char* description);
