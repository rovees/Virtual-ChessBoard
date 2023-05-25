#ifndef PIECEGRAPHICSITEM_H
#define PIECEGRAPHICSITEM_H

#include <QGraphicsPixmapItem>
#include "ChessSquare.h"
#include <QGraphicsSceneMouseEvent>
#include "ChessSquareGraphicsItem.h"

class ChessSquareGraphicsItem;
class PieceGraphicsItem;

// #include "Piece.h"

class PieceGraphicsItem : public QGraphicsPixmapItem
{
public:
    PieceGraphicsItem(QGraphicsItem *parent = nullptr, Piece *p = nullptr);
    ~PieceGraphicsItem();
    virtual void setImage() = 0;
    // metoda, która resetuje kolory odpowiednich pól (dotyczy to sytuacji gdy klikamy na daną figurę i podświetlane są wszystkie pola na szachownicy,
    // w które możemy się przesunąć), w momencie kiedy odklikniemy wybraną figurę lub wykonamy ruch to zostaną przywrócone oryginalne kolory pól, do
    //    których można było się przesunąć
    void decolor();
    // void mousePressEvent(QGraphicsSceneMouseEvent *event, Piece *piece);
    //metoda ustawiająca odpowiedni kolor pola (w zależności czy jest to pole, na którym znajduje się figura,
    // którą możemy zbić lub jest puste pole
    // bool boxSetting(ChessSquare *box);
    Piece *getChessPiece();
    void setChessPiece(Piece *p);
protected:
    Piece *chessPiece;
};

#endif // PIECEGRAPHICSITEM_H
