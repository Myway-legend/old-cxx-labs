#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include <vector>
#include <forward_list>

namespace samoilenko
{
  template< class T >
  struct StrategyOperator
  {
    using iterator = size_t;
    using container = typename std::vector< T >;

    static iterator begin(const container&)
    {
      return 0;
    }
    static iterator end(const container& cont)
    {
      return cont.size();
    }
    static T& get(container& cont, iterator iter)
    {
      return cont[iter];
    }
  };

  template< class T >
  struct StrategyAt
  {
    using iterator = size_t;
    using container = typename std::vector< T >;

    static iterator begin(const container&)
    {
      return 0;
    }
    static iterator end(const container& cont)
    {
      return cont.size();
    }
    static T& get(container& cont, iterator iter)
    {
      return cont.at(iter);
    }
  };

  template< class T >
  struct StrategyIter
  {
    using iterator = typename std::forward_list< T >::iterator;
    using container = std::forward_list< T >;

    static iterator begin(container& container)
    {
      return container.begin();
    }
    static iterator end(container& container)
    {
      return container.end();
    }
    static T& get(container&, iterator iter)
    {
      return *iter;
    }
  };
}

#endif
