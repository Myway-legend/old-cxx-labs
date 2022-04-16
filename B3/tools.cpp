#include "tools.hpp"
#include <iostream>
#include <functional>
#include <algorithm>

std::vector< std::string > samoilenko::commandToArgs(const std::string& command)
{
  std::vector< std::string > args(1);
  bool isQuotesInside = false;
  bool doEscapeNext = false;
  for (char character: command)
  {
    if (std::isspace(character))
    {
      if (isQuotesInside)
      {
        args.back() += character;
      }
      else
      {
        args.emplace_back();
      }
    }
    else if (character == '"' && !doEscapeNext)
    {
      isQuotesInside = !isQuotesInside;
      args.back() += character;
    }
    else if (character == '\\' && !doEscapeNext)
    {
      doEscapeNext = true;
    }
    else
    {
      args.back() += character;
      doEscapeNext = false;
    }
  }
  return args;
}

bool samoilenko::isNumberValid(const std::string& number)
{
  std::function< bool(char) > isValid
  {
    [](char c)
    {
      return std::isdigit(c);
    }
  };

  return std::all_of(number.data(), number.data() + number.length(), isValid);
}

bool samoilenko::isNameValid(const std::string& name)
{
  bool newLine = true;
  bool quotes = false;
  size_t nQuotes = 0;
  for (size_t i = 0; i < name.length(); i++)
  {
    if (name[i] == '\n')
    {
      newLine = false;
    }
    if (name[i] == '"')
    {
      if (i == 0 || i == name.length() - 1)
      {
        quotes = true;
      }
      nQuotes++;
    }
  }
  return newLine && quotes && (nQuotes >= 2);
}

std::string samoilenko::removeSlashes(const std::string& str)
{
  std::string temp = str;
  for (size_t i = 0; i < temp.length() - 1; i++)
  {
    if (temp[i] == '\\' && temp[i + 1] == '"')
    {
      temp.erase(i);
    }
  }
  return temp;
}
