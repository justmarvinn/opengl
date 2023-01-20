#pragma once

#include <glm/ext.hpp>

#include "graphics/graphics.h"

namespace jengine {
    class gameObject
    {
        public:
            gameObject(graphics::VBO);
            gameObject(graphics::VBO vbo, glm::vec3 pos);
            ~gameObject();

            void setPosition(glm::vec3 pos);
            void setDirection(glm::vec3 dir);
            void setScale(glm::vec3 scale);

            glm::vec3 getPosition();
            glm::vec3 getDirection();
            glm::vec3 getScale();

            void rotateX(float deg);
            void rotateY(float deg);
            void rotateZ(float deg);
            void rotateXrad(float rad);
            void rotateYrad(float rad);
            void rotateZrad(float rad);

            void setVAO(graphics::VAO vao);
            void setVBO(graphics::VBO vbo);
            void render();

        private:
            graphics::VAO _vao;
            graphics::VBO _vbo;
            graphics::EBO _ebo;

            glm::vec3 _pos;
            glm::vec3 _dir;
            glm::vec3 _scale;
    };
}
