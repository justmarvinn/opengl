#include "point.h"

using namespace jengine::graphics;

/* Point::~Point() {} */

Point::Point()
{
    _ambient = glm::vec3(1);
    _diffuse = glm::vec3(1);
    _specular = glm::vec3(1);

    _position = glm::vec3(0);
    _kl = 0.7;
    _kq = 1.8;
}

Point::Point(glm::vec3 pos)
{
    _ambient = glm::vec3(1);
    _diffuse = glm::vec3(1);
    _specular = glm::vec3(1);

    _position = pos;
    _kl = 0.7;
    _kq = 1.8;
}

Point::Point(double x, double y, double z)
{
    _ambient = glm::vec3(1);
    _diffuse = glm::vec3(1);
    _specular = glm::vec3(1);

    _position = glm::vec3(x, y, z);
    _kl = 0.7;
    _kq = 1.8;
}

Point::Point(glm::vec3 pos, double kl, double kq)
{
    _ambient = glm::vec3(1);
    _diffuse = glm::vec3(1);
    _specular = glm::vec3(1);

    _position = pos;
    _kl = kl;
    _kq = kq;
}

Point::Point(double x, double y, double z, double kl, double kq)
{
    _ambient = glm::vec3(1);
    _diffuse = glm::vec3(1);
    _specular = glm::vec3(1);

    _position = glm::vec3(x, y, z);
    _kl = kl;
    _kq = kq;
}

void Point::setPosition(glm::vec3 pos)
{
    _position = pos;
}

void Point::setPosition(double x, double y, double z)
{
    _position = glm::vec3(x, y, z);
}

glm::vec3 Point::getPosition() const
{
    return _position;
}

void Point::setKl(double kl)
{
    _kl = kl;
}

void Point::setKq(double kq)
{
    _kq = kq;
}
