#include <boost/test/unit_test.hpp>
#include <vector>
#include <string>
#include "tools.hpp"

BOOST_AUTO_TEST_CASE(lineTokeys)
{
  std::string line1 = "-3,-2,aaaaa";
  std::string line2 = "1,5,gggggg";
  std::vector< std::string > v1 = { "-3", "-2", "aaaaa"};
  std::vector< std::string > v2 = { "1", "5", "gggggg"};
  std::vector< std::string > v3 = samoilenko::lineToKeys(line1);
  std::vector< std::string > v4 = samoilenko::lineToKeys(line2);
  BOOST_CHECK_EQUAL(v1[0], v3[0]);
  BOOST_CHECK_EQUAL(v1[1], v3[1]);
  BOOST_CHECK_EQUAL(v1[2], v3[2]);
  BOOST_CHECK_EQUAL(v2[0], v4[0]);
  BOOST_CHECK_EQUAL(v2[1], v4[1]);
  BOOST_CHECK_EQUAL(v2[2], v4[2]);
}

BOOST_AUTO_TEST_CASE(isKeyValid)
{
  std::string s1 = "-5";
  std::string s2 = "-25";
  std::string s3 = "+6";
  std::string s4 = "3";
  BOOST_CHECK_EQUAL(samoilenko::isKeyValid(s1), true);
  BOOST_CHECK_EQUAL(samoilenko::isKeyValid(s2), false);
  BOOST_CHECK_EQUAL(samoilenko::isKeyValid(s3), false);
  BOOST_CHECK_EQUAL(samoilenko::isKeyValid(s4), true);
}
