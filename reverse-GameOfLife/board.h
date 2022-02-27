//
// Created by alimoammeri on 2/27/22.
//

#ifndef BOARD_H
#define BOARD_H

#include <cstddef>
#include <vector>
#include <string>

class Board {
public:
    // Default constructor
    Board();
    Board(const std::vector<char>& table, std::size_t hight, std::size_t width);
    Board(std::size_t hight, std::size_t width, const char& fill);
    // Copy constructor
    Board(const Board& board);
    const std::size_t& get_hight() const;
    const std::size_t& get_width() const;

    const char& get_block(std::size_t i, std::size_t j) const;
    void set_block(std::size_t i, std::size_t j, const char& ch);

    const std::string to_string() const;
    const bool is_empty() const;

    Board& operator= (const Board& fraction);
    bool operator== (const Board& board) const ;

private:
    std::size_t hight = 0;
    std::size_t width = 0;
    std::vector<char> table{};
};


#endif //BOARD_H
