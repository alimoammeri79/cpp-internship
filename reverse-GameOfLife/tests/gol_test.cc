#include "gtest/gtest.h"
#include "gol.h"

TEST(GolBoard, GetEmptyBoard) {
    constexpr std::size_t hight{3};
    constexpr std::size_t width{3};
    constexpr std::size_t level{10};

    const std::vector<char> input {
        '*','*','*',
        '*','*','*',
        '*','.','.'
        };

    const Array_2D<char> board {hight, width, input};
    Gol gol {board, level};
    const Array_2D<char> result { gol.solve() };

    EXPECT_EQ(1, result.is_empty());
}

TEST(GolBoard, GetInitialBoard) {
    constexpr std::size_t hight{4};
    constexpr std::size_t width{5};
    constexpr std::size_t level{10};

    const std::vector<char> input {
        '.','.','.','.','*',
        '.','.','*','.','*',
        '.','*','.','.','*',
        '.','.','*','.','*'
        };
    const std::vector<char> output {
         '.','.','*','.','*',
         '.','.','.','*','*',
         '*','*','.','*','*',
         '*','.','.','.','.'
        };

    const Array_2D<char> input_board {hight, width, input};
    const Array_2D<char> output_board {hight, width, output};

    Gol gol {input_board, level};

    EXPECT_EQ(output_board, gol.solve());
}