#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <vector>
#include <string>
#include "book.hpp"

namespace samoilenko
{
  const std::string EMPTY = "<EMPTY>\n";
  const std::string INVALID_STEP = "<INVALID STEP>\n";
  const std::string INVALID_COMMAND = "<INVALID COMMAND>\n";
  const std::string INVALID_BOOKMARK = "<INVALID BOOKMARK>\n";
  std::vector< std::string > commandToArgs(const std::string& command);
  bool isNumberValid(const std::string& number);
  bool isNameValid(const std::string& name);
  std::string removeSlashes(const std::string& str);
}
#endif
