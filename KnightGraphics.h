#ifndef KNIGHTGRAPHICS_H
#define KNIGHTGRAPHICS_H
#include "Knight.h"
#include "PieceGraphicsItem.h"


class KnightGraphics : public PieceGraphicsItem
{
public:
    KnightGraphics(QGraphicsItem *parent = nullptr, Piece *p = nullptr);
    ~KnightGraphics();
    void setImage();
};

#endif // KNIGHTGRAPHICS_H
