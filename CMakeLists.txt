cmake_minimum_required(VERSION 3.0)
project(app)

add_subdirectory(./graphics)

set(SOURCE_FILES
    main.cpp
    utils.cpp
    window.cpp
    setup.cpp
    gameObject.cpp
)

set(HEADER_FILES
    utils.h
    window.h
    setup.h
    gameObject.h
)

add_executable(${PROJECT_NAME}
    ${HEADER_FILES}
    ${SOURCE_FILES}
)

target_link_libraries(${PROJECT_NAME}
    jengine::graphics
)
