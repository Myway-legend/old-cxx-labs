#include <iostream>
#include <vector>
#include <forward_list>
#include <cstring>
#include "tasks.hpp"
#include "supporting-things.hpp"
#include "sort.hpp"
#include "strategy.hpp"

int samoilenko::task1(const char* order)
{
  if (strcmp(order, "ascending") && strcmp(order, "descending"))
  {
    std::cerr << "Invalid order!\n";
    return 1;
  }

  int input = 0;
  std::vector< int > vector1;

  while (std::cin >> input)
  {
    vector1.push_back(input);
  }
  if ((std::cin.fail()) && (!std::cin.eof()))
  {
    std::cerr << "Something's gone wrong with input\n";
    return 1;
  }

  std::vector< int > vector2 = vector1;
  std::forward_list< int > list(vector1.begin(), vector1.end());
  Order sortMode = getSortMode(order);
  sort< StrategyOperator< int > >(vector1, sortMode);
  sort< StrategyAt< int > >(vector2, sortMode);
  sort< StrategyIter< int > >(list, sortMode);
  print(std::cout, vector1);
  print(std::cout, vector2);
  print(std::cout, list);
  return 0;
}
