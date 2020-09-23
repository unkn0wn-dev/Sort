#include <algorithm> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <iterator>
 
int main()
{
	int array[]{ 30, 50, 20, 10, 40 };
	constexpr int length{ static_cast<int>(std::size(array)) };

	for (int firstIndex{ 0 }; firstIndex < length - 1; ++firstIndex)
	{
		int smallestIndex{ firstIndex };
 
		// Then look for a smaller element in the rest of the array
		for (int currentIndex{ firstIndex + 1 }; currentIndex < length; ++currentIndex)
		{
			// If we've found an element that is smaller than our previously found smallest
			if (array[currentIndex] < array[smallestIndex])
				// then keep track of it
				smallestIndex = currentIndex;
		}
 
		std::swap(array[firstIndex], array[smallestIndex]);
	}

	for (int index{ 0 }; index < length; ++index)
		std::cout << array[index] << ' ';
 
	std::cout << '\n';
 
	return 0;
}