#ifndef HEAD_SPAN_HPP
# define HEAD_SPAN_HPP

#ifdef LIST_MODE
#include <list>
#endif
# include <vector>
# include <iostream>
# include <exception>
# include <algorithm>
# include <climits>
#include <stdexcept>
#include <ostream>


class Span
{
	private:
#ifdef VECTOR_MODE
		std::vector<unsigned int> _vec;
#else
		std::list<unsigned int> _list;
		unsigned int _capacity;
#endif
	public:
		Span(unsigned int num);
		Span(const Span & obj);
		~Span();
		Span	&operator=(const Span & obj);

#ifdef VECTOR_MODE
		const std::vector<unsigned int> &getVector() const;
#else
		const std::list<unsigned int> &getList() const;
#endif
		void	addNumber(unsigned int num);
		void	addNumber(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end);
		unsigned int longestSpan();
		unsigned int shortestSpan();
};

std::ostream	&operator<<(std::ostream &out, const Span &obj);

#endif