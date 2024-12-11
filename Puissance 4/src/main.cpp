#include <iostream>
#include <vector>
#include <string>
#include "Player.hpp"
#include "GameBoard.hpp"

const int rows{6};
const int columns{7};

bool drop_symbol(std::vector<std::vector<char>> &board, int col, char token) // pour mettre un jeton sur le plateau
{
    if (col < 0 || col >= columns)
    {
        return false; // colonne invalide
    }
    for (int row = rows - 1; row >= 0; --row)
    {
        if (board[row][col] == ' ')
        {
            board[row][col] = token;
            return true;
        }
    }
    return false; // colonne pleine
}


bool victoire(const std::vector<std::vector<char>> &board, char token) //pour vérifier si un joueur a gagné
{
    for (int row = 0; row < rows; ++row) //les lignes
        for (int col = 0; col <= columns - 4; ++col)
            if (board[row][col] == token && board[row][col + 1] == token && board[row][col + 2] == token && board[row][col + 3] == token)
                return true;

    for (int col = 0; col < columns; ++col) //les colonnes
        for (int row = 0; row <= rows - 4; ++row)
            if (board[row][col] == token && board[row + 1][col] == token && board[row + 2][col] == token && board[row + 3][col] == token)
                return true;

    for (int row = 3; row < rows; ++row) //les diagonales montantes
        for (int col = 0; col <= columns - 4; ++col)
            if (board[row][col] == token && board[row - 1][col + 1] == token && board[row - 2][col + 2] == token && board[row - 3][col + 3] == token)
                return true;

    for (int row = 0; row <= rows - 4; ++row) //les diagonales descendantes
        for (int col = 0; col <= columns - 4; ++col)
            if (board[row][col] == token && board[row + 1][col + 1] == token && board[row + 2][col + 2] == token && board[row + 3][col + 3] == token)
                return true;
    return false;
}

void play_game()
{  
    std::vector<std::vector<char>> board(rows, std::vector<char>(columns, ' '));
    Player player2;
    Player player1;
    player1 = create_player1();
    std::cout << std::endl;
    player2 = create_player2();

    while (player1.symbol == player2.symbol)
    {
        std::cout << "Symbole deja choisi par " << player1.name << ". Choisissez un autre symbole : ";
        std::cin.clear();
        std::cin.ignore(255, '\n');
        std::cin >> player2.symbol;
    }

    bool game_over = false;
    int turn = 0;

    while (!game_over)
    {
        std::cout << std::endl;
        draw_game_board(board);
        std::cout << std::endl;

        std::string current_player {(turn % 2 == 0) ? player1.name : player2.name};
        char current_symbol = (turn % 2 == 0) ? player1.symbol : player2.symbol;

        std::cout << current_player << " (" << current_symbol << "), choisissez une colonne (1-" << columns << ") : ";
        int col;
        std::cin >> col;
        while (!drop_symbol(board, col - 1, current_symbol))
        {
            std::cout << "Colonne invalide ou pleine. Choisissez une autre colonne : ";
            std::cin.clear();
            std::cin.ignore(255, '\n');
            std::cin >> col;
        }


        if (victoire(board, current_symbol))
        {
            draw_game_board(board);
            std::cout << std::endl;
            std::cout << current_player << " a gagne !" << std::endl;
            game_over = true;
        }
        else if (turn == rows * columns - 1)
        {
            draw_game_board(board);
            std::cout << std::endl;
            std::cout << "Match nul ! Le plateau est plein." << std::endl;
            game_over = true;
        }
        else
        {
            turn++;
        }
    }
}

int main()
{
    std::cout << "Bienvenue dans le jeu de Puissance 4 !" << std::endl;
    std::cout << std::endl;
    play_game();
}
