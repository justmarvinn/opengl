#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Window.h"

#include <png.h>

const int WIDTH = 800;
const int HEIGHT  = 600;

int main(void)
{

    Window::Initialize(WIDTH, HEIGHT, "window");
    while (!Window::isShouldClose()) {
        glColor3f(1.0f, 1.0f, 1.0f);

        glBegin(GL_QUADS);
        glVertex3f(-0.5f, 0.5f, 0.0f);
        glVertex3f(0.5f, 0.5f, 0.0f);
        glVertex3f(0.5f, -0.5f, 0.0f);
        glVertex3f(-0.5f, -0.5f, 0.0f);
        glEnd();

        glFlush();
        Window::Update();
    }
    Window::setIcon("img/icon.png");
    Window::Finalize();
    return 0;
}