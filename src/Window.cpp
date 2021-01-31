#include "Window.h"
#pragma warning(disable : 4996)

GLFWwindow* Window::_window;

void Window::Initialize(int width, int height, const char* title, bool resizable) 
{
    /* Initialize the library */
    if (!glfwInit()) {
#ifdef _DEBUG
        std::cerr << "GLFW initialization error" << std::endl;
#endif
        return;
    }

    glfwWindowHint(GLFW_RESIZABLE, (int)resizable);

    /* Create a windowed mode window and its OpenGL context */
    _window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!_window)
    {
        Window::Finalize();
#ifdef _DEBUG
        std::cerr << "GLFW window creating error" << std::endl;
#endif
        return;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(_window);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Window::Finalize() 
{
    glfwTerminate();
}

void Window::Update()
{
    /* Swap front and back buffers */
    glfwSwapBuffers(_window);

    /* Poll for and process events */
    glfwPollEvents();

    glClear(GL_COLOR_BUFFER_BIT);
}

bool Window::isShouldClose()
{
    return glfwWindowShouldClose(_window);
}

void Window::setIcon(const char* filename)
{
    //GLFWimage* img;
    
    FILE* fp = fopen(filename, "rb"); //C4996 error
    if (!fp) {
#ifdef _DEBUG
        std::cerr << "Open image error" << std::endl;
#endif
        return;
    }

    png_structp pngptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    png_infop pnginfo = png_create_info_struct(pngptr);
    png_set_palette_to_rgb(pngptr);

    png_init_io(pngptr, fp);
    png_read_png(pngptr, pnginfo, PNG_TRANSFORM_IDENTITY, NULL);
    png_bytepp rows = png_get_rows(pngptr, pnginfo);
            
    for (uint32_t i = 0; i < pnginfo->height; i++) {
        for (uint32_t j = 0; j < pnginfo->width * 3; j += 3) {
            printf("%d %d %d ", rows[i][j], rows[i][j + 1], rows[i][j + 2]);
            
        }
        printf("\n");
    }

    fclose(fp);
    //glfwSetWindowIcon(_window, 1, img);
}