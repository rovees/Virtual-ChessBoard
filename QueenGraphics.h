#ifndef QUEENGRAPHICS_H
#define QUEENGRAPHICS_H
#include "Queen.h"
#include "PieceGraphicsItem.h"

class QueenGraphics : public PieceGraphicsItem
{
public:
    QueenGraphics(QGraphicsItem *parent = nullptr, Piece *p = nullptr);
    ~QueenGraphics();
    void setImage();
};

#endif // QUEENGRAPHICS_H
