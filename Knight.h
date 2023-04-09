#ifndef KNIGHT_H
#define KNIGHT_H

#include "Structures.h"
#include "Piece.h"

class Knight : public Piece
{
public:
    Knight(PieceType t, Color c);
    virtual PieceType getType(PieceType type);
    virtual void move(Position from, Position to);
    virtual Position getPosition();
    virtual Color getColor();
    virtual bool isMoveValid();
    ~Knight();
};

#endif // KNIGHT_H
