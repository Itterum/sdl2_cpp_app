#include "application.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <utility>

Application::Application(int w, int h, std::string t) {
  width = w;
  height = h;
  title = std::move(t);
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
  glOrtho(0, width, height, 0, -1, 1);
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
        shape->animate(width, height);
      }
    }

    glfwSwapBuffers(window);

    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }

  glfwDestroyWindow(window);
}

GLFWwindow *Application::create_window() const {
  GLFWwindow *window =
      glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

  if (!window) {
    std::cerr << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return nullptr;
  }

  return window;
}
