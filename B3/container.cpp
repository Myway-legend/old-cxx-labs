#include "container.hpp"
#include <cassert>

namespace samoilenko
{
  constexpr Container::ValueType factorial(Container::ValueType n)
  {
    return (n <= 1) ? 1 : (n * factorial(n - 1));
  }
  constexpr Container::ValueType beginMultiplier = 1;
  constexpr Container::ValueType beginValue = factorial(beginMultiplier);
  constexpr Container::ValueType endMultiplier = 11;
  constexpr Container::ValueType endValue = factorial(endMultiplier);
}

samoilenko::Container::Iterator::Iterator():
  value_(0),
  multiplier_(0)
{}

samoilenko::Container::Iterator::Iterator(ValueType value, ValueType multiplier):
  value_(value),
  multiplier_(multiplier)
{}

const samoilenko::Container::ValueType& samoilenko::Container::Iterator::operator*() const
{
  assert(value_ != 0);
  return value_;
}

const samoilenko::Container::ValueType* samoilenko::Container::Iterator::operator->() const
{
  assert(value_ != 0);
  return &value_;
}

samoilenko::Container::Iterator& samoilenko::Container::Iterator::operator++()
{
  assert(multiplier_ < endMultiplier);
  value_ *= ++multiplier_;
  return *this;
}

samoilenko::Container::Iterator samoilenko::Container::Iterator::operator++(int)
{
  Iterator temp = *this;
  ++(*this);
  return temp;
}

samoilenko::Container::Iterator& samoilenko::Container::Iterator::operator--()
{
  assert(multiplier_ > beginMultiplier);
  value_ /= multiplier_--;
  return *this;
}

samoilenko::Container::Iterator samoilenko::Container::Iterator::operator--(int)
{
  Iterator temp = *this;
  --(*this);
  return temp;
}

bool samoilenko::Container::Iterator::operator==(const Container::Iterator& other) const
{
  return **this == *other;
}

bool samoilenko::Container::Iterator::operator!=(const Container::Iterator& other) const
{
  return !(*this == other);
}

samoilenko::Container::Iterator samoilenko::Container::begin() const noexcept
{
  return { beginValue, beginMultiplier };
}

samoilenko::Container::Iterator samoilenko::Container::end() const noexcept
{
  return { endValue, endMultiplier };
}
