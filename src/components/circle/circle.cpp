#include <GLFW/glfw3.h>
#include <circle.h>
#include <cmath>

Circle::Circle(const float x, const float y, const float w, const float h) {
  set_point_x(x);
  set_point_y(y);
  set_width(w);
  set_height(h);
}

Circle::~Circle() = default;

void Circle::draw() {
  change_color();

  const float radius = width / 2;
  const float center_x = point_x + radius;
  const float center_y = point_y + radius;
  constexpr int num_segments = 360;

  glBegin(GL_POLYGON);
  for (int i = 0; i < num_segments; ++i) {
    const auto theta = static_cast<float>(2.0f * M_PI * i / num_segments);
    const float x = radius * cosf(theta);
    const float y = radius * sinf(theta);
    glVertex2f(x + center_x, y + center_y);
  }
  glEnd();
}
void Circle::draw_center_point(const float center_x, const float center_y) {
  glColor3f(0.0f, 0.0f, 1.0f);

  constexpr float size = 5.0f;
  glBegin(GL_QUADS);
  glVertex2f(center_x - size, center_y - size);
  glVertex2f(center_x + size, center_y - size);
  glVertex2f(center_x + size, center_y + size);
  glVertex2f(center_x - size, center_y + size);
  glEnd();
}

void Circle::animate(const float window_width, const float window_height) {
  static float angle = 0.0;
  static float center_x = window_width / 2;
  static float center_y = window_height / 2;
  static float radius = 100.0f;

  const auto x = center_x + radius * std::cos(angle);
  const auto y = center_y + radius * std::sin(angle);

  set_point_x(x - get_width() / 2);
  set_point_y(y - get_height() / 2);

  angle += 0.05f;

  set_width(get_width() + size_increment);
  set_height(get_height() + size_increment);

  if (get_width() >= max_size || get_height() >= max_size)
    size_increment = -size_increment;

  if (get_width() <= min_size || get_height() <= min_size)
    size_increment = -size_increment;

  draw();
  // draw_center_point(center_x, center_y); // method for debug center
}

std::string Circle::get_name() const { return "Circle"; }
