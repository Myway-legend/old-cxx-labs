#include "tasks.hpp"
#include <iostream>
#include <vector>
#include <cstring>
#include "sort.hpp"
#include "strategy.hpp"
#include "supporting-things.hpp"

int samoilenko::task4(const char* order, size_t size)
{
  if (strcmp(order, "ascending") && strcmp(order, "descending"))
  {
    std::cerr << "Wrong order\n";
    return 1;
  }
  std::vector< double > vector(size);
  samoilenko::fillRandom(vector.data(), size);
  samoilenko::print(std::cout, vector);
  samoilenko::sort< samoilenko::StrategyOperator< double > >(vector, getSortMode(order));
  samoilenko::print(std::cout, vector);
  return 0;
}
