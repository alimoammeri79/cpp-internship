//
// Created by ali on 20.02.22.
//

#ifndef reverseGOL_GOL_H
#define reverseGOL_GOL_H

#include <vector>
#include <cstddef>
#include <string>
#include <algorithm>
#include <cmath>

#define MSHRM '*'
#define DEAD '.'

struct Coordinate
{
    int x{0};
    int y{0};
};

struct Action
{
    char entity{};
    Coordinate coordinate{};
};

bool is_mushroom(char block);
int count_adjacent_mushrooms(std::vector<char>& table, size_t hight, size_t width, Coordinate coordinates);
void do_action(std::vector<char>& table, size_t hight, size_t width, const std::vector<Action>& actions);
bool evolve(std::vector<char>& table, size_t hight, size_t width);
std::string to_binary(size_t number, size_t length);
size_t count_mushrooms(const std::vector<char>& table, size_t hight, size_t width);
std::vector<char> get_initial_table(std::vector<char>& table, const std::vector<char>& final_table,
                                           std::size_t n, std::size_t m, std::size_t l, std::size_t current=0);

/**
    I'm trying to keep track of states in order to avoid
    duplicate moves. But that doesn't work yet.
bool extract_state(const std::vector<char>& a);
**/

#endif //reverseGOL_GOL_H
