#pragma once

#include <glm/ext.hpp>

#include "../window.h"

namespace jengine::graphics {
    class camera
    {
        public:
            static void init();
            static void update();

            static void setPosition(glm::vec3 pos);
            /* static void setDirection(glm::vec3 dir); */
            static void setTarget(glm::vec3 target);
            static void setPerspective(float fov, float near=0.1f, float far=100.f);
            static void setOrtho(float left, float right, float top, float bottom, float near=0.1f, float far=100.f);
            static glm::mat4& viewMatrix();
            static glm::mat4& projectionMatrix();

        private:
            static glm::vec3 _direction;
            static glm::vec3 _position;
            static glm::vec3 _target;
            static glm::mat4 _view;
            static glm::mat4 _projection;

            static bool _isPerspective;
            static float _fov;
            static float _near;
            static float _far;
            static float _left;
            static float _right;
            static float _top;
            static float _bottom;
    };
}
