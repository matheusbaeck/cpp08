#include "Span.hpp"
#include <iostream>
#ifdef TIME_MODE
#include <ctime>
#include <chrono>
#endif

#ifndef RANGE
# define RANGE 10
#endif

#ifndef MAX
# define MAX 10
#endif

std::vector<unsigned int> generateRandomVector(unsigned int size)
{
	std::vector<unsigned int> v;
	v.reserve(size);
	for (unsigned int i = 0; i < size; ++i) {
		v.push_back(rand() % MAX); 
	}
	return v;
}

int main() {

	std::cout << "----------------------------------------" << std::endl;
	// Test adding number beyond capacity
	try {
		Span sp = Span(3);

		sp.addNumber(10);
		sp.addNumber(20);
		sp.addNumber(30);
		// This should throw an exception
		sp.addNumber(40);
		std::cout << "FAILURE" << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "SUCCESS -- Expected Error: " << e.what() << std::endl;
	}

	std::cout << "----------------------------------------" << std::endl;
	// Test adding range beyond capacity
	try {
		Span sp = Span(3);
		std::vector<unsigned int> nums = {1, 2, 3, 4};
		// This should throw an exception
		sp.addNumber(nums.begin(), nums.end());
		std::cout << "FAILURE" << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "SUCCESS -- Expected Error: " << e.what() << std::endl;
	}

	std::cout << "----------------------------------------" << std::endl;
	// Test with insufficient numbers for longestSpan
	try {
		Span sp = Span(1);

		// This should throw an exception
		std::cout << sp.longestSpan() << "FAILURE" << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "SUCCESS -- Expected Error: " << e.what() << std::endl;
	}

	std::cout << "----------------------------------------" << std::endl;
	// Test with insufficient numbers for shortestSpan
	try {
		Span sp = Span(2);

		sp.addNumber(5);
		// This should throw an exception
		std::cout << sp.shortestSpan() << "FAILURE" << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "SUCCESS -- Expected Error: " << e.what() << std::endl;
	}

	std::cout << "----------------------------------------" << std::endl;
	// Basic functionality test
	try {
		Span sp = Span(5);

		sp.addNumber(3);
		sp.addNumber(6);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(17);

		std::cout << "Longest Span: " << sp.longestSpan() << " correct is " << 17 - 3 << std::endl;
		std::cout << "Shortest Span: " << sp.shortestSpan() << " correct is " << 11 - 9 << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;
	// Large scale test
	srand(time(NULL));
	try {
		unsigned int limit = RANGE;
		Span sp(limit);

		std::vector<unsigned int> randomData = generateRandomVector(limit);

		#ifdef TIME_MODE
		auto start = std::chrono::high_resolution_clock::now();
		#endif
		std::cout << "Adding " << limit << " random numbers to Span..." << std::endl;
		sp.addNumber(randomData.begin(), randomData.end());
		#ifdef TIME_MODE
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> duration = end - start;
		std::cout << " (Added in " << duration.count() << "ms)" << std::endl;
		#endif



		#ifdef TIME_MODE
		start = std::chrono::high_resolution_clock::now();
		#endif
		unsigned int shortest = sp.shortestSpan();
		#ifdef TIME_MODE
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		#endif

		std::cout << "Shortest Span: " << shortest << std::endl;
		#ifdef TIME_MODE
		std::cout << " (Found in " << duration.count() << "ms)" << std::endl;
		#endif

		#ifdef TIME_MODE
		start = std::chrono::high_resolution_clock::now();
		#endif
		unsigned int longest = sp.longestSpan();
		#ifdef TIME_MODE
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		#endif

		std::cout << "Longest Span: " << longest << std::endl;
		#ifdef TIME_MODE
		std::cout << " (Found in " << duration.count() << "ms)" << std::endl;
		#endif

		std::cout << "----------------------------------------" << std::endl;
		std::cout << "All operations completed successfully." << std::endl;
		std::cout << sp << std::endl;
		
		
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}