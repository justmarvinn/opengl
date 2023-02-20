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

std::array<float, (3+3+2)*6*6>vertices = {
    // positions          // normals           // texture coords
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
};

int main(int argc, char* argv[])
{
   if (!jengine::init())
       return -1;

    VAO vao1;
    /* VBO vbo1 = utils::cubeVBO(); */
    /* vao1.setVertexAttribute(&vbo1, 0, 3, 5, 0); */
    VBO vbo1(vertices, 3+3+2);
    vao1.setVertexAttribute(&vbo1, 0, 3, 8, 0); // positions
    vao1.setVertexAttribute(&vbo1, 1, 3, 8, 3); // normals
    vao1.setVertexAttribute(&vbo1, 2, 2, 8, 6); // tex coords
    ShaderProgram shader1(2,
            "../res/shaders/phong.frag",
            "../res/shaders/phong.vert");
    shader1.link();

    /* VAO vao2; */
    /* VBO vbo2 = utils::cubeVBO(); */
    /* vao2.setVertexAttribute(&vbo2, 0, 3, 5, 0); */
    /* ShaderProgram shader2(2, */
    /*         "../res/shaders/lamp.frag", */
    /*         "../res/shaders/lamp.vert"); */
    /* shader2.link(); */

    glm::vec3 objPos(0, 0, 0);
    glm::mat4 model1(1);
    model1 = glm::translate(model1, objPos);
    model1 = glm::rotate(model1, glm::radians(45.0f), glm::vec3(0.76, 0.3, 0.0));

    /* glm::mat4 model2(1); */
    /* model2 = glm::translate(model2, lightPos); */
    /* model2 = glm::scale(model2, glm::vec3(0.1)); */

    Point light = Point();

    camera::setPosition(glm::vec3(1.5, 0, 1.5));
    camera::setTarget(glm::vec3(0));
    /* camera::setPerspective(45); */

    shader1.use();
    texture2d diffuse_map = texture2d();
    texture2d specular_map = texture2d();
    /* texture2d emission = texture2d(); */
    diffuse_map.loadImageRGB("../res/textures/container_diffuse_map.png", 0);
    specular_map.loadImageRGB("../res/textures/container_specular_map.png", 1);
    /* emission.loadImageRGB("../res/textures/matrix.jpg", 2); */
    shader1.setUniformTexture("material.diffuse", diffuse_map); 
    shader1.setUniformTexture("material.specular", specular_map);
    shader1.setUniform("material.shininess", 32);
    /* shader1.setUniformTexture("emission", emission); */

    shader1.setUniform("point.ambient", light.getAmbient());
    shader1.setUniform("point.diffuse", light.getDiffuse());
    shader1.setUniform("point.specualr", light.getSpecular());

    shader1.setUniform("cameraPos", camera::getPosition());

    while (!jengine::window::isShouldClose()) {
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        float t = (float)(glfwGetTime());
        float r = 1;
        light.setPosition(glm::vec3(r*cos(t), 0, r*sin(t)));

        shader1.use();
        shader1.setUniform("model", model1);
        shader1.setUniform("view", camera::viewMatrix());
        shader1.setUniform("projection", camera::projectionMatrix());
        shader1.setUniform("point.pos", light.getPosition());
        vao1.renderVBO(&vbo1);

        /* shader2.use(); */
        /* shader2.setUniform("model", model2); */
        /* shader2.setUniform("view", camera::viewMatrix()); */
        /* shader2.setUniform("projection", camera::projectionMatrix()); */
        /* shader2.setUniform("lightColor", lightColor); */
        /* vao2.renderVBO(&vbo2); */

        /* if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) */
        /*     glfwSetWindowShouldClose(window, true); */
        camera::update();
        jengine::window::update();
    }
    jengine::stop();
    return 0;
}
