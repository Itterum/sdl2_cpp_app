cmake_minimum_required(VERSION 3.10)

project(c_apps)

set(CMAKE_CXX_STANDARD 11)

find_package(PkgConfig REQUIRED)
pkg_check_modules(CAIRO REQUIRED cairo)
pkg_check_modules(SDL2 REQUIRED sdl2)

include_directories(
  ${CAIRO_INCLUDE_DIRS}
  ${SDL2_INCLUDE_DIRS}
  ${CMAKE_SOURCE_DIR}/src
  ${CMAKE_SOURCE_DIR}/src/app
  ${CMAKE_SOURCE_DIR}/src/components
  ${CMAKE_SOURCE_DIR}/src/components/rect
  ${CMAKE_SOURCE_DIR}/src/components/shape
)

add_executable(
  main
  src/main.cpp
  src/app/application.cpp
  src/components/shape/shape.cpp
  src/components/rect/rectangle.cpp
)

target_link_libraries(main ${CAIRO_LIBRARIES} ${SDL2_LIBRARIES})

message(STATUS "Cairo Libraries: ${CAIRO_LIBRARIES}")
message(STATUS "SDL2 Libraries: ${SDL2_LIBRARIES}")
