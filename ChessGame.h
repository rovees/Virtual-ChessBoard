#ifndef CHESSGAME_H
#define CHESSGAME_H

#include "Structures.h"

// obiekt reprezentujący szachownicę od strony aktualnego stanu pozycji figur i pól
class ChessGame
{
    ChessGame();
    void makeMove(); // funkcja realizująca dany ruch na szachownicy, aktualizacja stanu szachownicy
    void run();
    ~ChessGame();
};

#endif // CHESSGAME_H
