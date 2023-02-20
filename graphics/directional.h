#pragma once

#include "light.h"
#include <glm/ext.hpp>

namespace jengine::graphics {
    class Directional : public Light {
    public:
        Directional();
        Directional(glm::vec3 dir);
        Directional(double x, double y, double z);
        ~Directional();

        void setDirection(glm::vec3 dir);
        void setDirection(double x, double y, double z);
        glm::vec3 getDirection() const;

    private:
        glm::vec3 _direction;
    };
}
