#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include "Game.h"



class Pawn:public Piece
{
public:
    Pawn(QString team,QGraphicsItem *parent = 0);
    ~Pawn();

    void setImage();
    void move();

};

#endif // PAWN_H
