cmake_minimum_required(VERSION 3.10)

project(c_apps)

set(CMAKE_CXX_STANDARD 11)

if (UNIX)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(SDL2 REQUIRED sdl2)
else (WIN32)
    set(SDL_DIR "C:\\tools\\SDL2-devel-2.30.8-mingw\\SDL2-2.30.8\\x86_64-w64-mingw32")

    find_library(SDL_LIB NAMES libSDL2 HINTS "${SDL_DIR}\\lib")
    include_directories(SDL_INCLUDE "${SDL_DIR}\\include")

    if (NOT SDL_LIB)
        message(FATAL_ERROR "SDL2 not found!")
    endif ()
endif ()

include_directories(
        ${SDL_INCLUDE}
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/app
        ${CMAKE_SOURCE_DIR}/src/components
        ${CMAKE_SOURCE_DIR}/src/components/rect
        ${CMAKE_SOURCE_DIR}/src/components/shape
        #        ${CMAKE_SOURCE_DIR}/src/components/circle
)

add_executable(
        main
        src/main.cpp
        src/app/application.cpp
        src/components/shape/shape.cpp
        src/components/rect/rectangle.cpp
        #        src/components/circle/circle.cpp
)

target_link_libraries(main ${SDL_LIB})

message(STATUS "SDL2 Libraries: ${SDL_LIB}")
