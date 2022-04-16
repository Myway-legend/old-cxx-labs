#include <iostream>
#include "tasks.hpp"

int main(int argc, char* argv[])
{
  int code = 0;
  if (argc != 2 || argv[1][1] == ' ')
  {
    std::cerr << "Invalid argument\n";
    code = 1;
    return code;
  }
  int task = std::atoi(argv[1]);
  if (task == 1)
  {
    return samoilenko::task1(std::cin, std::cout);
  }
  else if (task == 2)
  {
    return samoilenko::task2(std::cin, std::cout);
  }
  else
  {
    std::cerr << "Invalid argument\n";
    code = 1;
  }
  return code;
}
