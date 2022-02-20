/**
    This program tries to reverse "Conway's Game of Life" and guess it's initial state.
    Right now it uses brute force to achieve that.
**/

#include <iostream>
#include "GOL.h"

int main() {

    std::size_t n{}, m{}, l{};
    std::cin >> n >> m >> l;

    std::vector<std::string> table{n};
    std::vector<std::string> final_table{n};
    for(auto& row: final_table)
        std::cin >> row;

    std::vector<std::string> result{find_initial_step(table, final_table, n, m, l)};
    if(!result.empty())
        for(const auto& row: result)
            std::cout << row << "\n";
    else
        std::cout << "impossible" << "\n";

    return 0;
}
