//
// Created by ali on 20.02.22.
//

#ifndef GOL_H
#define GOL_H

#include <vector>
#include <cstddef>
#include <string>
#include <algorithm>
#include <cmath>
#include "Array_2D.h"

#define MSHRM '*'
#define DEAD '.'

struct Update
{
    char entity{};
    std::size_t row{};
    std::size_t column{};
};

// Game of life class
class Gol
{
public:
    Gol(const Array_2D<char>& table, std::size_t level);
    Array_2D<char> get_table() const;
    Array_2D<char> solve();
private:
    Array_2D<char> table;
    std::size_t level;
    bool is_mushroom(const char& block);
    Array_2D<char> evolve(const Array_2D<char>& table, const std::size_t& level);
    std::size_t count_adjacent_mushrooms(const Array_2D<char>& table, std::size_t row, std::size_t column);
    void update_table(Array_2D<char>& table, const std::vector<Update>& updates);
    const Array_2D<char> get_next_step(const Array_2D<char> &table);
};

#endif //reverseGOL_gol_H
