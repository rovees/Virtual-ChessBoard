#ifndef QUEEN_H
#define QUEEN_H

#include "Structures.h"
#include "Piece.h"

class Queen : public Piece
{
public:
    Queen(PieceType t, Color c);
    virtual PieceType getType(PieceType type);
    virtual void move(Position from, Position to);
    virtual Position getPosition();
    virtual Color getColor();
    virtual bool isMoveValid();
    ~Queen();
};

#endif // QUEEN_H
