#include <boost/test/unit_test.hpp>
#include <vector>
#include <algorithm>
#include "dataStruct.hpp"

BOOST_AUTO_TEST_CASE(key1)
{
  std::vector< samoilenko::DataStruct > vector;
  vector.push_back({ 5, 3, "zxc" });
  vector.push_back({ 2, 3, "zxc" });
  vector.push_back({ -4, 3, "zxc" });
  std::sort(vector.begin(), vector.end());
  BOOST_CHECK(std::is_sorted(vector.begin(), vector.end()));
}

BOOST_AUTO_TEST_CASE(key2)
{
  std::vector< samoilenko::DataStruct > vector;
  vector.push_back({ 0, -5, "zxc" });
  vector.push_back({ 0, -3, "zxc" });
  vector.push_back({ 0, -4, "zxc" });
  std::sort(vector.begin(), vector.end());
  BOOST_CHECK(std::is_sorted(vector.begin(), vector.end()));
}

BOOST_AUTO_TEST_CASE(str)
{
  std::vector< samoilenko::DataStruct > vector;
  vector.push_back({ 0, 0, "sdasdfgsdgsdfggsg" });
  vector.push_back({ 0, 0, "fzghjdfdfguudfgufdghuhufg" });
  vector.push_back({ 0, 0, "zzzz" });
  std::sort(vector.begin(), vector.end());
  BOOST_CHECK(std::is_sorted(vector.begin(), vector.end()));
}
