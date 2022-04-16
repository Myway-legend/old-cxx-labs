#include "tools.hpp"

bool samoilenko::isKeyValid(const std::string& key)
{
  std::string temp = key;
  if (key[0] == '+')
  {
    temp = key.substr(1, key.length() - 1);
  }
  int intKey = std::stoi(temp);
  return !(intKey < -5 || intKey > 5);
}

std::vector< std::string > samoilenko::lineToKeys(const std::string& line)
{
  std::vector< std::string > args;
  size_t len = line.length();
  size_t comma1 = line.find(',');
  size_t comma2 = line.find(',', comma1 + 1);
  if (comma1 != std::string::npos && comma2 != std::string::npos)
  {
    args.push_back(line.substr(0, len - line.substr(comma1, std::string::npos).length()));
    args.push_back(line.substr(comma1 + 1, comma2 - comma1 - 1));
    args.push_back(line.substr(comma2 + 1, std::string::npos));
  }
  return args;
}
