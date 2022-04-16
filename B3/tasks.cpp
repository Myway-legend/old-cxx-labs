#include "tasks.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include "book.hpp"
#include "container.hpp"
#include "bookUserInterface.hpp"
#include "tools.hpp"

int samoilenko::bookTask(std::istream& in, std::ostream& out)
{
  Book book;
  std::string command = "0";
  while (std::getline(in, command))
  {
    std::vector< std::string > args = samoilenko::commandToArgs(command);
    executeUserInterface(book, args, out);
  }
  return in.eof() ? 0 : 1;
}

int samoilenko::containerTask(std::ostream& out)
{
  Container container;
  std::ostream_iterator< Container::ValueType > ostreamIterator(out, " ");
  std::copy(container.begin(), container.end(), ostreamIterator);
  out << '\n';
  std::reverse_copy(container.begin(), container.end(), ostreamIterator);
  out << '\n';
  return 0;
}
