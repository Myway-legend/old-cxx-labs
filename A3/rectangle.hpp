#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"

namespace samoilenko
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(double width, double height, const point_t& pos);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& position) override;
    void move(double x, double y) override;
    void scale(double factor) override;
  private:
    double width_;
    double height_;
    point_t pos_;
  };
}

#endif
