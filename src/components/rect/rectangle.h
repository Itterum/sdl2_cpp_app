#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../shape/shape.h"
#include <cairo/cairo.h>
#include <cmath>
#include <iostream>

class Rectangle : public Shape {
public:
  Rectangle(int x, int y, int w, int h);
  ~Rectangle();

  void shape(cairo_t *cr) override;
};

#endif
