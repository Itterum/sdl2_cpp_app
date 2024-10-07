#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
  virtual ~Shape() = default;
  virtual void draw() = 0;
  virtual void animate(int window_width, int window_height);

  int get_point_x() const { return point_x; }
  int get_point_y() const { return point_y; }
  int get_width() const { return width; }
  int get_height() const { return height; }

  void set_point_x(int x) { point_x = x; }
  void set_point_y(int y) { point_y = y; }
  void set_width(int w) { width = w; }
  void set_height(int h) { height = h; }

protected:
  int point_x = 0;
  int point_y = 0;
  int width = 0;
  int height = 0;
};

#endif
