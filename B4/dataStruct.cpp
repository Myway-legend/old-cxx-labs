#include "dataStruct.hpp"
#include <iostream>
#include "tools.hpp"

bool samoilenko::operator<(const DataStruct& d1, const DataStruct& d2)
{
  if (d1.key1 == d2.key1)
  {
    if (d1.key2 == d2.key2)
    {
      return (d1.str.length() < d2.str.length());
    }
    return (d1.key2 < d2.key2);
  }
  return (d1.key1 < d2.key1);
}

bool samoilenko::operator>(const DataStruct& d1, const DataStruct& d2)
{
  return !(d1 < d2) && !(d1 == d2);
}

bool samoilenko::operator==(const DataStruct& d1, const DataStruct& d2)
{
  return !(d1 < d2) && !(d2 < d1);
}

bool samoilenko::operator!=(const DataStruct& d1, const DataStruct& d2)
{
  return (d1 < d2) || (d2 < d1);
}

std::ostream& samoilenko::operator<<(std::ostream& out, const DataStruct& d)
{
  out << d.key1 << "," << d.key2 << "," << d.str;
  return out;
}

std::istream& samoilenko::operator>>(std::istream& in, DataStruct& d)
  {
    std::string line;
    std::vector< std::string > args;
    std::getline(std::cin, line);
    args = samoilenko::lineToKeys(line);
    if (args.size() != 3)
    {
      in.setstate(std::istream::failbit);
    }
    else
    {
      if (samoilenko::isKeyValid(args[0]) && samoilenko::isKeyValid(args[1]))
      {
        d = { std::stoi(args[0]), std::stoi(args[1]), args[2] };
      }
      else
      {
        in.setstate(std::istream::failbit);
      }
    }
    return in;
  }
