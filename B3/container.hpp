#ifndef CONTAINER_HPP
#define CONTAINER_CPP

#include <iterator>

namespace samoilenko
{

  class Container
  {
  public:
    using ValueType = unsigned int;
    class Iterator: public std::iterator< std::bidirectional_iterator_tag, ValueType >
    {
    public:
      Iterator();
      const ValueType& operator*() const;
      const ValueType* operator->() const;
      Iterator& operator++();
      Iterator operator++(int);
      Iterator& operator--();
      Iterator operator--(int);
      bool operator==(const Container::Iterator& other) const;
      bool operator!=(const Container::Iterator& other) const;
    private:
      ValueType value_;
      ValueType multiplier_;
      friend class Container;
      Iterator(ValueType value, ValueType multiplier);
    };

    Iterator begin() const noexcept;
    Iterator end() const noexcept;
  };
}

#endif
