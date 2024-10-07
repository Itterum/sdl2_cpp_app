#ifndef APPLICATION_H
#define APPLICATION_H

#include "../components/shape/shape.h"
#include <GLFW/glfw3.h>
#include <string>
#include <vector>

class Application {
public:
  Application(int width, int height, char *title);
  ~Application();

  void init();
  void main_loop(std::vector<Shape *> &shapes, bool animate) const;

  GLFWwindow *create_window() const;
  GLFWwindow *get_window() const { return window; }

private:
  int w_width;
  int w_height;
  std::string w_title;
  GLFWwindow *window{};
};

#endif
