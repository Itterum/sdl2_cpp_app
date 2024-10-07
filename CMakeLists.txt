cmake_minimum_required(VERSION 3.10)

project(c_apps)

set(CMAKE_CXX_STANDARD 11)

if (WIN32)
    set(CMAKE_WIN32_EXECUTABLE OFF)
endif ()

if (UNIX)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(SDL2 REQUIRED sdl2)

    include_directories(${SDL2_INCLUDE_DIRS})
    link_directories(${SDL2_LIBRARY_DIRS})

    set(LINK_LIBS ${SDL2_LIBRARIES})
else (WIN32)
    set(SDL_DIR "C:\\tools\\SDL2-devel-2.30.8-mingw\\SDL2-2.30.8\\x86_64-w64-mingw32")

    find_library(SDL_LIBS NAMES libSDL2 HINTS "${SDL_DIR}\\lib")
    include_directories("${SDL_DIR}\\include")

    if (NOT SDL_LIBS)
        message(FATAL_ERROR "SDL2 not found!")
    endif ()

    set(LINK_LIBS ${SDL_LIBS})
endif ()

include_directories(
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

target_link_libraries(main ${LINK_LIBS})

message(STATUS "SDL2 Libraries: ${LINK_LIBS}")
