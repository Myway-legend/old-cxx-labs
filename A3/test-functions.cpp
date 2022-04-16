#include "test-functions.hpp"

std::shared_ptr< samoilenko::Shape > samoilenko::makeRect()
{
  const double width = 3.0;
  const double height = 2.0;
  const samoilenko::point_t pos{ 9.0, 7.0 };
  return std::make_shared< samoilenko::Rectangle >(samoilenko::Rectangle(width, height, pos));
}

std::shared_ptr< samoilenko::Shape > samoilenko::makeCircle()
{
  const samoilenko::point_t pos{ 5.0, 8.0 };
  const double rad = 7.0;
  return std::make_shared< samoilenko::Circle >(samoilenko::Circle(rad, pos));
}
