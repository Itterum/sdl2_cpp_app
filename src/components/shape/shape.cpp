#include "shape.h"

void Shape::draw(void *pixels, int pitch) {
  cairo_surface_t *surface = cairo_image_surface_create_for_data(
      (unsigned char *)pixels, CAIRO_FORMAT_ARGB32, 640, 480, pitch);
  cairo_t *cr = cairo_create(surface);

  shape(cr);

  cairo_destroy(cr);
  cairo_surface_destroy(surface);
}

void Shape::animate(void *pixels, int pitch, int window_width,
                    int window_height) {
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

  draw(pixels, pitch);
}
