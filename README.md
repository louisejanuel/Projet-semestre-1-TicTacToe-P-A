- [Projet SEMESTRE 1 P\&A - TicTacToe](#projet-semestre-1-pa---tictactoe)
  - [Présentation globale](#présentation-globale)
  - [Présentation des améliorations](#présentation-des-améliorations)
    - [Amélioration n°1 : IA plus complexe](#amélioration-n1--ia-plus-complexe)
    - [Amélioration n°2 : Puissance 4](#amélioration-n2--puissance-4)
  - [Compte rendu](#compte-rendu)
  - [Conclusion](#conclusion)


# Projet SEMESTRE 1 P&A - TicTacToe

*Louise Januel - E3IMAC*

Voici mon projet de fin de semestre où nous devions réaliser un jeu en C++ : le TicTacToe.

## Présentation globale

Je travaille sur Windows et utilise GCC en tant que compilateur.
Pour l'ensemble des programmes (jeu de base + améliorations), ils sont au nomobre de deux (deux dossiers distincts) et s'exécutent de manière habituelle, sans particularité.

## Présentation des améliorations 

J'ai choisi de faire deux améliorations : 

### Amélioration n°1 : IA plus complexe

On utilise cette première amélioration lorsqu'on choisit l'IA avancé après avoir choisi le deuième mode de jeu TicTacToe.
J'ai codé cette IA de manière à ce qu'elle prenne en compte les symboles déjà placés sur le plateau. Elle contre les coups adverses ou complète ses propres lignes si deux symboles identiques sont déjà alignés. Pour cela, si l'adversaire ou l'IA elle-même a déjà aligné deux symboles, cette dernière va compléter la ligne. Si ce n'est pas le cas, elle va alors sélectionner aléatoirement une case vide pour jouer.

### Amélioration n°2 : Puissance 4

Le deuxième dossier contient un autre code à part entière : Puissance 4. Je me suis inspirée du code du TicTacToe pour le réaliser et ai suivi les règles bien connues du célèbre jeu de plateau.


## Compte rendu

**TicTacToe**
J'ai commencé par coder le jeu de base *TicTacToe*. Après avoir créé les fichiers **Player** et **GameBoard**, comme demandé dans la consigne, j'ai commencé à écrire le programme global. Pour organiser le tout, j'ai décidé de créer trois fonctions principales : `play_game`, `victoire` et `board_complete`.

- La fonction la plus générale, `play_game`, sert à lancer une partie en fonction du mode de jeu choisi par le joueur, puis à gérer le déroulement des tours.  
- J'ai rencontré des difficultés pour trouver comment faire en sorte que la partie se termine. Finalement, j'ai utilisé un booléen `game_over`, initialisé à `false`, qui passe à `true` lorsque la partie se termine. J'ai encapsulé toute la logique des tours dans une boucle `while` contrôlée par ce booléen. Cette boucle inclut aussi un test pour vérifier si la partie est finie.

Pour que la partie soit considérée comme terminée, deux cas sont possibles :
1. Un des deux joueurs a gagné.
2. Le plateau est entièrement rempli.

Pour gérer ces deux cas, j'ai créé deux fonctions séparées, `victoire` et `board_complete`, qui retournent des booléens :
- La fonction `board_complete` a été assez simple à coder avec une boucle qui vérifie les cases du plateau.
- La fonction `victoire`, en revanche, a été plus difficile à concevoir. J'ai eu du mal à trouver une solution pour vérifier toutes les combinaisons gagnantes. Finalement, j'ai eu l'idée d'utiliser des tableaux de tableaux. J'ai listé tous les patterns possibles de victoire et j'ai fait une boucle pour vérifier si l'un des deux joueurs remplissait l'un de ces patterns.

Ces deux fonctions retournent `true` en cas de fin de partie, ce qui permet de sortir de la boucle `while` dans `play_game`.

Pour ce qui est des améliorations :
- J'ai ajouté un petit temps d'attente pour le tour de l'IA, ce qui rend le jeu plus réaliste et plaisant.
- J'ai aussi ajouté des boucles `while` pour gérer les erreurs de saisie des joueurs (par exemple, si le joueur entre un numéro qui ne correspond à aucune case ou une case déjà prise). Ces boucles permettent de vider et réinitialiser les entrées pour que le joueur puisse corriger et continuer à jouer sans problème.

**Puissance 4**
Pour le *Puissance 4*, j'ai repris la même base que pour le *TicTacToe* : une fonction principale, des fonctions pour vérifier la fin de la partie, et une boucle `while` qui tourne tant que la partie n'est pas terminée.

J'ai ajouté une fonction `drop_symbol`, qui :
- Place un symbole dans une colonne choisie par le joueur.
- Retourne `false` si la saisie est invalide (colonne inexistante ou pleine). Dans ce cas, le joueur doit refaire son choix.

De plus, j'ai fixé les dimensions du plateau à 7 colonnes et 6 rangées, comme dans le jeu physique. Pour vérifier les victoires, j'ai adapté le code pour tester les alignements horizontaux, verticaux et diagonaux spécifiques à ce jeu.

## Conclusion

Ce projet m'a permis de bien m'entraîner avec le C++ et de mieux comprendre comment organiser un programme, gérer les erreurs et structurer la logique des jeux.