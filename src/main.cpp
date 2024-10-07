#include "app/application.h"
#include "components/rect/rectangle.h"

#include <components/circle/circle.h>

int main() {
  const Application app(800, 600, "Game Engine");

  Rectangle rect(50, 50, 32, 32);
  Circle circle(100, 100, 50, 50);

  std::vector<Shape *> shapes;

  shapes.push_back(&rect);
  shapes.push_back(&circle);

  app.main_loop(shapes, true);

  return 0;
}
