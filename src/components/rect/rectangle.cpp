#include <GLFW/glfw3.h>
#include <rectangle.h>

Rectangle::Rectangle(const float x, const float y, const float w,
                     const float h) {
  set_point_x(x);
  set_point_y(y);
  set_width(w);
  set_height(h);
}

Rectangle::~Rectangle() = default;

void Rectangle::draw() {
  change_color();

  glBegin(GL_QUADS);
  glVertex2f(get_point_x(), get_point_y());
  glVertex2f(get_point_x() + get_width(), get_point_y());
  glVertex2f(get_point_x() + get_width(), get_point_y() + get_height());
  glVertex2f(get_point_x(), get_point_y() + get_height());
  glEnd();
}

void Rectangle::animate(const float window_width, const float window_height) {
  static float dx = 2.0f;
  static float dy = 2.0f;

  set_point_x(get_point_x() + dx);
  set_point_y(get_point_y() + dy);

  if (get_point_x() <= 0 || get_point_x() + get_width() >= window_width) {
    dx = -dx;
    set_point_x(
        std::max(0.0f, std::min(get_point_x(), window_width - get_width())));
  }
  if (get_point_y() <= 0 || get_point_y() + get_height() >= window_height) {
    dy = -dy;
    set_point_y(
        std::max(0.0f, std::min(get_point_y(), window_height - get_height())));
  }

  set_width(get_width() + size_increment);
  set_height(get_height() + size_increment);

  if (get_width() >= max_size || get_height() >= max_size)
    size_increment = -size_increment;

  if (get_width() <= min_size || get_height() <= min_size)
    size_increment = -size_increment;

  draw();
}

std::string Rectangle::get_name() const { return "Rectangle"; }
