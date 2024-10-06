#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int w, int h) {
  point_x = x;
  point_y = y;
  width = w;
  height = h;
}

Rectangle::~Rectangle() {}

void Rectangle::shape(cairo_t *cr) {
  cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);
  cairo_rectangle(cr, point_x, point_y, width, height);
  cairo_fill(cr);
}

void Rectangle::animate(void *pixels, int pitch, int window_width,
                        int window_height) {
  static int dx = 2;
  static int dy = 2;

  point_x += dx;
  point_y += dy;

  if (point_x <= 0 || point_x + width >= window_width) {
    dx = -dx;
  }
  if (point_y <= 0 || point_y + height >= window_height) {
    dy = -dy;
  }

  draw(pixels, pitch);
}
