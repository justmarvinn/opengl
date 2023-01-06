#pragma once

#include <iostream>
#include <string>
#include <vector>

#include <glad/glad.h>

#include "utils.h"

namespace jengine::graphics
{
    class ShaderProgram
    {
        public:
            ShaderProgram();
            ~ShaderProgram();
            void link();
            void addSource(std::string filename);
            void use();
            static void useNoShader();

            void setUniform(std::string name, float x);
            void setUniform(std::string name, float x, float y);
            void setUniform(std::string name, float x, float y, float z);
            void setUniform(std::string name, float x, float y, float z, float w);

            void setUniform(std::string name, int x);
            void setUniform(std::string name, int x, int y);

        private:
            unsigned int _id;
            std::vector<unsigned int> _shaders;
    };
}
