/* count_recurse.cpp */

#include <iostream>
#include <vector>

static std::vector<int> numbers = {1, 2, 3, 4, 5};

int count(std::vector<int> &slice) {
    if (slice.size() == 0)
        return 0;

    slice.pop_back();
    return 1 + count(slice);
}


int main(void) {
    std::cout << "The count of our array is: " << count(numbers) << std::endl;

    return 0;
}