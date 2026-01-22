#include "Span.hpp"

#ifdef VECTOR_MODE
Span::Span(unsigned int num)
{
	_vec.reserve(num);
}

Span::Span(const Span & obj)
{
	_vec = obj._vec;
}

Span::~Span() {}

Span	&Span::operator=(const Span & obj)
{
	if (this != &obj)
		_vec = obj._vec;
	return (*this);
}

const std::vector<unsigned int> &Span::getVector() const
{
	return _vec;
}

void	Span::addNumber(unsigned int num)
{
	if (_vec.size() >= _vec.capacity())
		throw std::overflow_error("Span is full");
	_vec.push_back(num);
}

void	Span::addNumber(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end)
{
	size_t rangeSize = std::distance(begin, end);
	if (_vec.size() + rangeSize > _vec.capacity())
		throw std::overflow_error("Adding this range would exceed Span capacity");
	_vec.insert(_vec.end(), begin, end);
}

unsigned int	Span::longestSpan()
{
	if (_vec.size() < 2)
		throw std::length_error("Not enough numbers to find a span");

	unsigned int minNum = *std::min_element(_vec.begin(), _vec.end());
	unsigned int maxNum = *std::max_element(_vec.begin(), _vec.end());

	return (maxNum - minNum);
}

unsigned int	Span::shortestSpan()
{
	if (_vec.size() < 2)
		throw std::length_error("Not enough numbers to find a span");

	std::vector<unsigned int> sortedArray = _vec;
	std::sort(sortedArray.begin(), sortedArray.end());

	unsigned int minSpan = UINT_MAX;
	for (size_t i = 1; i < sortedArray.size(); ++i)
	{
		unsigned int span = sortedArray[i] - sortedArray[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

std::ostream	&operator<<(std::ostream &out, const Span &obj)
{
	out << "Span with " << obj.getVector().size() << " elements: ";
	for (size_t i = 0; i < obj.getVector().size(); ++i)
	{
		out << obj.getVector()[i];
		if (i < obj.getVector().size() - 1)
			out << ", ";
	}
	return out;
}

#else
Span::Span(unsigned int num)
{
	// _list.resize(num);
	_capacity = num;
}

Span::Span(const Span & obj)
{
	_list = obj._list;
	_capacity = obj._capacity;
}

Span::~Span() {}

Span	&Span::operator=(const Span & obj)
{
	if (this != &obj)
		_list = obj._list;
	return (*this);
}

const std::list<unsigned int> &Span::getList() const
{
	return _list;
}

void Span::addNumber(unsigned int num)
{
	if (_list.size() >= _capacity)
		throw std::overflow_error("Span is full");
	_list.push_back(num);
}

void Span::addNumber(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end)
{
	size_t rangeSize = std::distance(begin, end);
	if (_list.size() + rangeSize > _capacity)
		throw std::overflow_error("Adding this range would exceed Span capacity");
	_list.insert(_list.end(), begin, end);
}


unsigned int	Span::longestSpan()
{
	if (_list.size() < 2)
		throw std::length_error("Not enough numbers to find a span");

	unsigned int minNum = *std::min_element(_list.begin(), _list.end());
	unsigned int maxNum = *std::max_element(_list.begin(), _list.end());

	return (maxNum - minNum);
}

unsigned int	Span::shortestSpan()
{
	if (_list.size() < 2)
		throw std::length_error("Not enough numbers to find a span");

	std::list<unsigned int> sortedList = _list;
	sortedList.sort();

	unsigned int minSpan = UINT_MAX;
	std::list<unsigned int>::iterator prevIt = sortedList.begin();
	for (std::list<unsigned int>::iterator it = ++sortedList.begin(); it != sortedList.end(); ++it)
	{
		unsigned int span = *it - *prevIt;
		if (span < minSpan)
			minSpan = span;
		prevIt = it;
	}
	return minSpan;
}

std::ostream	&operator<<(std::ostream &out, const Span &obj)
{
	out << "Span with " << obj.getList().size() << " elements: ";
	std::list<unsigned int>::const_iterator it = obj.getList().begin();
	for (; it != obj.getList().end(); ++it)
	{
		out << *it;
		if (std::next(it) != obj.getList().end())
			out << ", ";
	}
	return out;
}

#endif
