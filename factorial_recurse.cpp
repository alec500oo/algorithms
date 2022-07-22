/* factorial_recurse.cpp */

#include <iostream>

/**
 * @brief Use simple recursion to calculate a factorial
 *
 * @param n number to calculate
 * @return int answer: n!
 */
int factorial(int n) {
    if (n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main(void) {
    std::cout << "The factorial of 5 is: " << factorial(5) << std::endl;

    return 0;
}