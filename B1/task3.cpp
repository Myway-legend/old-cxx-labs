#include "tasks.hpp"
#include <iostream>
#include <vector>
#include "supporting-things.hpp"

int samoilenko::task3()
{
  std::vector< int > vector;
  int input = 0;
  while ((std::cin >> input) && (input != 0))
  {
    vector.push_back(input);
  }

  if ((std::cin.fail()) && (!std::cin.eof()))
  {
    std::cerr << "Reading error\n";
    return 1;
  }

  if (input != 0)
  {
    std::cerr << "Wrong input\n";
    return 1;
  }

  std::vector< int >::iterator iterator = vector.begin();
  if ((!vector.empty()) && (vector.back() == 1))
  {
    while (iterator != vector.end())
    {
      if (*iterator % 2 == 0)
      {
        iterator = vector.erase(iterator);
      }
      else
      {
        iterator++;
      }
    }
  }

  if ((!vector.empty()) && (vector.back() == 2))
  {
    while (iterator != vector.end())
    {
      if (*iterator % 3 == 0)
      {
        iterator = vector.insert(iterator + 1, 3, 1) + 2;
      }
      else
      {
        iterator++;
      }
    }
  }
  print(std::cout, vector);
  return 0;
}
