cmake_minimum_required(VERSION 3.10)

project(c_apps)

set(CMAKE_CXX_STANDARD 11)

if (UNIX)
    find_package(OpenGL REQUIRED)
    find_package(glfw3 REQUIRED)
else (WIN32)
    set(GLFW_DIR "C:\\tools\\glfw-3.4.bin.WIN64")

    find_package(OpenGL REQUIRED)
    find_library(GLFW_LIB NAMES glfw3 HINTS "${GLFW_DIR}\\lib-mingw-w64")
    include_directories("${GLFW_DIR}\\include")

    if (NOT GLFW_LIB)
        message(FATAL_ERROR "GLFW not found!")
    endif ()
endif ()

include_directories(
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/app
        ${CMAKE_SOURCE_DIR}/src/components/shape
        ${CMAKE_SOURCE_DIR}/src/components/rect
        ${CMAKE_SOURCE_DIR}/src/components/circle
)

add_executable(
        main
        src/main.cpp
        src/app/application.cpp
        src/components/shape/shape.cpp
        src/components/rect/rectangle.cpp
        src/components/circle/circle.cpp
)

if (UNIX)
    target_link_libraries(
            main
            ${OPENGL_LIBRARIES}
            glfw ${GLM_LIBRARIES}
    )
elseif (WIN32)
    target_link_libraries(
            #            main
            #            ${OPENGL_LIBRARIES}
            #            ${GLFW_LIB}
            main
            ${OPENGL_LIBRARIES}
            ${GLFW_LIB} ${GLM_LIBRARIES}
    )
endif ()

message(STATUS "OpenGL Libraries: ${OPENGL_LIBRARIES}")
message(STATUS "GLFW Library: ${GLFW_LIB}")
