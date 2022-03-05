    //
    // Created by alimoammeri on 20.02.22.
    //

#include "gol.h"

Gol::Gol(const Array_2D<char>& table, std::size_t level) : m_table{table}, m_level{level} {}
Array_2D<char> Gol::get_table() const
{
    return m_table;
}

bool Gol::is_mushroom(const char& block)
{
    return (block == MSHRM);
}

void Gol::update_table(Array_2D<char>& table, const std::vector<Update>& updates)
{
    for(const auto& update: updates) {
        std::size_t row{update.row};
        std::size_t column{update.column};
        table[row][column] = update.entity;
    }
}

/*
 *  table: table that we wonna count it's block's adjacent mushroms
 *  row: position of the block's row in the table
 *  column: position of the block's column in the table
 */
std::size_t Gol::count_adjacent_mushrooms(const Array_2D<char>& table, std::size_t row, std::size_t column)
{
    std::size_t count{0};
    const std::size_t hight{table.hight()};
    const std::size_t width{table.width()};

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
                if (table[new_i][new_j] == MSHRM)
                    ++count;
            }
        }
    }
    return count;
}

Array_2D<char> Gol::evolve(const Array_2D<char>& table, const std::size_t& level)
{
    std::vector<Update> updates;
    Array_2D<char> temp{table};
    const std::size_t hight{m_table.hight()};
    const std::size_t width{m_table.width()};

    for(std::size_t step{0}; step < level; ++step) {
        for (std::size_t i{0}; i < hight; ++i) {
            for (std::size_t j{0}; j < width; ++j) {
                const std::size_t adjacent_mushrooms_count =
                        count_adjacent_mushrooms(temp, i, j);
                if (is_mushroom(temp[i][j])) {
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

// Try to reverse current table state to reach the initial state of table
Array_2D<char> Gol::solve()
{
    Array_2D<char> temp{m_table.hight(), m_table.width(), DEAD};
    const std::size_t steps = pow(2, m_table.hight() * m_table.width());
    for (std::size_t step{0}; step < steps; ++step) {
        const Array_2D<char> new_table = evolve(temp, m_level);
        if (m_table == new_table)
            return temp;
        temp = get_next_step(temp);
    }
    return Array_2D<char>{};
 }

 const Array_2D<char> Gol::get_next_step(const Array_2D<char> &table)
 {
    Array_2D<char> temp{table};
    if(temp[0][0] == DEAD) {
        temp[0][0] = MSHRM;
        return temp;
    }
    for(std::size_t i{0}; i < temp.hight(); ++i) {
        for(std::size_t j{0}; j < table.width(); ++j) {
            if(temp[i][j] == MSHRM) {
                temp[i][j] = DEAD;
                continue;
            }
            else {
                temp[i][j] = DEAD;
                return temp;
            }
        }
    }
 }
