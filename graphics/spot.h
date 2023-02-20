#pragma once

#include "light.h"
#include <glm/ext.hpp>

namespace jengine::graphics {
    class Spot : public Light {
    public:
        Spot();
        Spot(glm::vec3 pos, glm::vec3 dir);
        Spot(glm::vec3 pos, glm::vec3 dir, double cutOff);
        Spot(glm::vec3 pos, glm::vec3 dir, double cutOff, double outerCutOff);
        ~Spot();

        void setPosition(glm::vec3 pos);
        void setPosition(double x, double y, double z);
        glm::vec3 getPosition() const;

        void setDirection(glm::vec3 dir);
        void setDirection(double x, double y, double z);
        glm::vec3 getDirection() const;

        void setCutOffDeg(double cutOff);
        void setCutOffRad(double cutOff);
        void setOuterCutOffDeg(double outerCutOff);
        void setOuterCutOffRad(double outerCutOff);

    private:
        glm::vec3 _position;
        glm::vec3 _direction;
        double _cutOff;
        double _outerCutOff;
    };
}
