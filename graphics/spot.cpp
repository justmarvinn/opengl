#include "spot.h"

using namespace jengine::graphics;

Spot::~Spot() {}

Spot::Spot()
{
    _ambient = glm::vec3(1);
    _diffuse = glm::vec3(1);
    _specular = glm::vec3(1);

    _position = glm::vec3(0);
    _direction = glm::vec3(0);
    _cutOff = glm::radians(45.0);
    _outerCutOff = _cutOff;
}

Spot::Spot(glm::vec3 pos, glm::vec3 dir)
{
    _ambient = glm::vec3(1);
    _diffuse = glm::vec3(1);
    _specular = glm::vec3(1);

    _position = pos;
    _direction = dir;
    _cutOff = glm::radians(45.0);
    _outerCutOff = _cutOff;
}

Spot::Spot(glm::vec3 pos, glm::vec3 dir, double cutOff)
{
    _ambient = glm::vec3(1);
    _diffuse = glm::vec3(1);
    _specular = glm::vec3(1);

    _position = pos;
    _direction = dir;
    _cutOff = cutOff;
    _outerCutOff = _cutOff;
}

Spot::Spot(glm::vec3 pos, glm::vec3 dir, double cutOff, double outerCutOff)
{
    _ambient = glm::vec3(1);
    _diffuse = glm::vec3(1);
    _specular = glm::vec3(1);
    
    _position = pos;
    _direction = dir;
    _cutOff = cutOff;
    _outerCutOff = outerCutOff;
}

void Spot::setPosition(glm::vec3 pos)
{
    _position = pos;
}

void Spot::setPosition(double x, double y, double z)
{
    _position = glm::vec3(x, y, z);
}

glm::vec3 Spot::getPosition() const
{
    return _position;
}

void Spot::setDirection(glm::vec3 dir)
{
    _direction = dir;
}

void Spot::setDirection(double x, double y, double z)
{
    _direction = glm::vec3(x, y, z);
}

glm::vec3 Spot::getDirection() const
{
    return _direction;
}

void Spot::setCutOffDeg(double cutOff)
{
    setCutOffRad(glm::radians(cutOff));
}

void Spot::setCutOffRad(double cutOff)
{
    _cutOff = cutOff;
}

void Spot::setOuterCutOffDeg(double outerCutOff)
{
    setOuterCutOffRad(glm::radians(outerCutOff));
}

void Spot::setOuterCutOffRad(double outerCutOff)
{
    _outerCutOff = outerCutOff;
}
