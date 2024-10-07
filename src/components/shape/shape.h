#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
  virtual ~Shape() = default;
  virtual void draw() = 0;
  virtual void animate(float window_width, float window_height);

  float get_point_x() const { return point_x; }
  float get_point_y() const { return point_y; }
  float get_width() const { return width; }
  float get_height() const { return height; }

  void set_point_x(const float x) { point_x = x; }
  void set_point_y(const float y) { point_y = y; }
  void set_width(const float w) { width = w; }
  void set_height(const float h) { height = h; }

protected:
  float point_x = 0;
  float point_y = 0;
  float width = 0;
  float height = 0;
};

#endif
