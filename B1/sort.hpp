#ifndef SORT_HPP
#define SORT_HPP

#include "supporting-things.hpp"

namespace samoilenko
{
  template< class Strategy >
  void sort(typename Strategy::container& container, const samoilenko::Order order)
  {
    typename Strategy::iterator end = Strategy::end(container);
    typename Strategy::iterator start = Strategy::begin(container);
    while (start != end)
    {
      typename Strategy::iterator tempIter = start;
      while (tempIter != end)
      {
        if (((order == ORDER_DES) && (Strategy::get(container, start) < Strategy::get(container, tempIter))) ||
            ((order == ORDER_ASC) && (Strategy::get(container, start) > Strategy::get(container, tempIter))))
        {
          std::swap(Strategy::get(container, start), Strategy::get(container, tempIter));
        }
        tempIter++;
      }
      start++;
    }
  }
}

#endif
