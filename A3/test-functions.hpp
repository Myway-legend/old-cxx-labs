#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP

#include <iostream>
#include <memory>
#include <boost/test/unit_test.hpp>
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

namespace samoilenko
{
  const double TOLERANCE = 0.001;
  std::shared_ptr< Shape > makeRect();
  std::shared_ptr< Shape > makeCircle();
}

#endif
