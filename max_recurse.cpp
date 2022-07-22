/* max_recurse.cpp */

#include <iostream>
#include <vector>

static std::vector<int> numbers = {0, 100, 256, 128, 64};

int max(std::vector<int> &slice) {
    if (slice.size() == 2)
        return slice[0] > slice[1] ? slice[0] : slice[1];

    auto last = slice.back();
    slice.pop_back();

    auto sub_max = max(slice);
    return last > sub_max ? last : sub_max;
}


int main(void) {
    std::cout << "The max in our array is: " << max(numbers) << std::endl;

    return 0;
}