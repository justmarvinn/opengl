cmake_minimum_required(VERSION 3.0)
project(app)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
# set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
# set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
# set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
# add_subdirectory(./include/glfw-3.3.8)
# add_subdirectory(./include/glad)
add_subdirectory(./graphics)

set(SOURCE_FILES
    main.cpp
    # utils.cpp
    # ShaderProgram.cpp
    # VAO.cpp
    # VBO.cpp
    # EBO.cpp
)

set(HEADER_FILES
    # utils.h
    # ShaderProgram.h
    # VAO.h
    # VBO.h
    # EBO.h
)

add_executable(${PROJECT_NAME}
    ${HEADER_FILES}
    ${SOURCE_FILES}
)

target_link_libraries(${PROJECT_NAME}
    jengine::graphics
    # glfw
    # glad
)
