#pragma once

#include <iostream>
#include <string>

#include <GLFW/glfw3.h>

namespace jengine {
    class window
    {
        public:
            static void init(const int width, const int height, const std::string title, const bool resizable=false);
            static void close();
            static bool isShouldClose();
            static void update();
            static float aspect();
            //static void setIcon(const char* filename);
        private:
            static GLFWwindow* _window;
            static int _width, _height;

            static void onResize(GLFWwindow* win, int width, int height);
    };
}
