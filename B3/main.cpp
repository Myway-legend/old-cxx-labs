#include <iostream>
#include "tasks.hpp"

int main(int argc, char *argv[])
{
  int mainCode = 0;
  if (argc != 2) {
    std::cerr << "Invalid arguments";
    mainCode = 1;
  }
  if (!mainCode)
  {
    std::string task = argv[1];
    if (task == "1")
    {
      mainCode = samoilenko::bookTask(std::cin, std::cout);
    }
    else if (task == "2")
    {
      mainCode = samoilenko::containerTask(std::cout);
    }
    else
    {
      std::cerr << "Invalid task number";
      mainCode = 1;
    }
  }
  return mainCode;
}
