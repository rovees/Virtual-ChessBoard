#ifndef PAWNGRAPHICS_H
#define PAWNGRAPHICS_H

#include "Pawn.h"
#include "PieceGraphicsItem.h"

class PawnGraphics : public PieceGraphicsItem
{
public:
    PawnGraphics(QGraphicsItem *parent = nullptr, Piece *p = nullptr);
    ~PawnGraphics();
    void setImage();
};

#endif // PAWNGRAPHICS_H
