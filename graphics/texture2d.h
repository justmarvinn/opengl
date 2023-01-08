#pragma once

#include <string>

#include <glad/glad.h>
#include <SOIL2.h>

namespace jengine::graphics
{
    class texture2d
    {
        public:
            texture2d();
            ~texture2d();
            void loadImageRGB(std::string filename, unsigned int channel=0);
            void loadImageRGBA(std::string filename, unsigned int channel=0);
            void use();
            static void useNoTexture();
            unsigned int channel();

        private:
            unsigned int _id;
            int _width, _height;
            unsigned char* _data;
            unsigned int _channel;
    };
}
