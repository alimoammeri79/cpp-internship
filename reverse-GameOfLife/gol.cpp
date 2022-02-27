    //
    // Created by ali on 20.02.22.
    //

    #include "GOL.h"

    bool is_mushroom(char block)
    {
        return (block == MSHRM);
    }

    int count_adjacent_mushrooms(std::vector<char>& table, size_t hight, size_t width, Coordinate coordinates)
    {
        int count{0};
        int row{coordinates.x};
        int column{coordinates.y};

        for(int i{row - 1}; i <= row + 1; ++i)
            for(int j{column - 1}; j <= column + 1; ++j)
                if(i == row && j == column)
                    continue;
                else {
                    size_t index{((i + hight) % hight) * width + ((j + width) % width)};
                    if (table[index] == MSHRM)
                        ++count;
                }
        return count;
    }

    void do_action(std::vector<char>& table, size_t hight, size_t width, const std::vector<Action>& actions)
    {
        for(const auto& action: actions)
        {
            int x{action.coordinate.x};
            int y{action.coordinate.y};
            table[x * width + y] = action.entity;
        }
    }

    bool evolve(std::vector<char>& table, size_t hight, size_t width)
    {
        std::vector<Action> actions;
        for(int i{0}; i < hight; ++i)
            for(int j{0}; j < width; ++j)
            {
                int adjacent_mushrooms_count = count_adjacent_mushrooms(table, hight, width, Coordinate{i, j});
                if(is_mushroom(table[i*width+j]))
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
            do_action(table, hight, width, actions);
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

    size_t count_mushrooms(const std::vector<char>& table)
    {
        size_t mushrooms{0};
        mushrooms+=std::count(table.cbegin(), table.cend(), MSHRM);
        return mushrooms;
    }

    std::vector<char> get_initial_table(std::vector<char>& table, const std::vector<char>& final_table,
                                               std::size_t hight, std::size_t width, std::size_t level, std::size_t current) {

        if(current == hight)
        {
            std::vector<char> temp{table.begin(), table.end()};

            for(int i{0}; i < level; ++i) {
                if((count_mushrooms(temp) < 3) || !evolve(temp, hight, width))
                    return std::vector<char>{};
            }
            if(temp == final_table)
                return table;

            return std::vector<char>{};
        }
        for(std::size_t k{0}; k < pow(2, double(width)); ++k)
        {
            std::string row{to_binary(k, width)};
            for(size_t i{0}; i < row.length(); ++i)
                table[current*width+i] = row[i];
            std::vector<char> result{get_initial_table(table, final_table, hight, width, level, current + 1)};
            if(!result.empty()){
                return result;
            }
        }
        return std::vector<char>{};
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