#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

template< typename T >
typename T::const_iterator easyfind(const T& container, int n)
{
	typename T::const_iterator it;
	it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw std::invalid_argument("Can not find n");
	return it;
}

#endif