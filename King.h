#ifndef KING_H
#define KING_H

#include "Structures.h"
#include "Piece.h"

class King : public Piece
{
public:
    King(PieceType t, Color c);
    virtual PieceType getType(PieceType type);
    virtual void move(Position from, Position to);
    virtual Position getPosition();
    virtual Color getColor();
    virtual bool isMoveValid();
    ~King();
};

#endif // KING_H
