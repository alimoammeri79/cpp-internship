//
// Created by ali on 20.02.22.
//

#include "GOL.h"

bool is_mushroom(char block)
{
    return (block == MSHRM);
}

int count_adjacent_mushrooms(std::vector<std::string>& table, Coordinate coordinates)
{
    int count{0};
    int row{coordinates.x};
    int column{coordinates.y};
    size_t width{table[row].length()};
    size_t height{table.size()};

    for(int i{row - 1}; i <= row + 1; ++i)
        for(int j{column - 1}; j <= column + 1; ++j)
            if(i == row && j == column)
                continue;
            else
            if(table[(i + height) % height][(j + width) % width] == MSHRM)
                ++count;

    return count;
}

void do_action(std::vector<std::string>& table, const std::vector<Action>& actions)
{
    for(const auto& action: actions)
    {
        int x{action.coordinate.x};
        int y{action.coordinate.y};
        table[x][y] = action.entity;
    }
}

bool evolve(std::vector<std::string>& table)
{
    std::vector<Action> actions;
    for(int i{0}; i < table.size(); ++i)
        for(int j{0}; j < table[i].length(); ++j)
        {
            int adjacent_mushrooms_count = count_adjacent_mushrooms(table, Coordinate{i, j});
            if(is_mushroom(table[i][j]))
            {
                if(!((adjacent_mushrooms_count == 3) || (adjacent_mushrooms_count == 2)))
                    actions.push_back({DEAD, Coordinate{i, j}});
            }
            else
            {
                if(adjacent_mushrooms_count == 3)
                    actions.push_back({MSHRM, Coordinate{i, j}});
            }
        }
    if(!actions.empty()) {
        do_action(table, actions);
        return true;
    }
    return false;
}

std::string to_binary(size_t number, size_t length)
{
    std::string result(length, DEAD);
    for(std::size_t i{result.length()}; i-- && number;) {
        result[i] = (number % 2) ?  MSHRM : DEAD;
        number /= 2;
    }
    return result;
}

size_t count_mushrooms(const std::vector<std::string>& table)
{
    size_t mushrooms{0};
    for(const auto& row: table)
        mushrooms+=std::count(row.cbegin(), row.cend(), MSHRM);

    return mushrooms;
}

std::vector<std::string> find_initial_step(std::vector<std::string>& table, const std::vector<std::string>& final_table,
                                           std::size_t n, std::size_t m, std::size_t l, std::size_t current) {

    if(n == current)
    {
        std::vector<std::string> temp{table.begin(), table.end()};

        for(int i{0}; i < l; ++i) {
            if((count_mushrooms(temp) < 3) || !evolve(temp))
                return std::vector<std::string>{};
        }
        if(temp == final_table)
            return table;

        return std::vector<std::string>{};
    }
    for(std::size_t k{0}; k < pow(2, double(m)); ++k)
    {
        table[current] = to_binary(k, m);
        std::vector<std::string> result{find_initial_step(table, final_table, n, m, l, current + 1)};
        if(!result.empty()){
            return result;
        }
    }
    return std::vector<std::string>{};
}

/**
I'm trying to keep track of states in order to avoid
duplicate moves. But that doesn't work yet.
bool extract_state(const std::vector<std::string>& a)
{
    std::string state{""};
    for(const auto& row: a)
        state += to_std::string(stoi(row, nullptr, 2));
    if (find(states.begin(), states.end(), state) == states.end()) {
        states.push_back(state);
        return true;
    }
    return false;
}
**/