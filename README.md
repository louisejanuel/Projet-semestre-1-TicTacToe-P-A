# Projet SEMESTRE 1 P&A - TicTacToe

*Louise Januel - E3IMAC*

Voici mon projet de fin de semestre où nous devions réaliser un jeu en C++ : le TicTacToe.

## Présentation globale

Je trvaille personnellement sur Windows et utilise GCC en tant que compilateur.
Pour l'ensemble des programmes (jeu de base + améliorations), ils sont au nomobre de deux (deux dossiers distincts) et s'exécutent de manière habituelle, sans particularité.

## Présentation des améliorations 

J'ai choisi de faire deux améliorations : 

### Amélioration n°1 : IA plus complexe

On utilise cette première amélioration lorsqu'on choisit l'IA avancé après avoir choisi le deuième mode de jeu TicTacToe.
J'ai codé cette IA de manière à ce qu'elle prenne en compte les symboles déjà placés sur le plateau. Elle contre les coups adverses ou complète ses propres lignes si deux symboles identiques sont déjà alignés. Pour cela, si l'adversaire ou l'IA elle-même a déjà aligné deux symboles, cette dernière va compléter la ligne. Si ce n'est pas le cas, elle va alors sélectionner aléatoirement une case vide pour jouer.

### Amélioration n°2 : Puissance 4

Le deuxième dossier contient un autre code à part entière : Puissance 4. Je me suis inspirée du code du TicTacToe pour le réaliser et ai suivi les règles bien connues du célèbre jeu de plateau.