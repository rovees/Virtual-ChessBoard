#include "PieceGraphicsItem.h"
#include "Piece.h"

PieceGraphicsItem::PieceGraphicsItem(QGraphicsItem *parent, Piece *p) : QGraphicsPixmapItem(parent)
{

}

PieceGraphicsItem::~PieceGraphicsItem()
{

}

void PieceGraphicsItem::decolor()
{
    for(size_t i = 0, n = chessPiece->moveLocation().size(); i < n;i++) {
        chessPiece->moveLocation()[i]->getBoxGraphics()->resetOriginalColor();
    }
}

