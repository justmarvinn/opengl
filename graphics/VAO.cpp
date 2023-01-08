#include "VAO.h"

using namespace jengine::graphics;

VAO::VAO()
{
    glGenVertexArrays(1, &_id);
}

VAO::~VAO()
{
    glDeleteVertexArrays(1, &_id);
}

void VAO::_bind()
{
    glBindVertexArray(_id);
}

void VAO::_unbind()
{
    glBindVertexArray(0);
}

void VAO::setVertexAttribute(
        VBO* vboptr,
        unsigned int index,
        int size,
        int stride,
        int offset,
        bool needNormalize
) {
    _bind();
    vboptr->use();
    glVertexAttribPointer(index, size, GL_FLOAT, needNormalize, stride * sizeof(GL_FLOAT), (void*)(offset*sizeof(GL_FLOAT)));
    glEnableVertexAttribArray(index);
    _unbind();
}

void VAO::setVertexAttribute(
        VBO* vboptr,
        EBO* eboptr,
        unsigned int index,
        int size,
        int stride,
        int offset,
        bool needNormalize
) {
    _bind();
    vboptr->use();
    eboptr->use();
    glVertexAttribPointer(index, size, GL_FLOAT, needNormalize, stride * sizeof(GL_FLOAT), (void*)(offset*sizeof(GL_FLOAT)));
    glEnableVertexAttribArray(index);
    _unbind();
}

void VAO::renderVBO(VBO* vboptr, unsigned int numVertices)
{
    _bind();
    vboptr->use();
    glDrawArrays(GL_TRIANGLES, 0, numVertices);
    _unbind();
}

void VAO::renderVBO(VBO* vboptr)
{
    _bind();
    vboptr->use();
    glDrawArrays(GL_TRIANGLES, 0, vboptr->size());
    _unbind();
}

void VAO::renderEBO(EBO* eboptr, unsigned int numVertices, unsigned int offset)
{
    _bind();
    eboptr->use();
    glDrawElements(GL_TRIANGLES, numVertices, GL_UNSIGNED_INT, (void*)(offset*sizeof(unsigned int))); 
    _unbind();
}

void VAO::renderEBO(EBO* eboptr)
{
    _bind();
    eboptr->use();
    glDrawElements(GL_TRIANGLES, eboptr->size(), GL_UNSIGNED_INT, (void*)0);
    _unbind();
}
