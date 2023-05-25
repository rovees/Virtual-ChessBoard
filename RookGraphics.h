#ifndef ROOKGRAPHICS_H
#define ROOKGRAPHICS_H
#include "Rook.h"
#include "PieceGraphicsItem.h"

class RookGraphics : public PieceGraphicsItem
{
public:
    RookGraphics(QGraphicsItem *parent = nullptr, Piece *p = nullptr);
    ~RookGraphics();
    void setImage();
};

#endif // ROOKGRAPHICS_H
