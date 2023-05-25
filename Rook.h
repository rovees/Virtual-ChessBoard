#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece
{
public:
    Rook(QString team); //, QGraphicsItem *parent = 0);
    ~Rook();

    // void setImage();
    void move();

};

#endif // ROOK_H
