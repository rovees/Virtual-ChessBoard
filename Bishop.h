#ifndef BISHOP_H
#define BISHOP_H

#include "Structures.h"
#include "Piece.h"
// XDDDDDDDDDDDDDDDDDDDDDDDDDDD
class Bishop : public Piece
{
public:
    Bishop(PieceType t, Color c);
    virtual PieceType getType(PieceType type);
    virtual void move(Position from, Position to);
    virtual Position getPosition();
    virtual Color getColor();
    virtual bool isMoveValid();
    ~Bishop();
};

#endif // BISHOP_H
