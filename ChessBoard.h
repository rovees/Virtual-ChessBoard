#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "Structures.h"
#include "Piece.h"

class ChessBoard
{
    vector <vector <Piece>> *board; // reprezentacja szachownicy w postaci tablicy dwuwymiarowej
    Color turn;

public:
    ChessBoard();
    void getPiece();
    Color getTurn(Color turn);
    Position getToPos(); // pobierz pozycję, do której chcemy przesunąć figurę
    // void setTurn();
    bool makeMove(bool moveValid); // zwraca true jeżeli ruch został wykonany, w przeciwnym wypadku zwraca false
    bool isFieldEmpty(Position pos); // funkcja sprawdzająca czy pole na szachownicy jest puste
    void getBoard(vector <vector<string>> board); // uaktualnianie stanu szachownicy w trakcie partii
    ~ChessBoard();
};

#endif // CHESSBOARD_H
