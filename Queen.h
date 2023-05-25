#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"
#include "Game.h"



class Queen : public Piece
{
public:
    Queen(QString team); //, QGraphicsItem *parent = 0);
    ~Queen();

    // void setImage();
    void move();

};

#endif // QUEEN_H
