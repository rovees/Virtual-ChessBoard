#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight:public Piece
{
public:
    Knight(QString team, QGraphicsItem *parent = 0);
    ~Knight();

    void setImage();
    void move();

};

#endif // KNIGHT_H
