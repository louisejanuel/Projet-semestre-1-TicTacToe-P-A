#include "Player.hpp"
#include <iostream>

Player create_player() {
    Player player;

    std::cout << "Entrez le nom du joueur : ";
    std::cin >> player.name;

    std::cout << "Choisissez un symbole (X ou O) : ";
    std::cin >> player.symbol;

    return player;
}


Player create_player1() {
    Player player;

    std::cout << "Entrez le nom du premier joueur : ";
    std::cin >> player.name;

    std::cout << "Choisissez un symbole (X ou O) : ";
    std::cin >> player.symbol;

    return player;
}

Player create_player2() {
    Player player;

    std::cout << "Entrez le nom du deuxieme joueur : ";
    std::cin >> player.name;

    std::cout << "Choisissez un symbole (X ou O) : ";
    std::cin >> player.symbol;

    return player;
}