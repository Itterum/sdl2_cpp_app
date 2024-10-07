#include "app/application.h"
#include "components/rect/rectangle.h"

int main() {
  const Application app(800, 600, "Game Engine");

  Rectangle rect(50, 50, 32, 32);

  std::vector<Shape *> shapes;

  shapes.push_back(&rect);

  app.main_loop(shapes, true);

  return 0;
}
