/**
    This program tries to reverse "Conway's Game of Life" and guess it's initial state.
    Right now it uses brute force to achieve that.
**/

#include <iostream>
#include "array2d.h"
#include "gol.h"

int main() {

    std::size_t hight{}, width{}, level{};
    std::cin >> hight >> width >> level;
    if(!std::cin)
        throw std::runtime_error("You should enter numbers only");

    Array2d<char> table{hight, width, '.'};
    // Getting input table
    for(std::size_t i{0}; i < hight; ++i)
        for(std::size_t j{0}; j < width; ++j)
            std::cin >> table[i][j];


    Gol gol{table, level};
    const Array2d<char> result{gol.solve()};
    if(result.is_empty())
        std::cout << "impossible" << "\n";
    else
        std::cout << result << std::endl;

    return 0;
}
