#include "shape.h"

void Shape::draw(void *pixels, int pitch) {
  cairo_surface_t *surface = cairo_image_surface_create_for_data(
      (unsigned char *)pixels, CAIRO_FORMAT_ARGB32, 640, 480, pitch);
  cairo_t *cr = cairo_create(surface);

  shape(cr);

  cairo_destroy(cr);
  cairo_surface_destroy(surface);
}
