#include "gtest/gtest.h"
#include <cstddef>
#include "array2d.h"

// The fixture for testing class Foo.
class Array2dTest : public ::testing::Test {
 protected:
  Array2dTest() {}
  void SetUp() override {
     // Code here will be called immediately after the constructor (right
     // before each test).
     m_width = 3;
     m_hight = 3;
     m_board = {m_hight, m_width, {1, 2, 3, 4, 5, 6, 7, 8, 9}};
     m_board_2 = {m_board};
     m_board_3 = {m_hight, m_width, {1, 2, 3, 4, 5, 6, 0, 8, 9}};
     m_empty_board = {};
  }
  std::size_t m_width;
  std::size_t m_hight;
  Array2d<int> m_board;
  Array2d<int> m_board_2;
  Array2d<int> m_board_3;
  Array2d<int> m_empty_board;
};

TEST_F(Array2dTest, GettersTest) {
    EXPECT_EQ(m_width, m_board.width());
    EXPECT_EQ(m_hight, m_board.hight());
}

TEST_F(Array2dTest, IsEmptyTest) {
    EXPECT_EQ(false, m_board.is_empty());
    EXPECT_EQ(true, m_empty_board.is_empty());
}

TEST_F(Array2dTest, EqualityTest) {
    EXPECT_EQ(true, m_board == m_board_2);
}

TEST_F(Array2dTest, AccessWithIndexTest) {
        
    EXPECT_EQ(1, m_board[0][0]);
    EXPECT_EQ(4, m_board[1][0]);
    EXPECT_EQ(5, m_board[1][1]);
    
    m_board[1][1] = 9;
    EXPECT_EQ(9, m_board[1][1]);
}