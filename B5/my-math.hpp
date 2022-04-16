#ifndef MY_MATH_HPP
#define MY_MATH_HPP

#include "shape.hpp"

namespace samoilenko
{

  inline int squareDistance(const Point& p1, const Point& p2);
  bool isSidesEqual(const Shape& shape);
  int countVertices(int vert, const Shape& shape);

}

#endif
