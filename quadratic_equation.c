#include "quadratic_equation.h"

#include <math.h>

Roots solve_equation(double a, double b, double c) {
  Roots roots;
  double discriminant = b * b - 4 * a * c;
  if (discriminant > 0) {
    roots.x1 = (-b + sqrt(discriminant)) / (2 * a);
    roots.x2 = (-b - sqrt(discriminant)) / (2 * a);
  } else if (discriminant == 0) {
    roots.x1 = roots.x2 = (-b) / (2 * a);
  } else {
    roots.x1 = roots.x2 = NAN;
  }
  return roots;
}