#include "light.h"

using namespace jengine::graphics;

Light::Light() {}

void Light::setAmbient(glm::vec3 rgb)
{
    _ambient = rgb;
}

void Light::setAmbient(double r, double g, double b)
{
    _ambient = glm::vec3(r, g, b);
}

glm::vec3 Light::getAmbient() const
{
    return _ambient;
}

void Light::setDiffuse(glm::vec3 rgb)
{
    _diffuse = rgb;
}

void Light::setDiffuse(double r, double g, double b)
{
    _diffuse = glm::vec3(r, g, b);
}

glm::vec3 Light::getDiffuse() const
{
    return _diffuse;
}

void Light::setSpecular(glm::vec3 rgb)
{
    _specular = rgb;
}

void Light::setSpecular(double r, double g, double b)
{
    _specular = glm::vec3(r, g, b);
}

glm::vec3 Light::getSpecular() const
{
    return _specular;
}
