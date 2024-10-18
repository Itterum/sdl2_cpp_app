#include <GLFW/glfw3.h>
#include <shape.h>

void Shape::animate(const float window_width, const float window_height) {
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
}

void Shape::change_color() {
  const float red = get_point_x() / 800.0f;
  const float green = get_point_y() / 600.0f;
  const float blue = 1.0f - (red + green) / 2.0f;

  glColor3f(red, green, blue);
}
