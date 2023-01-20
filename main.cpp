#include <iostream>
#include <string>
#include <array>

#include <glad/glad.h>
#include <glm/ext.hpp>

#include "graphics/graphics.h"
#include "utils.h"
#include "window.h"
#include "setup.h"

using namespace jengine::graphics;

std::array<float, (3+3)*6*6> vertices = {
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 
    -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 

    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
     0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
};

int main(int argc, char* argv[])
{
   if (!jengine::init())
       return -1;

    VAO vao1;
    /* VBO vbo1 = utils::cubeVBO(); */
    VBO vbo1(vertices, 6);
    vao1.setVertexAttribute(&vbo1, 0, 3, 6, 0); // positions
    vao1.setVertexAttribute(&vbo1, 1, 3, 6, 3); // normals
    /* vao1.setVertexAttribute(&vbo1, 0, 3, 5, 0); */
    /* vao1.setVertexAttribute(&vbo1, 1, 2, 5, 3); */
    ShaderProgram shader1(2,
            "../res/shaders/phong.frag",
            "../res/shaders/phong.vert");
    shader1.link();

    VAO vao2;
    VBO vbo2 = utils::cubeVBO();
    /* VBO vbo2(vertices, 3); */
    vao2.setVertexAttribute(&vbo2, 0, 3, 5, 0);
    /* vao2.setVertexAttribute(&vbo2, 1, 2, 5, 3); */
    ShaderProgram shader2(2,
            "../res/shaders/lamp.frag",
            "../res/shaders/lamp.vert");
    shader2.link();

    /* texture2d tex; */
    /* tex.loadImageRGB("../res/textures/capy.jpg", 0); */

    glm::vec3 lightPos(-2.5, 0, 0.5);
    glm::vec3 lightColor(1, 1, 1);
    glm::vec3 objColor(1, 0.5f, 0.31f);
    glm::vec3 objPos(2, -1, -0.5);

    glm::mat4 model1(1);
    glm::mat4 model2(1);
    model1 = glm::translate(model1, objPos);
    model2 = glm::translate(model2, lightPos);
    camera::setTarget(glm::vec3(0));
    /* camera::setPerspective(45); */

    while (!jengine::window::isShouldClose()) {
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        float t = (float)(glfwGetTime());
        float r = 2.5;
        camera::setPosition(glm::vec3(sin(t)*r, r, cos(t)*r));
        
        shader1.use();
        shader1.setUniform("model", model1);
        shader1.setUniform("view", camera::viewMatrix());
        shader1.setUniform("projection", camera::projectionMatrix());

        shader1.setUniform("objColor", objColor);
        shader1.setUniform("lightColor", lightColor);
        shader1.setUniform("lightPos", lightPos);
        shader1.setUniform("cameraPos", camera::getPosition());
        shader1.setUniform("ambientStrength", 0.1f);
        shader1.setUniform("specularStrength", 1.f);
        /* shader1.setUniformTexture("tex", tex); */
        vao1.renderVBO(&vbo1);

        shader2.use();
        shader2.setUniform("model", model2);
        shader2.setUniform("view", camera::viewMatrix());
        shader2.setUniform("projection", camera::projectionMatrix());
        shader2.setUniform("lightColor", lightColor);
        vao2.renderVBO(&vbo2);

        /* if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) */
        /*     glfwSetWindowShouldClose(window, true); */
        camera::update();
        jengine::window::update();
    }
    jengine::stop();
    return 0;
}
