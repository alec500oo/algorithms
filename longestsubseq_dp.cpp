/* longestsubseq_dp.cpp */

#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <array>

using namespace std::literals;

constexpr std::string_view str1 = "fish";
constexpr std::string_view str2 = "fosh";

int main(void)
{
	std::array<std::array<int, str2.length() + 1>, str1.length() + 1> grid;
	auto max = 0;

	for (int i = 1; i < grid.size(); ++i) {
		for (int j = 1; j < grid[0].size(); ++j) {
			if (str1[i - 1] == str2[j - 1])
				grid[i][j] = grid[i - 1][j - 1] + 1;
			else
				grid[i][j] = std::max(grid[i - 1][j], grid[i][j - 1]);

			max = std::max(max, grid[i][j]);
		}
	}

	std::cout << "The max subsequence is: " << max << std::endl;

	for (int i = 0; i < grid.size(); ++i) {
		for (int j = 0; j < grid.size(); ++j) {
			std::cout << grid[i][j] << "\t";
		}
		std::cout << std::endl;
	}

		return 0;
}