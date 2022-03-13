//
// Created by ali on 20.02.22.
//

#ifndef GOL_H
#define GOL_H

/**
 * @file gol.h
 * @author Ali Moameri (https://github.com/alimoammeri79)
 * @brief Game of life utilities
 * @date 2022-03-13
 */

#include <vector>
#include <cstddef>
#include <string>
#include <algorithm>
#include <cmath>
#include "array2d.h"

#define MSHRM '*'
#define DEAD '.'

/**
 * @brief A class for managing changes that should be done on the game table
 */
struct Update {
    char entity{};
    std::size_t row{};
    std::size_t column{};
};

/**
 * @brief Game of life class
 */
class Gol {
public:
    /** Constructor
     *   @param table game table
     *   @param level current level (how many evolves done on the table)
     */
    Gol(const Array2d<char>& table, std::size_t level);

    /** Return current game board
     *  @return current table state
     */
    Array2d<char> get_table() const;

    /** Find initial table state
     *  @return initial table
     */
    Array2d<char> solve();
private:
    Array2d<char> m_table;
    std::size_t m_level;

    /** Check whether a given block is mushroom or not
     * @param parameter a charcter representing a block in the game table
     * @return true if given block is mushroom, false otherwise
    */
    bool is_mushroom(const char& block) const;

    std::vector<Update> get_next_step_updates(Array2d<char>& table);

    /** Evolve table "level" times 
     * @param table game table
     * @param level how many evoluotions?
     * @return table after evolutions
    */
    Array2d<char> evolve(const Array2d<char>& table, const std::size_t& level);


    /** Count adjacent mushrooms of a given block
     * @param table game table
     * @param row block's row
     * @param row block's column
     * @return number of neighbor mushrooms
    */    
    std::size_t count_adjacent_mushrooms(const Array2d<char>& table, std::size_t row, std::size_t column) const;

    /** Update current table based on given changes
     * @param table current game table
     * @param updates changes that has to be done
    */ 
    void update_table(Array2d<char>& table, const std::vector<Update>& updates) const;

     /** Generate next table to check wheter it is the initial state of the current state 
     * @param table current checked table
     * @return next table that had to be checked
    */ 
    const Array2d<char> get_next_step(const Array2d<char> &table) const;
};

#endif //GOL_H
