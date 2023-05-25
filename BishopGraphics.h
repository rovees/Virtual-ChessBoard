#ifndef BISHOPGRAPHICS_H
#define BISHOPGRAPHICS_H
#include "Bishop.h"
#include "PieceGraphicsItem.h"

class BishopGraphics : public PieceGraphicsItem
{
public:
    BishopGraphics(QGraphicsItem *parent = nullptr, Piece *p = nullptr);
    ~BishopGraphics();
    void setImage();
};

#endif // BISHOPGRAPHICS_H
