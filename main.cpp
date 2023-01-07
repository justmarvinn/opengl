#include <iostream>
#include <string>
#include <array>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "graphics/ShaderProgram.h"
#include "graphics/VAO.h"
#include "graphics/VBO.h"
#include "graphics/EBO.h"

using namespace jengine::graphics;

void framebuffer_size_callback(GLFWwindow* window, int width, int height); 
void error_callback(int err, const char* description);

int main(int argc, char* argv[])
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "hello world", NULL, NULL);
    if (window == NULL) {
        std::cerr << "failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return -1;
    }
    
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetErrorCallback(error_callback);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    /* glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); */

    std::array<float, 6*4> vertices = {
         1, -1, 0, 1, 0, 0, // bottom right
        -1, -1, 0, 0, 1, 0,// bottom left
        -1,  1, 0, 0, 0, 1,// top left
         1,  1, 0, 0, 1, 0,// top right
    };
    std::array<unsigned int, 3*2> indices = {
        0, 1, 2,
        2, 3, 0,
    };

    std::array<float, 6*3> triangle = {
          0,  .5, 0, 1, 0, 0,
         .5, -.5, 0, 0, 1, 0,
        -.5, -.5, 0, 0, 0, 1,
    };

    VAO vao;
    VBO vbo = VBO();
    EBO ebo = EBO();
    vbo.setData(vertices);
    ebo.setData(indices);
    vao.setVertexAttribute(&vbo, 0, 3, 6, 0);
    /* vao.setVertexAttribute(&vbo, 1, 3, 6, false, 3); */

    ShaderProgram shader;
    shader.addSource("../shaders/noise.vert");
    shader.addSource("../shaders/noise.frag");
    shader.link();

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();
        int h, w;
        glfwGetWindowSize(window, &w, &h);
        shader.setUniform("screenSize", w, h);
        shader.setUniform("octaves", 1);
        vao.renderEBO(&ebo, 6);

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void error_callback(int err, const char* description)
{
    std::cerr << description << std::endl;
}
