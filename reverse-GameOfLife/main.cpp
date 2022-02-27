/**
    This program tries to reverse "Conway's Game of Life" and guess it's initial state.
    Right now it uses brute force to achieve that.
**/

#include <iostream>
#include <exception>
#include "board.h"
#include "gol.h"

int main() {

    std::size_t hight{}, width{}, level{};
    std::cin >> hight >> width >> level;
    if(!std::cin)
        // Catching some exceptions
        throw std::runtime_error("You should enter numbers only");

    std::vector<char> table(hight*width);
    // Getting input table
    for(auto& row: table)
        std::cin >> row;

    Board board{table, hight, width};

    Gol gol{board, level};
    const Board result{gol.solve()};
    if(result.is_empty())
        std::cout << "impossible" << "\n";
    else
        std::cout << result.to_string();

    return 0;
}
