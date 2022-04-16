#include <boost/test/unit_test.hpp>
#include "container.hpp"

BOOST_AUTO_TEST_SUITE(testContainer)

BOOST_AUTO_TEST_CASE(testFactorial)
{
  samoilenko::Container container;
  size_t factorial = 1;
  int i = 1;
  for (auto iter = container.begin(); iter != container.end(); iter++, i++)
  {
    factorial *= i;
    BOOST_CHECK(*iter == factorial);
  }
}

BOOST_AUTO_TEST_CASE(testDecrementIterator)
{
  samoilenko::Container container;
  auto Iterator = container.end();
  size_t expectedFactorial = 1;
  for (size_t i = 2; i <= 10; i++) {
    expectedFactorial *= i;
  }
  for (size_t i = 10; i >= 1; i--) {
    BOOST_CHECK_EQUAL(expectedFactorial, *--Iterator);
    expectedFactorial /= i;
  }
  BOOST_CHECK(Iterator == container.begin());
}

BOOST_AUTO_TEST_SUITE_END()
