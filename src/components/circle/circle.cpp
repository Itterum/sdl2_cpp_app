#include <circle.h>
#include <GLFW/glfw3.h>
#include <cmath>

Circle::Circle(const float x, const float y, const float w, const float h) {
  set_point_x(x);
  set_point_y(y);
  set_width(w);
  set_height(h);
}

Circle::~Circle() = default;

void Circle::draw() {
  glColor3f(0.0f, 0.0f, 1.0f);

  const float radius = width / 2;
  const float center_x = point_x + radius;
  const float center_y = point_y + radius;
  constexpr int num_segments = 360;

  constexpr float theta = M_PI * 2 / static_cast<float>(num_segments);
  const float tang_factor = tanf(theta);

  const float radial_factor = cosf(theta);

  float x = radius;
  float y = 0;

  glLineWidth(2);
  glBegin(GL_POLYGON);
  for (int ii = 0; ii < num_segments; ii++) {
    glVertex2f(x + center_x, y + center_y);

    const float tx = -y;
    const float ty = x;

    x += tx * tang_factor;
    y += ty * tang_factor;

    x *= radial_factor;
    y *= radial_factor;
  }
  glEnd();
}

void Circle::animate(const float window_width, const float window_height) {
  static float angle = 0.0;
  static float center_x = window_width / 2;
  static float center_y = window_height / 2;
  static float radius = 100;

  const auto x = center_x + radius * std::cos(angle);
  const auto y = center_y + radius * std::sin(angle);

  set_point_x(x);
  set_point_y(y);

  angle += 0.05;

  draw();
}
