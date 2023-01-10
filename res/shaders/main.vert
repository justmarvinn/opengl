#version 330 core

layout (location = 0) in vec3 aPos;
/* layout (location = 1) in vec3 aColor; */
layout (location = 1) in vec2 aTexCoord;

/* out vec3 pos; */
/* out vec3 color; */
out vec2 texCoord;

uniform float uTime;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    /* vec3 p = aPos; */
    /* p.x += sin(uTime); */
    /* gl_Position = vec4(p, 1); */
    gl_Position = projection * view * model * vec4(aPos, 1);

    /* pos = aPos; */
    /* color = aColor; */
    texCoord = vec2(aTexCoord.x, 1-aTexCoord.y);
}
