#version 330 core

in vec3 normal;
in vec3 fragPos;

out vec4 color;

uniform vec3 objColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 cameraPos;

uniform float ambientStrength;
uniform float specularStrength;

const float k = 32.0f;

void main()
{
    vec3 ambient = ambientStrength * lightColor;

    vec3 lightDir = normalize(lightPos - fragPos);
    float diffuseStrength = max(dot(normal, lightDir), 0);
    vec3 diffuse = diffuseStrength * lightColor;

    vec3 cameraDir = normalize(cameraPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(cameraDir, reflectDir), 0.0), k);
    vec3 specular = specularStrength * spec * lightColor;

    vec3 phong = (ambient + diffuse + specular) * objColor;
    /* vec3 phong = vec3(diffuse); */
    color = vec4(phong, 1);
}
