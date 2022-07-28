/* knapsack_dp.cpp */

#include <map>
#include <string_view>
#include <iostream>

struct item_details {
    std::string_view name;
    int weight;
    int value;
};

constexpr std::array to_steal = {
    item_details{"gutar", 1, 1500},
    item_details{"stereo", 4, 3000},
    item_details{"laptop", 3, 2000},
    item_details{"iphone", 1, 2000},
    item_details{"mp3", 1, 1000},
};

constexpr auto max_weight = 4;

int main(void)
{
    int cells[to_steal.size() + 1][max_weight + 1] = {0};

    for (int i = 1; i < to_steal.size() + 1; ++i) {
        for (int j = 1; j < max_weight + 1; ++j) {
            auto value = to_steal[i - 1].value;
            auto weight = to_steal[i - 1].weight;

            if (j - weight < 0)
                cells[i][j] = cells[i - 1][j];
            else
                cells[i][j] = std::max(cells[i - 1][j], value + cells[i - 1][j - weight]);
        }
    }

    for (int i = 0; i < to_steal.size() + 1; ++i) {
        for (int j = 0; j < max_weight + 1; ++j) {
            std::cout << cells[i][j] << "\t";
        }
        std::cout << std::endl;
	}

    auto jdx = max_weight;
    std::string stolen_goods;
    for (int idx = to_steal.size(); idx > 0; --idx) {
        if (cells[idx][jdx] > cells[idx - 1][jdx]) {
            stolen_goods += to_steal[idx - 1].name;
            stolen_goods.append(" ");
            jdx -= to_steal[idx - 1].weight;
        }
    }

    std::cout << "We stole: " << stolen_goods << std::endl;

    return 0;
}