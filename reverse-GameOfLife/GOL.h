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
int count_adjacent_mushrooms(std::vector<std::string>& table, Coordinate coordinates);
void do_action(std::vector<std::string>& table, const std::vector<Action>& actions);
bool evolve(std::vector<std::string>& table);
std::string to_binary(size_t number, size_t length);
size_t count_mushrooms(const std::vector<std::string>& table);
std::vector<std::string> find_initial_step(std::vector<std::string>& table, const std::vector<std::string>& final_table,
                                           std::size_t n, std::size_t m, std::size_t l, std::size_t current=0);

/**
    I'm trying to keep track of states in order to avoid
    duplicate moves. But that doesn't work yet.
bool extract_state(const std::vector<std::string>& a);
**/

#endif //reverseGOL_GOL_H
