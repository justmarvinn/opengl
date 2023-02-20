#include "directional.h"

using namespace jengine::graphics;

Directional::~Directional() {}

Directional::Directional()
{
    _ambient = glm::vec3(1);
    _diffuse = glm::vec3(1);
    _specular = glm::vec3(1);

    _direction = glm::vec3(0);
}

Directional::Directional(glm::vec3 dir)
{
    _ambient = glm::vec3(1);
    _diffuse = glm::vec3(1);
    _specular = glm::vec3(1);

    _direction = dir;
}

Directional::Directional(double x, double y, double z)
{
    _ambient = glm::vec3(1);
    _diffuse = glm::vec3(1);
    _specular = glm::vec3(1);

    _direction = glm::vec3(x, y, z);
}

void Directional::setDirection(glm::vec3 dir)
{
    _direction = dir;
}

void Directional::setDirection(double x, double y, double z)
{
    _direction = glm::vec3(x, y, z);
}

glm::vec3 Directional::getDirection() const
{
    return _direction;
}
