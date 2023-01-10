#include "setup.h"

bool jengine::init(){
    try {
        init_glfw();
        jengine::window::init(800, 800, "hello world", true);
        init_glad();
        init_opengl();
        jengine::graphics::camera::init();
    } catch (const std::exception& e) {
        jengine::stop();
        return false;
    }
    return true;
}

void init_glfw()
{
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        throw std::exception();
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwSetErrorCallback(glfw_error_callback);
}

void init_glad()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        throw std::exception();
    }
}

void init_opengl()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    /* glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); */
    glEnable(GL_DEPTH_TEST);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
}

void jengine::stop()
{
    glfwTerminate();
}

void glfw_error_callback(int err, const char* description)
{
    std::cerr << description << std::endl;
}
