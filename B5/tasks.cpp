#include "tasks.hpp"
#include <iostream>
#include <unordered_set>
#include <iterator>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include "shape.hpp"
#include "my-math.hpp"

int samoilenko::task1(std::istream& in, std::ostream& out)
{
  using Iterator = std::istream_iterator< std::string >;
  std::unordered_set< std::string > data(Iterator{ in }, Iterator());

  if (!in.eof() && in.fail())
  {
    std::cerr << "Invalid input\n";
    return 1;
  }

  std::copy(data.begin(), data.end(), std::ostream_iterator< std::string >(out, "\n"));
  return 0;
}

samoilenko::Point frontPoint(const samoilenko::Shape& shape);

int samoilenko::task2(std::istream& in, std::ostream& out)
{
  std::vector< Shape > shapes;
  std::istream_iterator< Shape > firstIterator(in);
  std::istream_iterator< Shape > lastIterator;
  std::copy(firstIterator, lastIterator, std::back_inserter(shapes));

  if (!in.eof() && in.fail())
  {
    std::cerr << "Invalid input\n";
    return 1;
  }

  int vertices = std::accumulate(shapes.begin(), shapes.end(), 0, samoilenko::countVertices);
  int triangles = std::count_if(shapes.begin(), shapes.end(), samoilenko::isTri);
  int squares = std::count_if(shapes.begin(), shapes.end(), samoilenko::isSq);
  int rectangles = std::count_if(shapes.begin(), shapes.end(), samoilenko::isRect);

  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), samoilenko::isPent), shapes.end());
  std::vector< samoilenko::Point > points;
  std::transform(shapes.begin(), shapes.end(), std::back_inserter(points), frontPoint);

  std::vector< Shape >::iterator firstIt = std::partition(shapes.begin(), shapes.end(), isTri);
  std::vector< Shape >::iterator secondIt = std::partition(firstIt, shapes.end(), isSq);
  std::partition(secondIt, shapes.end(), isRect);

  out << "Vertices: " << vertices << '\n';
  out << "Triangles: " << triangles << '\n';
  out << "Squares: " << squares << '\n';
  out << "Rectangles: " << rectangles << '\n';
  out << "Points: ";
  std::copy(points.begin(), points.end(), std::ostream_iterator< samoilenko::Point >(out, " "));
  out << '\n';
  out << "Shapes:" << '\n';
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator< samoilenko::Shape >(out, "\n"));
  return 0;
}

samoilenko::Point frontPoint(const samoilenko::Shape& shape)
{
  return shape.front();
}
