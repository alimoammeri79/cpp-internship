//
// Created by ali on 2/27/22.
//

#include "board.h"

// Default contructor
Board::Board()
    : hight{0}, width{0} {};

/*
    table: A array of character, representing game board
    hight: table's hight
    width: table's width
 */
Board::Board(const std::vector<char>& table, std::size_t hight, std::size_t width)
    : table{table}, hight{hight}, width{width} {}

/*
    hight: table's hight
    width: table's width
    fill: charcter that we wonna fill table with
 */
Board::Board(std::size_t hight, std::size_t width, const char& fill):
    hight{hight}, width{width}, table(hight * width, fill) {}

Board::Board(const Board& board)
    : table{board.table}, hight{board.hight}, width{board.width} {}

const std::size_t& Board::get_hight() const { return this->hight; }
const std::size_t& Board::get_width() const { return this->width; }

// Consider table as a 2D array and Return element in  ith row and jth coloumn in the 2D table
const char& Board::get_block(std::size_t i, std::size_t j) const
{
    return this->table[(i * this->width) + j];
}

void Board::set_block(std::size_t i, std::size_t j, const char& ch)
{
    this->table[(i * this->width) + j] = ch;
}

const std::string Board::to_string() const
{
    std::string output{};
    for(std::size_t i{0}; i < hight; ++i)
    {
        for (std::size_t j{0}; j < width; ++j)
            output += this->get_block(i, j);
        output += '\n';
    }
    return output;
}

const bool Board::is_empty() const
{
    return !(this->hight || this->width);
}

Board& Board::operator= (const Board& board){
    this->hight = board.hight;
    this->width = board.width;
    for(auto& element: board.table)
        this->table.push_back(element);
    return *this;
}

bool Board::operator== (const Board& board) const {
    for(std::size_t i{0}; i < board.hight; ++i)
        for(std::size_t j{0}; j < board.width; ++j)
            if(this->get_block(i, j) != board.get_block(i, j))
                return false;
    return true;
}