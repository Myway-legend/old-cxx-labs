#include "my-math.hpp"
#include <algorithm>
#include <functional>

inline int samoilenko::squareDistance(const Point& p1, const Point& p2)
{
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool samoilenko::isSidesEqual(const Shape& shape)
{
  int lastSide = squareDistance(shape[0], shape[3]);
  std::vector< int > sides;
  sides.reserve(shape.size());
  std::transform(shape.begin() + 1, shape.end(), shape.begin(), std::back_inserter(sides), squareDistance);
  return std::all_of(sides.begin(), sides.end(), std::bind(std::equal_to<>(), std::placeholders::_1, lastSide));
}

int samoilenko::countVertices(int vert, const Shape& shape)
{
  return vert + shape.size();
}
