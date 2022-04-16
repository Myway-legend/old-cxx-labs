#include <sstream>
#include <boost/test/unit_test.hpp>
#include "shape.hpp"

BOOST_AUTO_TEST_SUITE(testPoint)

  BOOST_AUTO_TEST_CASE(wrong1)
  {
    std::string line("(11352-;1452783)");
    std::stringstream sin(line);
    samoilenko::Point point;
    BOOST_CHECK(!(sin >> point));
  }

  BOOST_AUTO_TEST_CASE(wrong2)
  {
    std::string line("(afdh2;jkkh3)");
    std::stringstream sin(line);
    samoilenko::Point point;
    BOOST_CHECK(!(sin >> point));
  }

  BOOST_AUTO_TEST_CASE(wrong3)
  {
    std::string line("(-152;asa2)");
    std::stringstream sin(line);
    samoilenko::Point point;
    BOOST_CHECK(!(sin >> point));
  }

  BOOST_AUTO_TEST_CASE(ok)
  {
    std::string line("(     -32   ;          13        )");
    std::stringstream sin(line);
    samoilenko::Point point;
    BOOST_CHECK(sin >> point);
  }

BOOST_AUTO_TEST_SUITE_END()
