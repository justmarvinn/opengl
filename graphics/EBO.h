#pragma once

#include <array>
#include <glad/glad.h>

namespace jengine::graphics
{
    class EBO
    {
        public:
            EBO();
            ~EBO();
            void use();
            static void useNoEBO();

            template<typename T, std::size_t N>
            void setData(const std::array<T, N>& data)
            {
                _size = N;
                use();
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, N * sizeof(data[0]), &data, GL_STATIC_DRAW);
                useNoEBO();
            }

            std::size_t size();

        private:
            unsigned int _id;
            std::size_t _size;
    };
}
