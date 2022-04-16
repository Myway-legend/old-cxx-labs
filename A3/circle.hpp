#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"

namespace samoilenko
{
  class Circle: public Shape
  {
  public:
    Circle(double radius_, const point_t& position);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& position) override;
    void move(double x, double y) override;
    void scale(double factor) override;
  private:
    double radius_;
    point_t pos_;
  };
}

#endif
