#include "shape.h"

void Shape::animate(const int window_width, const int window_height) {
  static int dx = 2;
  static int dy = 2;

  set_point_x(get_point_x() + dx);
  set_point_y(get_point_y() + dy);

  if (get_point_x() <= 0 || get_point_x() + get_width() >= window_width) {
    dx = -dx;
  }
  if (get_point_y() <= 0 || get_point_y() + get_height() >= window_height) {
    dy = -dy;
  }
}
