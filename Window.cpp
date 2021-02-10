#include "Window.h"
// #pragma warning(disable : 4996)

GLFWwindow* Window::_window;

void Window::Initialize(int width, int height, const char* title, bool resizable)
{
	if (!glfwInit()) {
        std::cerr << "Can not initialize GLFW" << std::endl;  	    
        return;
    }

   	glfwWindowHint(GLFW_RESIZABLE, (int)resizable);
    _window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!_window) {
	    Window::Finalize();
        std::cerr << "Can not create GLFW window" << std::endl;
		return;
	}
	glfwMakeContextCurrent(_window);
   	
    if (glewInit() != GLEW_OK) {
        Window::Finalize();
        std::cerr << "Can not initialize GLEW" << std::endl;    
        return;
    }
	
	glfwSetWindowSizeCallback(_window, Window::onResize);
	glClearColor(0, 0, 0, 1);
}

void Window::Finalize()
{
	glfwDestroyWindow(_window);
	glfwTerminate();
}

void Window::Update()
{
	glfwSwapBuffers(_window);
	glfwPollEvents();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

bool Window::isShouldClose()
{
	return glfwWindowShouldClose(_window);
}

void Window::onResize(GLFWwindow* win, int width, int height) 
{
	glViewport(0, 0, width, height);
}

/*void Window::setIcon(const char* filename)
{
	FILE* fp = fopen(filename, "r");
	if (!fp) {
		printf("Image not found\n");
		return;
	}

	png_structp pngptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	png_infop pnginfo = png_create_info_struct(pngptr);
	png_set_palette_to_rgb(pngptr);
	png_init_io(pngptr, fp);
	
	png_bytepp rows;
	png_read_png(pngptr, pnginfo, PNG_TRANSFORM_IDENTITY, NULL);
	rows = png_get_rows(pngptr, pnginfo);

	int width = png_get_image_width(pngptr, pnginfo);
	int height = png_get_image_height(pngptr, pnginfo);
	unsigned char pixels[width * height * 3];
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			//printf("%d %d %d\n", rows[i][j], rows[i][j+1], rows[i][j+2]);

			pixels[i+j] = rows[i][j];
			pixels[i+j+1] = rows[i][j+1];
			pixels[i+j+2] = rows[i][j+2];
 			//pixels[i+j+3] = 1.0f;
		}
	}
	int t = 0;
	for (int i = 0; i < sizeof(rows[0]); i++) {
		for (int j = 0; j < sizeof(rows[1]); j++) {
			std::cout << i << "; " << j  << std::endl;
			t++;
		}
	}
	std::cout << t << std::endl;

	GLFWimage image[1];
	image[0].width = width;
	image[0].height = height;
	image[0].pixels = pixels;
	//glfwSetWindowIcon(_window, 1, image);
	
	fclose(fp);

//	Critical error here
//	GLFWimage images[1];
//	images[0].pixels = stbi_load(filename, &images[0].width, &images[0].height, 0, 4);
//	glfwSetWindowIcon(_window, 1, images);
//	stbi_image_free(images[0].pixels);
}*/
