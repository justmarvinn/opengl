#include <iostream>
#include <string>
#include <array>
#include <random>
#include <vector>

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

    texture2d tex1;
    tex1.loadImageRGB("../res/textures/smile.png", 0);
    texture2d tex2;
    tex2.loadImageRGB("../res/textures/container.jpg", 1);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-1.0f, 1.0f);

    std::vector<glm::mat4> models;
    for (int i=0; i<5; i++) {
        glm::vec3 pos(dist(gen), dist(gen), dist(gen));
        float angle = utils::map((float)(dist(gen)), -1.0f, 1.0f, 0.0f, 180.0f);
        glm::vec3 rot(dist(gen), dist(gen), dist(gen));

        glm::mat4 model(1);
        model = glm::translate(model, pos);
        model = glm::rotate(model, glm::radians(angle), glm::normalize(rot));
        models.push_back(model);
    }

    camera::setTarget(glm::vec3(0));

    while (!jengine::window::isShouldClose()) {
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        float t = (float)(glfwGetTime());
        float r = 2;

        camera::setPosition(glm::vec3(sin(t)*r, 0, cos(t)*r));
        
        shader.use();
        shader.setUniform("uTime", t);
        shader.setUniform("view", camera::viewMatrix());
        shader.setUniform("projection", camera::projectionMatrix());
        shader.setUniformTexture("tex1", tex1);
        shader.setUniformTexture("tex2", tex2);

        for (auto& m : models) {
            shader.setUniform("model", m);
            vao.renderVBO(&vbo);
        }

        /* if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) */
        /*     glfwSetWindowShouldClose(window, true); */
        camera::update();
        jengine::window::update();
    }
    jengine::stop();
    return 0;
}

