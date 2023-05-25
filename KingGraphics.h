#ifndef KINGGRAPHICS_H
#define KINGGRAPHICS_H
#include "King.h"
#include "PieceGraphicsItem.h"

class KingGraphics : public PieceGraphicsItem
{
public:
    KingGraphics(QGraphicsItem *parent = nullptr, Piece *p = nullptr);
    ~KingGraphics();
    void setImage();
};

#endif // KINGGRAPHICS_H
