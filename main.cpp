#include <iostream>
#include <string>
#include <array>

#include <glm/ext.hpp>

#include "graphics/graphics.h"
#include "utils.h"
#include "window.h"
#include "setup.h"

using namespace jengine::graphics;

int main(int argc, char* argv[])
{
   if (!jengine::init())
       return -1;

    VAO vao;
    VBO vbo = utils::cubeVBO();
    vao.setVertexAttribute(&vbo, 0, 3, 5, 0);
    vao.setVertexAttribute(&vbo, 1, 2, 5, 3);

    ShaderProgram shader(2,
            "../res/shaders/main.vert",
            "../res/shaders/main.frag");
    shader.link();

    texture2d tex;
    tex.loadImageRGB("../res/textures/capy.jpg", 0);

    glm::mat4 model(1);
    /* model = glm::scale(model, glm::vec3(2)); */
    camera::setTarget(glm::vec3(0));

    while (!jengine::window::isShouldClose()) {
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        float t = (float)(glfwGetTime());
        float r = 2;
        camera::setPosition(glm::vec3(sin(t)*r, r, cos(t)*r));
        
        shader.use();
        shader.setUniform("model", model);
        shader.setUniform("view", camera::viewMatrix());
        shader.setUniform("projection", camera::projectionMatrix());
        shader.setUniformTexture("tex", tex);
        vao.renderVBO(&vbo);

        /* if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) */
        /*     glfwSetWindowShouldClose(window, true); */
        camera::update();
        jengine::window::update();
    }
    jengine::stop();
    return 0;
}
