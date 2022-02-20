/**
    This program tries to reverse "Conway's Game of Life" and guess it's initial state.
    Right now it uses brute force to achieve that.
**/

#include <iostream>
#include "GOL.h"

int main() {

    std::size_t hight{}, width{}, level{};
    std::cin >> hight >> width >> level;

    std::vector<char> table(hight*width);
    std::vector<char> final_table(hight*width);
    for(auto& row: final_table)
        std::cin >> row;

    std::vector<char> result{get_initial_table(table, final_table, hight, width, level)};
    if(!result.empty())
        for (size_t i{0}; i < table.size(); i++)
        {
            std::cout << table[i];
            if (i % width == width - 1)
                std::cout << '\n';
        }
    else
        std::cout << "impossible" << "\n";

    return 0;
}
