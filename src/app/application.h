#ifndef APPLICATION_H
#define APPLICATION_H

#include <GLFW/glfw3.h>
#include "../components/shape/shape.h"
#include <string>
#include <vector>

class Application {
public:
  Application(int width, int height, std::string title);
  ~Application();

  void init();
  void main_loop(std::vector<Shape *> &shapes, bool animate) const;

  GLFWwindow *create_window() const;
  GLFWwindow *get_window() const { return window; }

private:
  int width;
  int height;
  std::string title;
  GLFWwindow *window{};
};

#endif
