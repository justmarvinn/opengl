#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GLFW/glfw3.h>

#include "Window.h"
#include "graphics/Shader.h"
#include "graphics/VAO.h"

const int WIDTH = 800;
const int HEIGHT = 600;

const std::vector<float> q1Vertices = {
	-1, 1, 0,
	 0, 1, 0,
	 0, 0, 0,
	-1, 0, 0,
};
const std::vector<float> q2Vertices = {
	0,  0, 0,
	1,  0, 0,
	1, -1, 0,
	0, -1, 0,
};
const std::vector<float> fullScreenQuad = {
    -1,  1, 0,
     1,  1, 0,
     1, -1, 0,
    -1, -1, 0,
};
// const std::vector<float> tVertices = {
//     -1, -1, 0,
//      1, -1, 0,
//      0,  1, 0,
// };

int main()
{
	std::cout << "Hello, World!" << std::endl;

	Window::Initialize(WIDTH, HEIGHT, "window");

    Shader shader;
    shader.addSource("../shaders/main.vert");
    shader.addSource("../shaders/main.frag");
    shader.Compile();

    VAO vao1(GL_QUADS, 4);
    vao1.addVBO(q1Vertices);

    VAO vao2(GL_QUADS, 4);
    vao2.addVBO(q2Vertices);

    VAO fsVao(GL_QUADS, 4);
    fsVao.addVBO(fullScreenQuad);

    // VAO vao(GL_TRIANGLES, 3);
    // vao.addVBO(tVertices);

	while (!Window::isShouldClose()) {
        shader.Use();
        // vao.Render();
        fsVao.Render();
        // vao1.Render();
        // Shader::StopUsingShader();
        // vao2.Render();
		Window::Update();
    }
	Window::Finalize();

	return 0;
}
