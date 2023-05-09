#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
#include "Game.h"


class Bishop : public Piece
{
public:

    Bishop(QString team, QGraphicsItem *parent = 0);
    ~Bishop();
    void setImage();
    void move();

};


#endif // BISHOP_H
