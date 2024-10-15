#ifndef CIRCLE_H
#define CIRCLE_H

#include <components/shape/shape.h>

class Circle final : public Shape {
public:
  Circle(float x, float y, float w, float h);
  ~Circle() override;

  void draw() override;
  void animate(float window_width, float window_height) override;
};

#endif
