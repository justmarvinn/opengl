#include "camera.h"

using namespace jengine::graphics;

glm::vec3 camera::_direction;
glm::vec3 camera::_position;
glm::vec3 camera::_target;
glm::mat4 camera::_view;
glm::mat4 camera::_projection;

bool camera::_isPerspective;
float camera::_fov;
float camera::_near;
float camera::_far;
float camera::_left;
float camera::_right;
float camera::_top;
float camera::_bottom;

void camera::init()
{
    _projection = glm::mat4(1);
    _view = glm::mat4(1);
    setPerspective(120.f);
    update();
}

void camera::update()
{
    if (_isPerspective)
        _projection = glm::perspective(
            glm::radians(_fov),
            jengine::window::aspect(), 
            _near,
            _far
        );
    else
        _projection = glm::ortho(
                _left,
                _right,
                _bottom,
                _top,
                _near,
                _far
        );

    _view = glm::lookAt(
        /* glm::vec3(sin(t)*r, 0, cos(t)*r), */
        /* glm::vec3(0, 0, 0), */
        _position,
        _target,
        glm::vec3(0, 1, 0)
    );
}

void camera::setPerspective(float fov, float near, float far)
{
    _isPerspective = true;
    _fov = fov;
    _near = near;
    _far = far;
}

void camera::setOrtho(float left, float right, float top, float bottom, float near, float far)
{
    _isPerspective = false;
    _left = left;
    _right = right;
    _top = top;
    _bottom = bottom;
    _near = near;
    _far = far;
}

void camera::setPosition(glm::vec3 pos)
{
    _position = pos;
}

void camera::setTarget(glm::vec3 target)
{
    _target = target;
}

glm::mat4& camera::viewMatrix()
{
    return _view;
}

glm::mat4& camera::projectionMatrix()
{
    return _projection;
}
