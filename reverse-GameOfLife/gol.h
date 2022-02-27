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
#include "board.h"

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
    Gol(const Board& board, std::size_t level);
    const std::string get_board() const;
    const Board solve();
private:
    Board board;
    std::size_t level;
    bool is_mushroom(const char& block);
    const Board evolve(const Board& board, const std::size_t level);
    std::size_t count_adjacent_mushrooms(const Board& board, std::size_t row, std::size_t column);
    void update_table(Board& board, const std::vector<Update>& updates);
    const Board get_next_step(const Board &board);
};

#endif //reverseGOL_gol_H
