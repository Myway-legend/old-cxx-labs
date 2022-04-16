#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

namespace samoilenko
{
  using s_ptr = std::shared_ptr< Shape >;
  using s_container = std::unique_ptr< s_ptr[] >;

  void printStartingPosition(const s_container& compShape, const size_t count)
  {
    point_t tempPos = { 0.0, 0.0 };
    for (size_t i = 0; i < count; i++)
    {
      tempPos = compShape[i]->getFrameRect().pos;
      std::cout << "Start pos: (" << tempPos.x << ";" << tempPos.y << ")\n";
    }
  }

  void moveShapes(s_container& compShape, const size_t count)
  {
    point_t tempPos = { 0.0, 0.0 };
    const point_t newPosition = { 6.4, 12.8 };
    for (size_t i = 0; i < count; i++)
    {
      compShape[i]->move(newPosition);
      tempPos = compShape[i]->getFrameRect().pos;
      std::cout << "Move(point_t) pos: (" << tempPos.x << ";" << tempPos.y << ")\n";
    }
    const double dx = 1.6;
    const double dy = 3.2;
    for (size_t i = 0; i < count; i++)
    {
      compShape[i]->move(dx, dy);
      tempPos = compShape[i]->getFrameRect().pos;
      std::cout << "Move(x, y) pos: (" << tempPos.x << ";" << tempPos.y << ")\n";
    }
  }

  void printFrameRects(const s_container& compShape, const size_t count)
  {
    rectangle_t temp = compShape[0]->getFrameRect();
    for (size_t i = 0; i < count; i++)
    {
      temp = compShape[i]->getFrameRect();
      std::cout << "Frame rectangle #" << i + 1 << "\n";
      std::cout << "Width: " << temp.width << "\n";
      std::cout << "Height: " << temp.height << "\n";
      std::cout << "Position: (" << temp.pos.x << ";" << temp.pos.y << ")\n\n";
    }
  }
}

int main()
{
  using namespace samoilenko;
  const point_t position1 = { 0.0, 0.0 };
  const point_t position2 = { 5.0, 6.0 };
  const point_t position3 = { -2.0, -3.5 };
  const size_t count = 3;
  s_ptr figure1 = std::make_shared< Rectangle >(Rectangle(8.5, 4.0, position1));
  s_ptr figure2 = std::make_shared< Circle >(Circle(3.5, position2));
  s_ptr figure3 = std::make_shared< Rectangle >(Rectangle(10.0, 25.6, position3));
  s_container array = std::make_unique< s_ptr[] >(count);
  array[0] = figure1;
  array[1] = figure2;
  array[2] = figure3;
  printStartingPosition(array, count);
  moveShapes(array, count);
  printFrameRects(array, count);

  std::cout << "Lab A3:\n\n";
  const double coef = 2.0;
  CompositeShape compositeShape{ figure1, figure2, figure3 };
  printStartingPosition(array, count);
  std::cout << "\ncompositeShape.scale(" << coef << ")\n";
  compositeShape.scale(coef);
  printFrameRects(array, count);
  return 0;
}
