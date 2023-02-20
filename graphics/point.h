#pragma once

#include "light.h"
#include <glm/ext.hpp>

namespace jengine::graphics {
    class Point : public Light {
    public:
        Point();
        Point(glm::vec3 pos);
        Point(double x, double y, double z);
        Point(glm::vec3 pos, double kl, double kq);
        Point(double x, double y, double z, double kl, double kq);
        ~Point();

        void setPosition(glm::vec3 pos);
        void setPosition(double x, double y, double z);
        glm::vec3 getPosition() const;

        void setKl(double kl);
        void setKq(double kq);

    private:
        glm::vec3 _position;
        double _kl, _kq;
    };
}
