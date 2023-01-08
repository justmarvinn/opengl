#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

/* out vec3 pos; */
out vec3 color;
out vec2 texCoord;

void main()
{
    gl_Position = vec4(aPos, 1);

    /* pos = aPos; */
    color = aColor;
    texCoord = vec2(aTexCoord.x, 1-aTexCoord.y);
}
