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
#include "Array2d.h"

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
    Gol(const Array2d<char>& table, std::size_t level);
    Array2d<char> get_table() const;
    Array2d<char> solve() const;
private:
    Array2d<char> m_table;
    std::size_t m_level;
    bool is_mushroom(const char& block) const;
    Array2d<char> evolve(const Array2d<char>& table, const std::size_t& level) const;
    std::size_t count_adjacent_mushrooms(const Array2d<char>& table, std::size_t row, std::size_t column) const;
    void update_table(Array2d<char>& table, const std::vector<Update>& updates) const;
    const Array2d<char> get_next_step(const Array2d<char> &table) const;
};

#endif //reverseGOL_gol_H
