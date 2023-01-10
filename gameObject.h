#pragma once

#include <glm/ext.hpp>

namespace jengine {
    class gameObject
    {
        public:
            gameObject();
            gameObject(glm::vec3 pos);
            ~gameObject();

            void setPosition(glm::vec3 pos);
            void setDirection(glm::vec3 dir);
            void setScale(glm::vec3 scale);

            glm::vec3& getPosition();
            glm::vec3& getDirection();
            glm::vec3& getScale();

            void rotateX(float deg);
            void rotateY(float deg);
            void rotateZ(float deg);
            void rotateXrad(float rad);
            void rotateYrad(float rad);
            void rotateZrad(float rad);

        private:
            glm::vec3 _pos;
            glm::vec3 _dir;
            glm::vec3 _scale;
    };
}
