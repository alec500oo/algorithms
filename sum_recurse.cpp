/* sum_recurse.cpp */
#include <iostream>
#include <vector>

static std::vector<int> numbers = {1, 2, 3, 4, 5};

int sum(std::vector<int> &slice) {
    if (slice.size() == 0) {
        return 0;
    }
    auto last = slice.back();
    slice.pop_back();
    return last + sum(slice);
}


int main(void) {
    std::cout << "The sum of our array is: " << sum(numbers) << std::endl;

    return 0;
}