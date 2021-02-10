#include "VAO.h"

VAO::VAO(GLenum primitive, GLsizei verticesPerPrimitive)
{
    _primitive = primitive;
    _verticesPerPrimitive = verticesPerPrimitive;
    glGenVertexArrays(1, &_vaoId);
}

VAO::~VAO() 
{
    glDeleteBuffers(_vbos.size(), _vbos.data());
    glDeleteVertexArrays(1, &_vaoId);
    
}

void VAO::_Bind() 
{
    glBindVertexArray(_vaoId);
}

void VAO::_Unbind() 
{
    glBindVertexArray(0);
}

void VAO::addVBO(const std::vector<float> data)
{
    _Bind();

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(_vbos.size(), 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    _vbos.push_back(vbo);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    VAO::_Unbind();
}

void VAO::Render()
{
    _Bind();
    for (std::size_t i = 0; i < _vbos.size(); i++)
        glEnableVertexAttribArray(i);

    glDrawArrays(_primitive, 0, _verticesPerPrimitive);

    for (std::size_t i = 0; i < _vbos.size(); i++)
        glDisableVertexAttribArray(i);
}
