#ifndef KING_H
#define KING_H

#include "Piece.h"
#include "Game.h"


class King:public Piece
{
public:
    King(QString team,QGraphicsItem *parent = 0);
    ~King();

    void setImage();
    void findUnSafeLocation();
    void move();

};

#endif // KING_H
