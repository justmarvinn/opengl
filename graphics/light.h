#pragma once

#include <glm/ext.hpp>

namespace jengine::graphics {
    class Light {
    public:
        Light();
        virtual ~Light();
        
        void setAmbient(glm::vec3 rgb);
        void setAmbient(double r, double g, double b);
        glm::vec3 getAmbient() const;

        void setDiffuse(glm::vec3 rgb);
        void setDiffuse(double r, double g, double b);
        glm::vec3 getDiffuse() const;

        void setSpecular(glm::vec3 rgb);
        void setSpecular(double r, double g, double b);
        glm::vec3 getSpecular() const;

    protected:
        glm::vec3 _ambient;
        glm::vec3 _diffuse;
        glm::vec3 _specular;
    };
}
