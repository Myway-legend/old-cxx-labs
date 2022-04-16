#include <iostream>
#include "supporting-things.hpp"
#include "tasks.hpp"

int main(int argc, char* argv[])
{
  srand(time(0));
  int mainCode = 0;

  if (argc < 2)
  {
    mainCode = 1;
  }

  int task = 0;
  if (!mainCode)
  {
    task = std::atoi(&argv[1][0]);
    const char* arg1 = argv[1];
    if (samoilenko::checkForSpaces(arg1))
    {
      mainCode = 1;
    }
  }

  if ((!mainCode) && (task == 1) && (argc == 3))
  {
    const char* order = argv[2];
    mainCode = samoilenko::task1(order);
  }
  else if ((!mainCode) && (task == 2) && (argc == 3))
  {
    const char* name = argv[2];
    mainCode = samoilenko::task2(name);
  }
  else if ((!mainCode) && (task == 3) && (argc == 2))
  {
    mainCode = samoilenko::task3();
  }
  else if ((!mainCode) && (task == 4) && (argc == 4))
  {
    const char* order = argv[2];
    const char* size = argv[3];
    if (samoilenko::checkIsNumber(size))
    {
      int size2 = std::atoi(size);
      mainCode = samoilenko::task4(order, size2);
    }
    else
    {
      std::cerr << "Invalid arguments\n";
      mainCode = 1;
    }
  }
  else
  {
    std::cerr << "Invalid arguments\n";
    mainCode = 1;
  }
  return mainCode;
}
