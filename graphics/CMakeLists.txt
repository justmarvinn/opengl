project(graphics)

find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

set(SOURCE_FILES
    VAO.cpp
	Shader.cpp	
)
set(HEADER_FILES
    VAO.h
    Shader.h
)

add_library(${PROJECT_NAME}
    ${HEADER_FILES}
    ${SOURCE_FILES}
)
add_library(Engine::graphics ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
	GLEW::GLEW
	OpenGL::GL
	glfw
)
