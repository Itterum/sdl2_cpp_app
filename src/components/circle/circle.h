#ifndef CIRCLE_H
#define CIRCLE_H

#include "../shape/shape.h"
#include <cairo/cairo.h>
#include <iostream>
#include <cmath>

class Circle : public Shape {
public:
  Circle(int x, int y, int w, int h);
  ~Circle();

  void shape(cairo_t *cr) override;
  void animate(void *pixels, int pitch, int window_width, int window_height) override;
};

#endif
