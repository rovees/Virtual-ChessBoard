#ifndef PIECE_H
#define PIECE_H

#include "Structures.h"

class Piece
{

protected:
    PieceType type;
    Color color;
    Position position;

public:
    Piece(PieceType t, Color c);
    virtual PieceType getType(PieceType type) = 0;
    virtual void move(Position from, Position to) = 0; // funkcja zlecająca ruch daną figurą
    virtual Position getPosition() = 0;
    virtual Color getColor() = 0;
    virtual bool isMoveValid() = 0;
};

#endif // PIECE_H
