#include <sstream>
#include <boost/test/unit_test.hpp>
#include "shape.hpp"

BOOST_AUTO_TEST_SUITE(testShape)

  BOOST_AUTO_TEST_CASE(wrong)
  {
    std::string line("3 (12;gfd) (66;66) (55;55)");
    std::stringstream sin(line);
    samoilenko::Shape shp;
    BOOST_CHECK(!(sin >> shp));
  }

  BOOST_AUTO_TEST_CASE(ok)
  {
    std::string line("4          (12;12)    (66;66)  (55;55) (15;15)");
    std::stringstream sin(line);
    samoilenko::Shape shp;
    BOOST_CHECK(sin >> shp);
  }

BOOST_AUTO_TEST_SUITE_END()
