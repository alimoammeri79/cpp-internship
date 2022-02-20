/**
    This program tries to reverse "Conway's Game of Life" and guess it's initial state.
    Right now it uses brute force to achieve that.
**/

#include <iostream>
#include "GOL.h"

int main() {

    std::size_t n{}, m{}, l{};
    std::cin >> n >> m >> l;

    std::vector<std::string> world{n};
    std::vector<std::string> goal{n};
    for(auto& row: goal)
        std::cin >> row;

    std::vector<std::string> result{find_initial_step(world, goal, n, m, l)};
    if(!result.empty())
        for(const auto& row: result)
            std::cout << row << "\n";
    else
        std::cout << "impossible" << "\n";

    return 0;
}
