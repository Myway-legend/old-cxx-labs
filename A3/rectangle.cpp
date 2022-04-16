#include "rectangle.hpp"
#include "base-types.hpp"

samoilenko::Rectangle::Rectangle(const double width, const double height, const point_t& pos):
  width_(width),
  height_(height),
  pos_(pos)
{
  if ((width <= 0) || (height <= 0))
  {
    throw std::invalid_argument("Width and height must be more than 0");
  }
}

double samoilenko::Rectangle::getArea() const
{
  return height_ * width_;
}

samoilenko::rectangle_t samoilenko::Rectangle::getFrameRect() const
{
  return { width_, height_, pos_ };
}

void samoilenko::Rectangle::move(const point_t& position)
{
  pos_ = position;
}

void samoilenko::Rectangle::move(const double x, const double y)
{
  pos_.x += x;
  pos_.y += y;
}

void samoilenko::Rectangle::scale(const double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Factor must be more than 0");
  }
  width_ *= factor;
  height_ *= factor;
}
