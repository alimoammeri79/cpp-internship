/**
    This program tries to reverse "Conway's Game of Life" and guess it's initial state.
    Right now it uses brute force to achieve that.
**/

#include <iostream>
#include <cstddef>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
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

bool is_mushroom(char block)
{
    return (block == MSHRM);
}

int count_adjacent_mushrooms(std::vector<std::string>& world, Coordinate coordinates)
{
    int count{0};
    int row{coordinates.x};
    int column{coordinates.y};
    size_t width{world[row].length()};
    size_t height{world.size()};

    for(int i{row - 1}; i <= row + 1; ++i)
        for(int j{column - 1}; j <= column + 1; ++j)
            if(i == row && j == column)
                continue;
            else
            if(world[(i + height) % height][(j + width) % width] == MSHRM)
                ++count;

    return count;
}

void do_action(std::vector<std::string>& world, const std::vector<Action>& actions)
{
    for(const auto& action: actions)
    {
        int x{action.coordinate.x};
        int y{action.coordinate.y};
        world[x][y] = action.entity;
    }
}

bool game_of_life(std::vector<std::string>& world)
{
    std::vector<Action> actions;
    for(int i{0}; i < world.size(); ++i)
        for(int j{0}; j < world[i].length(); ++j)
        {
            int adjacent_mushrooms_count = count_adjacent_mushrooms(world, Coordinate{i, j});
            if(is_mushroom(world[i][j]))
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
        do_action(world, actions);
        return true;
    }
    return false;
}

std::string to_binary(size_t a, size_t n)
{
    std::string result(n, DEAD);
    for(std::size_t i{result.length()}; i-- && a;) {
        result[i] = (a % 2) ?  MSHRM : DEAD;
        a /= 2;
    }
    return result;
}

size_t mushrooms_count(const std::vector<std::string>& world)
{
    size_t mushrooms{0};
    for(const auto& row: world)
        mushrooms+=count(row.cbegin(), row.cend(), MSHRM);

    return mushrooms;
}

/**


// I'm trying to keep track of states in order to avoid
// duplicate moves. But that doesn't work yet.

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

std::vector<std::string> find_initial_step(std::vector<std::string>& world, const std::vector<std::string>& goal,
                                           std::size_t n, std::size_t m, std::size_t l, std::size_t current=0) {

    if(n == current)
    {
        std::vector<std::string> temp{world.begin(), world.end()};

        for(int i{0}; i < l; ++i) {
            if((mushrooms_count(temp) < 3) || !game_of_life(temp))
                return std::vector<std::string>{};
        }
        if(temp == goal)
            return world;

        return std::vector<std::string>{};
    }
    for(std::size_t k{0}; k < pow(2, double(m)); ++k)
    {
        world[current] = to_binary(k, m);
        std::vector<std::string> result{find_initial_step(world, goal, n, m, l, current + 1)};
        if(!result.empty()){
            return result;
        }
    }
    return std::vector<std::string>{};
}

int main() {

    std::size_t n{}, m{}, l{};
    std::cin >> n >> m >> l;

    std::vector<std::string> world{n};
    std::vector<std::string> goal{n};
    for(auto& row: goal)
        std::cin >> row;

    std::vector<std::string> result{find_initial_step(world, goal, n, m, l)};
    if(!result.empty())
        for(const auto& row: result)
            std::cout << row << "\n";
    else
        std::cout << "impossible" << "\n";

    return 0;
}
