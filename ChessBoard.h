#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <QGraphicsRectItem>
#include "Piece.h"

class ChessBoard
{
public:
    ChessBoard();
    ~ChessBoard();
    // narysowanie szachownicy
    void drawBoxes(int x, int y);

    // ustawienie białych i czarnych figur na szachownicy
    void setUpWhite();
    void setUpBlack();

    // metoda, która dodaje figurę na szachownicę
    void addChessPiece();
    // resetowanie szachownicy
    void reset();
private:
    // listy zawierające białe i czarne figury
    QList <Piece *> white;
    QList <Piece *> black;


};

#endif // CHESSBOARD_H
