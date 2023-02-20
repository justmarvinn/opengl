#version 330 core

struct Material {
    vec3 ambient;
    vec3 specular;
    vec3 diffuse;
    float shininess;
};

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 n;

out vec3 color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec3 objColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 cameraPos;

uniform Material material;

void main()
{
    gl_Position = projection * view * model * vec4(position, 1);
    vec3 normal = mat3(transpose(inverse(model))) * n;
    vec3 fragPos = vec3(model * vec4(position, 1));

    vec3 ambient = lightColor * material.ambient;

    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(lightPos - fragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * material.diffuse * lightColor;

    vec3 cameraDir = normalize(cameraPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(cameraDir, reflectDir), 0.0), material.shininess);
    vec3 specular = spec * material.specular * lightColor;

    vec3 gourand = (ambient + diffuse + specular) * objColor;
    color = gourand;
}
