#include "GameBoard.hpp"
#include <iostream>

void draw_game_board(const std::array<char, 9> board) {
    std::cout << "| " << board[0] << " | " << board[1] << " | " << board[2] << " |" << std::endl;
    std::cout << "| " << board[3] << " | " << board[4] << " | " << board[5] << " |" << std::endl;
    std::cout << "| " << board[6] << " | " << board[7] << " | " << board[8] << " |" << std::endl;
}
