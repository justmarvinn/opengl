#include "texture2d.h"

using namespace jengine::graphics;

texture2d::texture2d()
{
    glGenTextures(1, &_id);
}

texture2d::~texture2d()
{
    glDeleteTextures(1, &_id);
    SOIL_free_image_data(_data);
}

void texture2d::loadImageRGB(std::string filename, unsigned int channel)
{
    if (channel < 0 || channel > 31)
        return;
    _channel = channel;
    glActiveTexture(GL_TEXTURE0+channel);
    use();
    _data = SOIL_load_image(filename.c_str(), &_width, &_height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, _data);
    glGenerateMipmap(GL_TEXTURE_2D);
    useNoTexture();
}

void texture2d::loadImageRGBA(std::string filename, unsigned int channel)
{
    if (channel < 0 || channel > 31)
        return;
    _channel = channel;
    glActiveTexture(GL_TEXTURE0+channel);
    use();
    _data = SOIL_load_image(filename.c_str(), &_width, &_height, 0, SOIL_LOAD_RGBA);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _data);
    glGenerateMipmap(GL_TEXTURE_2D);
    useNoTexture();
}

void texture2d::use()
{
    glActiveTexture(GL_TEXTURE0+_channel);
    glBindTexture(GL_TEXTURE_2D, _id);
}

void texture2d::useNoTexture()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

unsigned int texture2d::channel()
{
    return _channel;
}
