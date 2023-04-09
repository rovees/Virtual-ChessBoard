#ifndef PAWN_H
#define PAWN_H

#include "Structures.h"
#include "Piece.h"

class Pawn : public Piece
{
public:
    Pawn(PieceType t, Color c);
    virtual PieceType getType(PieceType type);
    virtual void move(Position from, Position to);
    virtual Position getPosition();
    virtual Color getColor();
    virtual bool isMoveValid();
    /*
    bool czyRuchJestLegalny(int x1, int y1, int x2, int y2, Piece* pionki[8][8]); // sprawdza, czy ruch figury jest zgodny z zasadami szachów
    bool czyPoleMoznaZajac(int x, int y, Piece* pionki[8][8]); // sprawdza, czy pole na szachownicy jest wolne i można je zająć przez figurę
    */
    ~Pawn();
};

#endif // PAWN_H
