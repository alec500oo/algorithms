#include <iostream>
#include <vector>

static std::vector<int> list = {29, 42, 143, 100, 10, 83, 47};

/**
 * @brief Check if the collection is sorted in ascending order.
 *
 * @param c Collection ot check.
 * @return true if sorted.
 * @return false if not sorted.
 */
bool is_sorted(std::vector<int> const &c) {
	return std::is_sorted(c.begin(), c.end());
}

int take_smallest(std::vector<int> &c) {
	auto smallest = c[0];
	int smallest_index = 0;
	for (int i = 0; i < c.size(); ++i)
	{
		if (c[i] < smallest) {
			smallest_index = i;
			smallest = c[i];
		}
	}
	c.erase(c.begin() + smallest_index);
	return smallest;
}

/**
 * @brief Do a selection sort on the given collection.
 *
 * @param c Collection to sort
 * @return std::vector<int> with the newly sorted items.
 */
std::vector<int> selection_sort(std::vector<int> &c) {
	std::vector<int> out;
	for (int i = c.size(); i > 0; --i) {
		out.emplace_back(take_smallest(c));
	}
	return out;
}

int main(void) {
	auto sorted_list = selection_sort(list);

	std::cout << "Array Sorted? " << std::boolalpha
		<< is_sorted(sorted_list) << std::endl;

	std::cout << "Sorted list: ";
	for (auto i : sorted_list) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	return 0;
}