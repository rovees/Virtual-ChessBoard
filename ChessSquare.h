#ifndef CHESSSQUARE_H
#define CHESSSQUARE_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>

class Piece;

class ChessSquare : public QGraphicsRectItem
{
public:

    // Konstruktor i destruktor
    ChessSquare(QGraphicsItem *parent = 0);
    ~ChessSquare();

    // publiczne metody

    int rowPos;
    int colPos;
    Piece *currentPiece;

};

#endif // CHESSSQUARE_H
