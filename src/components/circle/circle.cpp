#include "circle.h"

Circle::Circle(int x, int y, int w, int h) {
  point_x = x;
  point_y = y;
  width = w;
  height = h;
}

Circle::~Circle() {}

void Circle::shape(cairo_t *cr) {
  cairo_set_source_rgb(cr, 0.0, 0.0, 1.0); // Установим цвет (синий)

  double radius = width / 2.0; // Радиус круга, можно взять ширину для расчета
  double center_x = point_x + radius; // Центр круга по оси X
  double center_y = point_y + radius; // Центр круга по оси Y

  cairo_arc(cr, center_x, center_y, radius, 0, 2 * M_PI); // Рисуем круг
  cairo_fill(cr); // Заполняем круг цветом
}

void Circle::animate(void *pixels, int pitch, int window_width,
                     int window_height) {
  static double angle = 0.0;
  static int center_x = window_width / 2;
  static int center_y = window_height / 2;
  static int radius = 100;

  // Вычисляем положение объекта по синусоиде
  int x = center_x + static_cast<int>(radius * std::cos(angle));
  int y = center_y + static_cast<int>(radius * std::sin(angle));

  set_point_x(x);
  set_point_y(y);

  angle += 0.05; // Угол увеличивается для движения по окружности

  // Обновляем экран
  draw(pixels, pitch);
}
