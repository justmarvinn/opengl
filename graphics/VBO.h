#pragma once

#include <array>
#include <glad/glad.h>

namespace jengine::graphics
{
    class VBO
    {
        public:
            VBO();
            ~VBO();
            template<typename T, std::size_t N>
            void setData(const std::array<T, N>& data)
            {
                use();
                glBufferData(GL_ARRAY_BUFFER, N * sizeof(data[0]), &data, GL_STATIC_DRAW);
                /* useNoVBO(); */
            }
            void use();
            static void useNoVBO();

        private:
            unsigned int _id;

    };
}