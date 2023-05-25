#include "KingGraphics.h"


KingGraphics::KingGraphics(QGraphicsItem *parent, Piece *p) : PieceGraphicsItem(parent)
{
    chessPiece = p;
    setImage();
}

KingGraphics::~KingGraphics()
{

}

void KingGraphics::setImage()
{
    if(chessPiece->getSide() == "WHITE")
        setPixmap(QPixmap("C:/Users/Radek/Documents/SZASZKI/white_king.png"));
    else
        setPixmap(QPixmap("C:/Users/Radek/Documents/SZASZKI/black_king.png"));
}
