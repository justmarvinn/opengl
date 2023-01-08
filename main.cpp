#include <iostream>
#include <string>
#include <array>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <SOIL2.h>

#include "graphics/ShaderProgram.h"
#include "graphics/VAO.h"
#include "graphics/VBO.h"
#include "graphics/EBO.h"
#include "graphics/texture2d.h"

using namespace jengine::graphics;

void framebuffer_size_callback(GLFWwindow* window, int width, int height); 
void error_callback(int err, const char* description);

int main(int argc, char* argv[])
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 800, "hello world", NULL, NULL);
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
    
    glViewport(0, 0, 800, 800);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetErrorCallback(error_callback);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    /* glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); */

    std::array<float, 8*4> vertices = {
         .5, -.5, 0,   1, 0, 0,   1, 0, // bottom right
        -.5, -.5, 0,   0, 1, 0,   0, 0, // bottom left
        -.5,  .5, 0,   0, 0, 1,   0, 1, // top left
         .5,  .5, 0,   1, 1, 0,   1, 1, // top right
    };
    std::array<unsigned int, 3*2> indices = {
        0, 1, 2,
        2, 3, 0,
    };

    std::array<float, 6*3> triangle = {
          0,  .5, 0, 
         .5, -.5, 0,
        -.5, -.5, 0,
    };

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);

    VAO vao;
    VBO vbo = VBO();
    EBO ebo = EBO();
    vbo.setData(vertices);
    ebo.setData(indices);
    vao.setVertexAttribute(&vbo, 0, 3, 8, 0);
    vao.setVertexAttribute(&vbo, 1, 3, 8, 3);
    vao.setVertexAttribute(&vbo, 2, 2, 8, 6);

    ShaderProgram shader(2,
            "../res/shaders/main.vert",
            "../res/shaders/main.frag");
    shader.link();

    texture2d tex1;
    tex1.loadImageRGB("../res/textures/smile.png", 0);

    texture2d tex2;
    tex2.loadImageRGB("../res/textures/container.jpg", 1);

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();
        shader.setUniformTexture("tex1", tex1);
        shader.setUniformTexture("tex2", tex2);
        vao.renderEBO(&ebo);

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
