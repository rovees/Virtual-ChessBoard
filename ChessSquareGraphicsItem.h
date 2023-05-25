#ifndef CHESSSQUAREGRAPHICSITEM_H
#define CHESSSQUAREGRAPHICSITEM_H
// #include "Piece.h"
#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include "ChessSquare.h"

class Piece;
class ChessSquare;

class ChessSquareGraphicsItem : public QGraphicsRectItem
{
public:
    ChessSquareGraphicsItem(QGraphicsItem *parent = nullptr, ChessSquare *cS = nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setColor(QColor color);
    QColor getColor();
    void setOriginalColor(QColor value);
    // void setBoxGraphics(QGraphicsItem *boxG);
    void resetOriginalColor();
    ChessSquare *getCurrSquare();
    void setCurrSquare(ChessSquare *currChessSquare);
    // Piece *getCurrPiece();
    // void setCurrPiece(Piece *currP);

private:
    ChessSquare *currSquare;
    // Piece *currPiece;
    QBrush brush;
    QColor originalColor; // oryginalny kolor pola szachowego
};


#endif // CHESSSQUAREGRAPHICSITEM_H
