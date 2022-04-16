#ifndef DATA_STRUCT_HPP
#define DATA_STRUCT_HPP

#include <iosfwd>
#include <string>

namespace samoilenko
{

  struct DataStruct
  {
    int key1;
    int key2;
    std::string str;
  };

  bool operator<(const DataStruct& d1, const DataStruct& d2);
  bool operator>(const DataStruct& d1, const DataStruct& d2);
  bool operator==(const DataStruct& d1, const DataStruct& d2);
  bool operator!=(const DataStruct& d1, const DataStruct& d2);

  std::ostream& operator<<(std::ostream& out, const DataStruct& d);
  std::istream& operator>>(std::istream& in, DataStruct& d);

}

#endif
