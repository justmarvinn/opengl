#include "VAO.h"

using namespace jengine::graphics;

VAO::VAO()
{
    glGenVertexArrays(1, &_id);
}

VAO::~VAO()
{
    glDeleteVertexArrays(1, &_id);
    /* for (auto vbo : _VBOs) */
    /*     delete vbo; */
    /* for (auto ebo : _EBOs) */
    /*     delete ebo; */
}

void VAO::_bind()
{
    glBindVertexArray(_id);
}

void VAO::_unbind()
{
    glBindVertexArray(0);
}

/* VBO* VAO::createVBO() */
/* { */
/*     _bind(); */
/*     VBO* vbo = new VBO(); */ 
/*     _unbind(); */
/*     _VBOs.push_back(vbo); */
/*     return vbo; */
/* } */

/* EBO* VAO::createEBO() */
/* { */
/*     _bind(); */
/*     EBO* ebo = new EBO(); */
/*     _unbind(); */
/*     _EBOs.push_back(ebo); */
/*     return ebo; */

/* } */

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

void VAO::renderEBO(EBO* eboptr, unsigned int numVertices, unsigned int offset)
{
    _bind();
    eboptr->use();
    glDrawElements(GL_TRIANGLES, numVertices, GL_UNSIGNED_INT, (void*)(offset*sizeof(GL_UNSIGNED_INT))); 
    _unbind();
}
