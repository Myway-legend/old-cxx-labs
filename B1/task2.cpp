#include "tasks.hpp"
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>

int samoilenko::task2(const char* file)
{
  std::ifstream input;
  input.open(file);
  if (!input.is_open())
  {
    std::cerr << "Opening error!\n";
    return 1;
  }
  size_t maxSize = 512;
  size_t size = 0;
  int coef = 2;
  std::unique_ptr< char[] > array = std::make_unique< char[] >(maxSize);
  while (!input.eof())
  {
    input.read(array.get() + size, maxSize - size);
    size += input.gcount();
    maxSize *= coef;
    std::unique_ptr< char[] > temp = std::make_unique< char [] >(maxSize);
    for (size_t i = 0; i < size; i++)
    {
      temp[i] = array[i];
    }
    array = std::move(temp);
  }
  input.close();
  std::vector< char > vector(array.get(), array.get() + size);
  for (size_t i = 0; i < size; i++)
  {
    std::cout << vector[i];
  }
  return 0;
}
