cmake_minimum_required(VERSION 3.0)
project(graphics)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(./include/glfw-3.3.8)
add_subdirectory(./include/glad)
add_subdirectory(./include/SOIL2)

set(SOURCE_FILES
    utils.cpp
    ShaderProgram.cpp
    VAO.cpp
    VBO.cpp
    EBO.cpp
    texture2d.cpp
)
set(HEADER_FILES
    utils.h
    ShaderProgram.h
    VAO.h
    VBO.h
    EBO.h
    texture2d.h
)

add_library(${PROJECT_NAME}
    ${SOURCE_FILES}
    ${HEADER_FILES}
)
add_library(jengine::graphics ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        glfw
        glad
        soil2
        # jengine::graphics
)

