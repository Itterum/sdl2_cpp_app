#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <components/shape/shape.h>

class Rectangle final : public Shape {
public:
  Rectangle(int x, int y, int w, int h);
  ~Rectangle() override;

  void draw() override;
  void animate(int window_width, int window_height) override;
};

#endif
