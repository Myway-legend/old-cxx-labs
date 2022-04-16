#include <boost/test/unit_test.hpp>
#include "tools.hpp"

BOOST_AUTO_TEST_SUITE(test)

BOOST_AUTO_TEST_CASE(testCommandsToArgs)
{
  const std::string input1 = "add 123123 papa";
  const std::string input2 = "store current ASIJDIgjfdkf";
  const std::string input3 = "insert after current 123123 papa";
  BOOST_CHECK_EQUAL("add", samoilenko::commandToArgs(input1)[0]);
  BOOST_CHECK_EQUAL("current", samoilenko::commandToArgs(input2)[1]);
  BOOST_CHECK_EQUAL("123123", samoilenko::commandToArgs(input3)[3]);
}
BOOST_AUTO_TEST_SUITE_END()
