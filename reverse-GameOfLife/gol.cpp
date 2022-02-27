    //
    // Created by alimoammeri on 20.02.22.
    //

#include "gol.h"

Gol::Gol(const Board& board, std::size_t level) : board{board}, level{level} {}
const std::string Gol::get_board() const
{
    return this->board.to_string();
}

bool Gol::is_mushroom(const char& block)
{
    return (block == MSHRM);
}

void Gol::update_table(Board& board, const std::vector<Update>& updates)
{
    for(const auto& update: updates) {
        std::size_t row{update.row};
        std::size_t column{update.column};
        board.set_block(row, column, update.entity);
    }
}

/*
 *  board: board that we wonna count it's block's adjacent mushroms
 *  row: position of the block's row in the board
 *  column: position of the block's column in the board
 */
std::size_t Gol::count_adjacent_mushrooms(const Board& board, std::size_t row, std::size_t column)
{
    std::size_t count{0};
    const std::size_t hight{board.get_hight()};
    const std::size_t width{board.get_width()};

    // Cast row and column to int, in order to dosn't break when minuses by one
    int int_row{static_cast<int>(row)};
    int int_column{static_cast<int>(column)};

    for(int i{int_row - 1}; i <= int_row + 1; ++i) {
        for (int j{int_column - 1}; j <= int_column + 1; ++j) {
            if (i == int_row && j == int_column)
                continue;
            else {
                std::size_t new_i = (i + hight) % hight;
                std::size_t new_j = (j + width) % width;
                if (board.get_block(new_i, new_j) == MSHRM)
                    ++count;
            }
        }
    }
    return count;
}

const Board Gol::evolve(const Board& board, const std::size_t level)
{
    std::vector<Update> updates;
    Board temp{board};
    const std::size_t hight{this->board.get_hight()};
    const std::size_t width{this->board.get_width()};

    for(std::size_t step{0}; step < level; ++step) {
        for (std::size_t i{0}; i < hight; ++i) {
            for (std::size_t j{0}; j < width; ++j) {
                const std::size_t adjacent_mushrooms_count =
                        count_adjacent_mushrooms(temp, i, j);
                if (is_mushroom(temp.get_block(i, j))) {
                    if (!((adjacent_mushrooms_count == 3) || (adjacent_mushrooms_count == 2)))
                        updates.push_back({DEAD, i, j});
                } else {
                    if (adjacent_mushrooms_count == 3)
                        updates.push_back({MSHRM, i, j});
                }
            }
        }
        if(updates.empty())
            break;
        else
            update_table(temp, updates);
    }
    return temp;
}

// Try to reverse current board state to reach the initial state of board
const Board Gol::solve()
{
    Board temp{this->board.get_hight(), this->board.get_width(), DEAD};
    const std::size_t steps = pow(2, this->board.get_hight() * this->board.get_width());
    for (std::size_t step{0}; step < steps; ++step) {
        const Board new_board = this->evolve(temp, this->level);
        if (this->board == new_board)
            return temp;
        temp = get_next_step(temp);
    }
    return Board{};
 }

 const Board Gol::get_next_step(const Board &board)
 {
    Board temp{board};
    if(temp.get_block(0, 0) == DEAD) {
        temp.set_block(0, 0, MSHRM);
        return temp;
    }
    for(std::size_t i{0}; i < temp.get_hight(); ++i) {
        for(std::size_t j{0}; j < board.get_width(); ++j) {
            if(temp.get_block(i, j) == MSHRM) {
                temp.set_block(i, j, DEAD);
                continue;
            }
            else {
                temp.set_block(i, j, DEAD);
                return temp;
            }
        }
    }
 }
