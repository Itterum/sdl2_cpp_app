#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../shape/shape.h"
#include <cairo/cairo.h>

class Rectangle : public Shape {
public:
  Rectangle(int x, int y, int w, int h);
  ~Rectangle();

  void shape(cairo_t *cr) override;
  void animate(void *pixels, int pitch, int window_width, int window_height);

private:
  int point_x;
  int point_y;
  int width;
  int height;
};

#endif
