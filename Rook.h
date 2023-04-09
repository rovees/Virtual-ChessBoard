#ifndef ROOK_H
#define ROOK_H

#include "Structures.h"
#include "Piece.h"

class Rook : public Piece
{
public:
    Rook(PieceType t, Color c);
    virtual PieceType getType(PieceType type);
    virtual void move(Position from, Position to);
    virtual Position getPosition();
    virtual Color getColor();
    virtual bool isMoveValid();
    ~Rook();
};

#endif // ROOK_H
