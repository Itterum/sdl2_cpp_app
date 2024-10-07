#include "application.h"
#include <chrono>
#include <iostream>
#include <thread>

Application::Application(int width, int height, char *title) {
  w_width = width;
  w_height = height;
  w_title = title;
  init();
}
Application::~Application() {
  glfwDestroyWindow(window);
  glfwTerminate();
}

void Application::init() {
  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW" << std::endl;
  }

  window = create_window();

  glfwMakeContextCurrent(window);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, w_width, w_height, 0, -1, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void Application::main_loop(std::vector<Shape *> &shapes,
                            const bool animate) const {
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    glClear(GL_COLOR_BUFFER_BIT);

    if (animate) {
      for (Shape *shape : shapes) {
        shape->animate(w_width, w_height);
      }
    }

    glfwSwapBuffers(window);

    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }

  glfwDestroyWindow(window);
}

GLFWwindow *Application::create_window() const {
  GLFWwindow *window =
      glfwCreateWindow(w_width, w_height, w_title.c_str(), nullptr, nullptr);

  if (!window) {
    std::cerr << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return nullptr;
  }

  return window;
}
