cmake_minimum_required(VERSION 3.12)
project(app)

# set(CMAKE_CXX_COMPILER )

add_subdirectory(./graphics)

# set(SOURCE_FILES
#     main.cpp
#     utils.cpp
#     window.cpp
#     setup.cpp
#     gameObject.cpp
# )

# set(HEADER_FILES
#     utils.h
#     window.h
#     setup.h
#     gameObject.h
# )

file(GLOB SOURCE_FILES "*.cpp")
file(GLOB HEADER_FILES "*.h")

add_executable(${PROJECT_NAME}
    ${HEADER_FILES}
    ${SOURCE_FILES}
)

target_link_libraries(${PROJECT_NAME}
    jengine::graphics
)
