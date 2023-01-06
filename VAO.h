#pragma once

#include <vector>
#include <array>

#include "VBO.h"
#include "EBO.h"

namespace jengine::graphics
{
    class VAO
    {
        /* friend VBO; */
        public:
            VAO();
            /* VAO(VBO* vbo); */
            ~VAO();
            /* VBO* createVBO(); */
            /* EBO* createEBO(); */
            void renderVBO(VBO* vboptr, unsigned int numVertices);
            void renderEBO(EBO* eboptr, unsigned int numVertices, unsigned int offset=0);
            void setVertexAttribute(
                    VBO* vboptr,
                    unsigned int index,
                    int size,
                    int stride,
                    int offset=0,
                    bool needNormalize=false
            );
            void setVertexAttribute(
                    VBO* vboptr,
                    EBO* eboptr,
                    unsigned int index,
                    int size,
                    int stride,
                    int offset=0,
                    bool needNormalize=false
            );

            /* template<typename T, std::size_t N> */
            /* void setData(VBO* vboptr, const std::array<T, N>& data) */
            /* { */
            /*     vboptr->use(); */
            /*     glBufferData(GL_ARRAY_BUFFER, sizeof(data), &data, GL_STATIC_DRAW); */
            /*     /1* vboptr->useNoVBO(); *1/ */
            /* } */

            /* template<typename T, std::size_t N> */
            /* void setData(EBO* eboptr, const std::array<T, N>& data) */
            /* { */
            /*     eboptr->use(); */
            /*     glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(data), &data, GL_STATIC_DRAW); */
            /*     /1* vboptr->useNoVBO(); *1/ */
            /* } */

        private:
            unsigned int _id;
            /* std::vector<VBO*> _VBOs; */
            /* std::vector<EBO*> _EBOs; */

            void _bind();
            static void _unbind();
    };
}
