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

std::vector<int> quicksort(std::vector<int> &li) {
    std::vector<int> out;
    std::vector<int> less;
    std::vector<int> greater;

    if (li.size() < 2)
        return li;

    auto pivot = li.back();
    li.pop_back();

    for (auto &i : li) {
        if (i <= pivot) {
            less.emplace_back(i);
        } else {
            greater.emplace_back(i);
        }
    }

    auto less_sort = quicksort(less);
    auto greater_sort = quicksort(greater);

    out.insert(out.end(), less_sort.begin(), less_sort.end());
    out.emplace_back(pivot);
    out.insert(out.end(), greater_sort.begin(), greater_sort.end());

    return out;
}

int main(void) {
	auto sorted_list = quicksort(list);

	std::cout << "Array Sorted? " << std::boolalpha
		<< is_sorted(sorted_list) << std::endl;

	std::cout << "Sorted list: ";
	for (auto i : sorted_list) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	return 0;
}