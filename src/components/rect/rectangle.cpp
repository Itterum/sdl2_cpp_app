#include "rectangle.h"
#include <GLFW/glfw3.h>

Rectangle::Rectangle(const float x, const float y, const float w,
                     const float h) {
  set_point_x(x);
  set_point_y(y);
  set_width(w);
  set_height(h);
}

Rectangle::~Rectangle() = default;

void Rectangle::draw() {
  glColor3f(1.0f, 0.0f, 0.0f);

  glBegin(GL_QUADS);
  glVertex2f(get_point_x(), get_point_y());
  glVertex2f(get_point_x() + get_width(), get_point_y());
  glVertex2f(get_point_x() + get_width(), get_point_y() + get_height());
  glVertex2f(get_point_x(), get_point_y() + get_height());
  glEnd();
}

void Rectangle::animate(const float window_width, const float window_height) {
  static float dx = 2;
  static float dy = 2;

  set_point_x(get_point_x() + dx);
  set_point_y(get_point_y() + dy);

  if (get_point_x() <= 0 || get_point_x() + get_width() >= window_width) {
    dx = -dx;
  }
  if (get_point_y() <= 0 || get_point_y() + get_height() >= window_height) {
    dy = -dy;
  }

  draw();
}
