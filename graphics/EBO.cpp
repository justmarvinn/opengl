#include "EBO.h"

using namespace jengine::graphics;

EBO::EBO()
{
    glGenBuffers(1, &_id);
}

EBO::~EBO()
{
    glDeleteBuffers(1, &_id);
}

void EBO::use()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
}

void EBO::useNoEBO()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

std::size_t EBO::size()
{
    return _size;
}
