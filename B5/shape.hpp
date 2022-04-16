#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iosfwd>
#include <vector>

namespace samoilenko
{

  struct Point
  {
    int x, y;
  };
  using Shape = std::vector< Point >;

  std::istream& operator>>(std::istream& in, Point& point);
  std::ostream& operator<<(std::ostream& in, const Point& point);

  bool operator<(const Shape& shape1, const Shape& shape2);
  std::istream& operator>>(std::istream& in, Shape& shape);
  std::ostream& operator<<(std::ostream& out, const Shape& shape);

  bool isTri(const Shape& shape);
  bool isRect(const Shape& shape);
  bool isSq(const Shape& shape);
  bool isPent(const Shape& shape);
}

#endif
