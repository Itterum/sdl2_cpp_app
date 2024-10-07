#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../shape/shape.h"

class Rectangle final : public Shape {
public:
  Rectangle(float x, float y, float w, float h);
  ~Rectangle() override;

  void draw() override;
  void animate(float window_width, float window_height) override;
};

#endif
