#include "VBO.h"

using namespace jengine::graphics;

VBO::VBO()
{
    glGenBuffers(1, &_id);
}

VBO::~VBO()
{
    glDeleteBuffers(1, &_id);
}

void VBO::use()
{
    glBindBuffer(GL_ARRAY_BUFFER, _id);
}

void VBO::useNoVBO()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

std::size_t VBO::size()
{
    return _size;
}
