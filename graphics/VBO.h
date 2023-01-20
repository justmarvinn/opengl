#pragma once

#include <array>
#include <glad/glad.h>

namespace jengine::graphics
{
    class VBO
    {
        public:
            VBO(unsigned int valuesPerVertex);

            template<typename T, std::size_t N>
            VBO(const std::array<T, N>& data, unsigned int valuesPerVertex)
            {
                _valuesPerVertex = valuesPerVertex;
                _size = N;
                glGenBuffers(1, &_id);
                setData(data);
            }

            ~VBO();

            template<typename T, std::size_t N>
            void setData(const std::array<T, N>& data)
            {
                _size = N;
                use();
                glBufferData(GL_ARRAY_BUFFER, N * sizeof(data[0]), &data, GL_STATIC_DRAW);
                useNoVBO();
            }

            void use();
            static void useNoVBO();
            std::size_t size();
            unsigned int valuesPerVertex();

        private:
            unsigned int _id;
            unsigned int _valuesPerVertex;
            std::size_t _size;
    };
}
