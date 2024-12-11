#include <iostream>
#include <cstdlib>
#include <array>
#include <ctime>
#include <thread>
#include <chrono>
#include "Player.hpp"
#include "GameBoard.hpp"

bool victoire(std::array<char, 9> board, char symbol)
{
    const std::array<std::array<char, 3>, 8> win_patterns = {std::array<char, 3>{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
    for (std::array<char, 3> pattern : win_patterns)
    {
        if (board[pattern[0]] == symbol && board[pattern[1]] == symbol && board[pattern[2]] == symbol)
        {
            return true;
        }
    }
    return false;
}

bool board_complete(std::array<char, 9> board)
{
    for (int i = 0; i < 9; ++i)
    {
        if (board[i] != 'X' && board[i] != 'O')
        {
            return false;
        }
    }
    return true;
}

void play_game(int choix)
{
    std::array<char, 9> board{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    Player player2;
    Player player1;

    if (choix == 1)
    {
        player1 = create_player1();
        player2 = create_player2();
        while (player1.symbol == player2.symbol)
        {
            std::cout << "Symbole deja choisi par " << player1.name << ". Choisissez un autre symbole : ";
            std::cin.clear();
            std::cin.ignore(255, '\n');
            std::cin >> player2.symbol;
        }
    }
    if (choix == 2)
    {
        int choix2;
        std::cout << "Veuillez choisir la complicité de l'IA :" << std::endl;
        std::cout << "1. Facile" << std::endl;
        std::cout << "2. Avance" << std::endl;
        std::cin >> choix2;

        if (choix2 == 1)
        {
            player1 = create_player();
            player2.name = "IA (facile)";
            player2.symbol = (player1.symbol == 'X') ? 'O' : 'X';
        }

        if (choix2 == 2)
        {
            player1 = create_player();
            player2.name = "IA (avance)";
            player2.symbol = (player1.symbol == 'X') ? 'O' : 'X';
        }
    }

    int turn = 0;
    bool game_over = false;
    std::cout << "Voici le plateau ! il faudra choisir un chiffre pour placer votre symbole a la place voulue ! " << std::endl;
    draw_game_board(board);
    board = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    while (!game_over)
    {
        Player current_player = (turn % 2 == 0) ? player1 : player2;
        int move{};
        std::cout << std::endl;
        draw_game_board(board);
        std::cout << std::endl;

        if (current_player.name == "IA (facile)")
        {
            std::cout << "Veuillez patienter.";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::cout << ".";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            std::cout << "." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            std::srand(std::time(nullptr));
            while (board[move] == player1.symbol || board[move] == player2.symbol)
                move = std::rand() % 9;
            board[move] = current_player.symbol;
        }

        else if (current_player.name == "IA (avance)")
        {
            std::cout << "Veuillez patienter.";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::cout << ".";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            std::cout << "." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));

            const std::array<std::array<char, 3>, 8> win_patterns = {std::array<char, 3>{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
            bool played = false;

            for (const std::array<char, 3> &pattern : win_patterns)
            {
                int count_player{0};
                int count_ia{0};
                int index{-1};

                for (int i : pattern)
                {
                    if (board[i] == player1.symbol)
                        count_player++;
                    else if (board[i] == player2.symbol)
                        count_ia++;
                    else
                        index = i;
                }

                if ((count_player == 2 || count_ia == 2) && index != -1)
                {
                    board[index] = current_player.symbol;
                    played = true;
                    break;
                }
            }

            if (!played)
            {
                std::srand(std::time(nullptr));
                while (board[move] == player1.symbol || board[move] == player2.symbol)
                    move = std::rand() % 9;
                board[move] = current_player.symbol;
            }
        }

        else
        {
            std::cout << current_player.name << ", choisissez une case : ";
            std::cin >> move;
            while (move != 1 && move != 2 && move != 3 && move != 4 && move != 5 && move != 6 && move != 7 && move != 8 && move != 9)
            {
                std::cout << "Entrez un chiffre entre 1 et 9 : ";
                std::cin.clear();
                std::cin.ignore(255, '\n');
                std::cin >> move;
            }
            while (board[move - 1] == player1.symbol || board[move - 1] == player2.symbol)
            {
                std::cout << "Case deja occupee, choisissez une autre case." << std::endl;
                std::cin.clear();
                std::cin.ignore(255, '\n');
                std::cin >> move;
            }
            move -= 1;
            board[move] = current_player.symbol;
        }

        {
            if (victoire(board, current_player.symbol))
            {
                std::cout << std::endl;
                draw_game_board(board);
                std::cout << std::endl;
                std::cout << current_player.name << " a gagne !" << std::endl;
                game_over = true;
            }
            else if (board_complete(board))
            {
                std::cout << std::endl;
                draw_game_board(board);
                std::cout << std::endl;
                std::cout << "Match nul !" << std::endl;
                game_over = true;
            }
            else
            {
                turn++;
            }
        }
    }
}

int main()
{
    int choix;

    std::cout << "Bienvenue dans le jeu du TicTacToe" << std::endl;
    std::cout << "Veuillez choisir un mode de jeu :" << std::endl;
    std::cout << "1. Deux joueurs" << std::endl;
    std::cout << "2. Un joueur contre l'IA" << std::endl;
    std::cin >> choix;
    play_game(choix);
}