#include "shape.hpp"
#include <iostream>
#include <algorithm>
#include <iterator>
#include "my-math.hpp"

std::istream& samoilenko::operator>>(std::istream& in, Point& point)
{
  std::ios_base::iostate fbit = std::ios_base::failbit;
  int x = 0;
  int y = 0;
  in >> std::ws;
  if (in.get() != '(')
  {
    in.clear();
    in.setstate(fbit);
    return in;
  }
  in >> std::ws;
  if (in.peek() == '\n')
  {
    in.setstate(fbit);
    return in;
  }
  in >> x >> std::ws;
  if (!in || in.get() != ';')
  {
    in.setstate(fbit);
    return in;
  }
  in >> std::ws;
  if (in.peek() == '\n')
  {
    in.setstate(fbit);
    return in;
  }
  in >> y >> std::ws;
  if (!in || in.get() != ')')
  {
    in.setstate(fbit);
    return in;
  }
  point = { x, y };
  return in;
}

std::ostream& samoilenko::operator<<(std::ostream& out, const Point& point)
{
  out << '(' << point.x << ';' << point.y << ')';
  return out;
}

bool samoilenko::operator<(const Shape& shape1, const Shape& shape2)
{
  if (shape1.size() < 5 && shape2.size() < 5)
  {
    if (shape1.size() == 4 && shape2.size() == 4)
    {
      return isSq(shape1) && !isSq(shape2);
    }
  }
  return shape1.size() < shape2.size();
}

std::istream& samoilenko::operator>>(std::istream& in, Shape& shape)
{
  std::ios_base::iostate fbit = std::ios_base::failbit;
  size_t n = 0;
  in >> n;

  if (!in || in.get() != ' ')
  {
    in.setstate(fbit);
    return in;
  }

  Shape temp;
  temp.reserve(n);
  std::copy_n(std::istream_iterator< Point >(in), n, std::back_inserter(temp));

  if ((in.fail() && !in.eof()) || temp.size() != n)
  {
    in.setstate(fbit);
    return in;
  }

  shape = temp;
  return in;
}

std::ostream& samoilenko::operator<<(std::ostream& out, const Shape& shape)
{
  out << shape.size() << ' ';
  std::copy(shape.begin(), shape.end(), std::ostream_iterator< Point >(out, " "));
  return out;
}

bool samoilenko::isTri(const Shape& shape)
{
  return shape.size() == 3;
}

bool samoilenko::isRect(const Shape& shape)
{
  return shape.size() == 4;
}

bool samoilenko::isSq(const Shape& shape)
{
  return isRect(shape) && isSidesEqual(shape);
}

bool samoilenko::isPent(const Shape& shape)
{
  return shape.size() == 5;
}
