#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "dataStruct.hpp"

int main()
{
  std::vector< samoilenko::DataStruct > v;
  std::copy(std::istream_iterator< samoilenko::DataStruct >(std::cin), std::istream_iterator< samoilenko::DataStruct >(), std::back_inserter(v));
  if (!std::cin.eof())
  {
    return 1;
  }
  std::sort(v.begin(), v.end());
  std::copy(v.begin(), v.end(), std::ostream_iterator< samoilenko::DataStruct >(std::cout, "\n"));
  return 0;
}
