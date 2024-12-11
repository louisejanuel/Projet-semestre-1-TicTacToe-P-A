#include "GameBoard.hpp"
#include <iostream>
#include <vector>

const int rows {6};
const int columns {7};

void draw_game_board(const std::vector<std::vector<char>>& board) {
    for (int row = 0; row < rows; ++row) {
        std::cout << "|";
        for (int col = 0; col < columns; ++col) {
            std::cout << board[row][col] << "|";
        }
        std::cout << std::endl;
    }
    std::cout << " ";
    for (int col = 1; col <= columns; ++col) {
        std::cout << col << " ";
    }
    std::cout << std::endl;
}