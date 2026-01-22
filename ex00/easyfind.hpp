#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <stdexcept>
# include <algorithm>
# include <iterator> 

template< typename T >
typename T::const_iterator easyfind(const T& container, int n);

#include "easyfind.tpp"

#endif