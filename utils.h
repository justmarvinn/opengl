#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <array>

#include "graphics/VBO.h"

namespace utils
{
    std::string parseText(std::string filename);
    std::string parseFormat(std::string filename);

    template<typename T>
    T map(T value, T min1, T max1, T min2, T max2)
    {
        return min2 + (value - min1) * (max2 - min2) / (max1 - min1);
    }

    jengine::graphics::VBO triangleVBO();
    jengine::graphics::VBO quadVBO();
    jengine::graphics::VBO cubeVBO();
}
