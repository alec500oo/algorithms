/* binarysearch.cpp */

#include <iostream>
#include <vector>

static std::vector items = 
	{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15, 16, 17, 18, 19, 20, 21};
/**
 * @brief Using binary search, find the given item in a collection.
 * 
 * @param items List of items to search for the given item.
 * @param item Iteam to search for
 * @return true if items found
 */
bool binarysearch(std::vector<int> const &items, int item) {
	int low = 0;
	int high = items.size() - 1;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (items[mid] == item) {
			return true;
		} else if (items[mid] < item) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return false;
}

int main(void) {

	std::cout << "Found 3: " << binarysearch(items, 3) << std::endl;
	std::cout << "Found 13: " << binarysearch(items, 13) << std::endl;
	std::cout << "Found 21: " << binarysearch(items, 21) << std::endl;

	return 0;
}