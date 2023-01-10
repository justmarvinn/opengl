#include "utils.h"

std::string utils::parseText(std::string filename)
{
    std::ifstream file;
    file.open(filename);
    std::string res = "";

    if (!file)
        std::cerr << "Can not open file " << filename << std::endl;
    else {
        std::string line;
        while (std::getline(file, line)) 
            res += line + '\n'; 
    }
    file.close();
    return res + '\0';
}

std::string utils::parseFormat(std::string filename) 
{
    if (filename.find(".") != std::string::npos)
        return filename.substr(filename.find_last_of("."));
    else {
        std::cerr << "File does not have an extension" << std::endl;
        return "";
    }
}

jengine::graphics::VBO utils::triangleVBO()
{
    std::array<float, (3+2)*3> triangle = {
         0,  1, 0,   .5, .5,
         1, -1, 0,    1,  0,
        -1, -1, 0,    0,  0,
    };
    jengine::graphics::VBO vbo(triangle, 5);
    return vbo;
}

jengine::graphics::VBO utils::quadVBO()
{
    std::array<float, (3+2)*6> quad = {
         1, -1, 0,   1, 0, // bottom right
        -1, -1, 0,   0, 0, // bottom left
        -1,  1, 0,   0, 1, // top left

        -1,  1, 0,   0, 1, // top left
         1,  1, 0,   1, 1, // top right
         1, -1, 0,   1, 0, // bottom right
    };
    jengine::graphics::VBO vbo(quad, 5);
    return vbo;
}

jengine::graphics::VBO utils::cubeVBO()
{
    std::array<float, (3+2)*6*6> cube = {
        -1, -1, -1,  0, 0,
         1, -1, -1,  1, 0,
         1,  1, -1,  1, 1,
         1,  1, -1,  1, 1,
        -1,  1, -1,  0, 1,
        -1, -1, -1,  0, 0,

        -1, -1,  1,  0, 0,
         1, -1,  1,  1, 0,
         1,  1,  1,  1, 1,
         1,  1,  1,  1, 1,
        -1,  1,  1,  0, 1,
        -1, -1,  1,  0, 0,

        -1,  1,  1,  1, 0,
        -1,  1, -1,  1, 1,
        -1, -1, -1,  0, 1,
        -1, -1, -1,  0, 1,
        -1, -1,  1,  0, 0,
        -1,  1,  1,  1, 0,

         1,  1,  1,  1, 0,
         1,  1, -1,  1, 1,
         1, -1, -1,  0, 1,
         1, -1, -1,  0, 1,
         1, -1,  1,  0, 0,
         1,  1,  1,  1, 0,

        -1, -1, -1,  0, 1,
         1, -1, -1,  1, 1,
         1, -1,  1,  1, 0,
         1, -1,  1,  1, 0,
        -1, -1,  1,  0, 0,
        -1, -1, -1,  0, 1,

        -1,  1, -1,  0, 1,
         1,  1, -1,  1, 1,
         1,  1,  1,  1, 0,
         1,  1,  1,  1, 0,
        -1,  1,  1,  0, 0,
        -1,  1, -1,  0, 1,
    };
    jengine::graphics::VBO vbo(cube, 5);
    return vbo;
}
