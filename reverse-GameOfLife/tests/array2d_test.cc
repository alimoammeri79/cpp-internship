#include "gtest/gtest.h"
#include <cstddef>
#include "array2d.h"

TEST(Array2dTest, GettersTest) {
    constexpr std::size_t width {3};
    constexpr std::size_t hight {3};

    const Array2d<int> my_board {hight, width, {1, 2, 3, 4, 5, 6, 7, 8, 9}};
    
    EXPECT_EQ(width, my_board.width());
    EXPECT_EQ(hight, my_board.hight());
}

TEST(Array2dTest, IsEmptyTest) {
    constexpr std::size_t width {1};
    constexpr std::size_t hight {1};

    const Array2d<int> my_board {hight, width, {1}};
    const Array2d<int> my_empty_board;
    
    EXPECT_EQ(0, my_board.is_empty());
    EXPECT_EQ(1, my_empty_board.is_empty());
}

TEST(Array2dTest, EqualityTest) {
    constexpr std::size_t width {2};
    constexpr std::size_t hight {2};

    const Array2d<int> my_board {hight, width, {1, 2, 6, 8}};
    const Array2d<int> my_second_board {my_board};
    const Array2d<int> my_third_board {hight, width, {1, 2, 6, 8}};
    const Array2d<int> my_forth_board {hight, width, {1, 2, 0, 8}};
    
    EXPECT_EQ(1, my_board == my_second_board);
    EXPECT_EQ(1, my_board == my_third_board);
    EXPECT_EQ(0, my_board == my_forth_board);
}

TEST(Array2dTest, AccessWithIndexTest) {
    constexpr std::size_t width {2};
    constexpr std::size_t hight {2};

    Array2d<int> my_board {hight, width, {1, 2, 6, 8}};
    
    EXPECT_EQ(1, my_board[0][0]);
    EXPECT_EQ(6, my_board[1][0]);
    EXPECT_EQ(8, my_board[1][1]);
    
    my_board[1][1] = 9;
    EXPECT_EQ(9, my_board[1][1]);
}