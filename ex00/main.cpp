
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <stack>
#include <queue>

#include <iostream>
#include "easyfind.hpp"

template < typename T >
class Wrapper : public T
{
	public:
		typedef typename T::container_type::iterator iterator;
		typedef typename T::container_type::const_iterator const_iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }

		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const { return this->c.end(); }
};

int main()
{
	int values []= { 10, 20, 30, 42, 50 };
	int size = sizeof(values) / sizeof(values[0]);

	try
	{
		if ((int)*easyfind(std::set<int>(values, values + size), 42) != 42)
			std::cout << "failed to find 42" << std::endl;
		else std::cout << "found " << (int)*easyfind(std::set<int>(values, values + size), 42) << " in set" << std::endl;

		if ((int)*easyfind(std::multiset<int>(values, values + size), 42) != 42)
			std::cout << "failed to find 42" << std::endl;
		else std::cout << "found " << (int)*easyfind(std::multiset<int>(values, values + size), 42) << " in multiset" << std::endl;

		if ((int)*easyfind(std::vector<int>(values, values + size), 42) != 42)
			std::cout << "failed to find 24" << std::endl;
		else std::cout << "found " << (int)*easyfind(std::vector<int>(values, values + size), 42) << " in vector" << std::endl;

		if ((int)*easyfind(std::list<int>(values, values + size), 42) != 42)
			std::cout << "failed to find 42" << std::endl;
		else std::cout << "found " << (int)*easyfind(std::list<int>(values, values + size), 42) << " in list" << std::endl;

		if ((int)*easyfind(std::deque<int>(values, values + size), 42) != 42)
			std::cout << "failed to find 42" << std::endl;
		else std::cout << "found " << (int)*easyfind(std::deque<int>(values, values + size), 42) << " in deque" << std::endl;

		std::stack<int> stack;
		std::queue<int> queue;
		for (int i = 0; i < size; ++i)
		{
			stack.push(values[i]);
			queue.push(values[i]);
		}

		Wrapper< std::stack<int> >& wrappedStack = static_cast< Wrapper< std::stack<int> >& >(stack);
		Wrapper< std::queue<int> >& wrappedQueue = static_cast< Wrapper< std::queue<int> >& >(queue);

		if (*easyfind(wrappedStack, 42) != 42)
			std::cout << "failed to find 42" << std::endl;
		else 
			std::cout << "found 42 in stack" << std::endl;
		
		if (*easyfind(wrappedQueue, 42) != 42)
			std::cout << "failed to find 42" << std::endl;
		else 
			std::cout << "found 42 in queue" << std::endl;

		std::cout << "all success" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Unexpected Exception thrown: " << e.what() << std::endl;
	}
}