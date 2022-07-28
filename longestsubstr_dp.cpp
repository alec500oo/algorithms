/* longestsubstr_dp.cpp */

#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <array>

using namespace std::literals;

constexpr auto str1 = "fishes"sv;
constexpr auto str2 = "hishes"sv;

int main(void)
{
	std::array<std::array<int, str2.length() + 1>, str1.length() + 1> grid;
	auto max = 0;
	auto max_i = 0;
	auto max_j = 0;

	for (int i = 1; i < grid.size(); ++i) {
		for (int j = 1; j < grid[0].size(); ++j) {
			if (str1[i - 1] == str2[j - 1])
				grid[i][j] = grid[i - 1][j - 1] + 1;

			if (max < grid[i][j]) {
				max_i = i;
				max_j = j;
				max = grid[i][j];
			}
		}
	}

	std::string substr;
	auto next = grid[max_i][max_j];

	while (next != 0) {
		substr = str1[max_i - 1] + substr;
		next = grid[--max_i][--max_j];
	}

	std::cout << "The longest substring is: " << substr << " (" << max << ")" << std::endl;

	for (int i = 0; i < grid.size(); ++i) {
		for (int j = 0; j < grid.size(); ++j) {
			std::cout << grid[i][j] << "\t";
		}
		std::cout << std::endl;
	}

		return 0;
}