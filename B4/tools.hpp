#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <string>
#include <vector>

namespace samoilenko
{

  constexpr int min = -5;
  constexpr int max = 5;

  bool isKeyValid(const std::string& key);
  std::vector< std::string > lineToKeys(const std::string& line);

}

#endif
