#pragma once

#include <vector>

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GLFW/glfw3.h>

class VAO
{
private:
    GLenum _primitive;
    GLsizei _verticesPerPrimitive;
    GLuint _vaoId;
    std::vector<GLuint> _vbos;

    void _Bind();
    static void _Unbind();

public:
    VAO(GLenum primitive, GLsizei verticesPerPrimitive);
    ~VAO();
    void addVBO(const std::vector<float> data);
    void Render();
};
