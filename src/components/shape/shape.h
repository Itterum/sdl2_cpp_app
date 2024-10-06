#ifndef SHAPE_H
#define SHAPE_H

#include <cairo/cairo.h>

class Shape {
public:
  void draw(void *pixels, int pitch);
  virtual void animate(void *pixels, int pitch, int window_width, int window_height);
  virtual void shape(cairo_t *cr) = 0;

  int get_point_x() const { return point_x; }
  int get_point_y() const { return point_y; }
  int get_width() const { return width; }
  int get_height() const { return height; }

  void set_point_x(int x) { point_x = x; }
  void set_point_y(int y) { point_y = y; }
  void set_width(int w) { width = w; }
  void set_height(int h) { height = h; }

protected:
  int point_x;
  int point_y;
  int width;
  int height;
};

#endif
