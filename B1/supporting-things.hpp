#ifndef THINGS_HPP
#define THINGS_HPP

#include <iostream>

namespace samoilenko
{
  enum Order
  {
    ORDER_DES,
    ORDER_ASC,
    ORDER_ERROR,
  };

  template< class T >
  void print(std::ostream& out, const T& container)
  {
    typename T::const_iterator start = container.begin();
    typename T::const_iterator end = container.end();
    while (start != end)
    {
      out << *start << " ";
      start++;
    }
    std::cout << "\n";
  }

  Order getSortMode(const char* order);
  void fillRandom(double* array, int size);
  bool checkIsNumber(const char* str);
  bool checkForSpaces(const char* str);
}

#endif
