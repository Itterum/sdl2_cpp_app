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
