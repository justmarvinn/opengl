#version 330 core

in vec3 color;
out vec4 res;

void main()
{
    res = vec4(color, 1);
}
