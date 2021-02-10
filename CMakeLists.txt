cmake_minimum_required(VERSION 3.0)

project(study-opengl VERSION 0.0.1 LANGUAGES CXX)

add_subdirectory(graphics)

find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

set(SOURCE_FILES 
	main.cpp
	Window.cpp
	Utils.cpp	
)
set(HEADER_FILES
	Window.h
	Utils.h
)

add_executable(${PROJECT_NAME} 
	${HEADER_FILES} 
	${SOURCE_FILES}
)
target_link_libraries(${PROJECT_NAME}
	GLEW::GLEW
	OpenGL::GL
	glfw
	Engine::graphics
)
