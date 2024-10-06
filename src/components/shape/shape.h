#ifndef SHAPE_H
#define SHAPE_H

#include <cairo/cairo.h>

class Shape {
public:
  void draw(void *pixels, int pitch);
  virtual void shape(cairo_t *cr) = 0;
};

#endif
