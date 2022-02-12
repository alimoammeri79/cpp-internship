/**
    This program tries to reverse "Conway's Game of Life" and guess it's initial state.
    Right now it uses brute force to acheive that.
**/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define MSHRM '*'
#define DEAD '.'
using namespace std;

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

bool is_mashroom(char block)
{
    return (block == MSHRM);
}

int count_adjacent_mashrooms(vector<string>& world, Coordinate coordinates)
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

void do_action(vector<string>& world, const vector<Action>& actions)
{
    for(const auto& action: actions)
    {
        int x{action.coordinate.x};
        int y{action.coordinate.y};
        world[x][y] = action.entity;
    }
}

bool game_of_life(vector<string>& world)
{
    vector<Action> actions;
    for(int i{0}; i < world.size(); ++i)
        for(int j{0}; j < world[i].length(); ++j)
        {
            int adjacent_mashrooms_count = count_adjacent_mashrooms(world, Coordinate{i, j});
            if(is_mashroom(world[i][j]))
            {
                if(!((adjacent_mashrooms_count == 3) || (adjacent_mashrooms_count == 2)))
                    actions.push_back({DEAD, Coordinate{i, j}});
            }
            else
            {
                if((adjacent_mashrooms_count == 3))
                    actions.push_back({MSHRM, Coordinate{i, j}});
            }
        }
    if(actions.size()) {
        do_action(world, actions);
        return true;
    }
    return false;
}

string to_binary(int a, int n)
{
    string result(n, DEAD);
    for(int i{result.length() - 1}; i >= 0 && a; --i) {
        result[i] = (a % 2) ?  MSHRM : DEAD;
        a /= 2;
    }
    return result;
}

size_t mushrooms_count(const vector<string>& world)
{
    size_t mushrooms{0};
    for(const auto& row: world)
        mushrooms+=count(row.cbegin(), row.cend(), MSHRM);

    return mushrooms;
}

/**


// I'm trying to keep track of states in order to avoid
// duplicate moves. But that dosn't work yet.

bool extract_state(const vector<string>& a)
{
    string state{""};
    for(const auto& row: a)
        state += to_string(stoi(row, nullptr, 2));
    if (find(states.begin(), states.end(), state) == states.end()) {
        states.push_back(state);
        return true;
    }
    return false;
}
**/

 vector<string> find_initial_step(vector<string>& world, const vector<string>& goal, int n, int m, int l, int current=0) {

    if(n == current)
    {
        vector<string> temp{world.begin(), world.end()};

        for(int i{0}; i < l; ++i) {
            if((mushrooms_count(temp) < 3) || !game_of_life(temp))
                return vector<string>{};
        }
        if(temp == goal)
            return world;

        return vector<string>{};
    }
    for(int k{0}; k < pow(2, m); ++k)
    {
        world[current] = to_binary(k, m);
        vector<string> result{find_initial_step(world, goal, n, m, l, current + 1)};
        if(result.size()){
            return result;
        }
	}
	return vector<string>{};
}

int main() {

    int n{}, m{}, l{};
    cin >> n >> m >> l;

    vector<string> world{n};
    vector<string> goal{n};
    for(auto& row: goal)
        cin >> row;

    vector<string> result{find_initial_step(world, goal, n, m, l)};
    if(result.size())
        for(const auto& row: result)
            cout << row << endl;
    else
        cout << "impossible" << endl;

	return 0;
}
