#version 330 core

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
};

struct Directional{
    vec3 dir;
    
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct Point {
    vec3 pos;
    float kl;
    float kq;
    
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct Spot {
    vec3 pos;
    vec3 dir;
    float cutOff;
    
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float outerCutOff;
};

in vec3 normal;
in vec3 fragPos;
in vec2 texCoord;

out vec4 color;

uniform vec3 cameraPos;
uniform Material material;
uniform Point point;
/* uniform sampler2D emission; */

void main()
{
    vec3 ambient = point.ambient * vec3(texture(material.diffuse, texCoord));
    /* vec3 ambient = light.ambient * vec3(texture(material.diffuse, texCoord)); */

    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(point.pos - fragPos);
    /* vec3 lightDir = normalize(light.pos - fragPos); */
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * light.diffuse * vec3(texture(material.diffuse, texCoord));

    vec3 cameraDir = normalize(cameraPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(cameraDir, reflectDir), 0.0), material.shininess);
    /* vec3 specular = spec * lightColor * vec3(texture(material.specular, texCoord)); */
    vec3 specular = spec * light.specular * vec3(texture(material.specular, texCoord));
    /* vec3 specular = vec3(texture(material.specular, texCoord)); */

    vec3 light = ambient + diffuse + specular;
    /* vec3 light = specular; */
    /* light += vec3(texture(emission, texCoord)); */
    color = vec4(light, 1);
}
