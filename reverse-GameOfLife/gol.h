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

// Game of life class interface
class Gol
{
public:
    Gol(const Array_2D<char>& table, std::size_t level);
    Array_2D<char> get_table() const;
    Array_2D<char> solve() const;
private:
    Array_2D<char> m_table;
    std::size_t m_level;
    bool is_mushroom(const char& block) const;
    Array_2D<char> evolve(const Array_2D<char>& table, const std::size_t& level) const;
    std::size_t count_adjacent_mushrooms(const Array_2D<char>& table, std::size_t row, std::size_t column) const;
    void update_table(Array_2D<char>& table, const std::vector<Update>& updates) const;
    const Array_2D<char> get_next_step(const Array_2D<char> &table) const;
};

#endif //reverseGOL_gol_H
