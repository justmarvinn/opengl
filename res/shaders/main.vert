#version 330 core

layout (location = 0) in vec3 position;
/* layout (location = 1) in vec2 aTexCoord; */
layout (location = 1) in vec3 norm;

/* out vec2 texCoord; */
out vec3 normal;
out vec3 fragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(position, 1);
    /* texCoord = vec2(aTexCoord.x, 1-aTexCoord.y); */
    normal = norm;
    fragPos = vec3(model * vec4(position, 1));
}
