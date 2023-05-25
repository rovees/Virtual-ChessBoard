#include "RookGraphics.h"

RookGraphics::RookGraphics(QGraphicsItem *parent, Piece *p) : PieceGraphicsItem(parent)
{
    chessPiece = p;
    setImage();
}

RookGraphics::~RookGraphics()
{

}

void RookGraphics::setImage()
{
    if(chessPiece->getSide() == "WHITE")
        setPixmap(QPixmap("C:/Users/Radek/Documents/SZASZKI/white_rook.png"));
    else
        setPixmap(QPixmap("C:/Users/Radek/Documents/SZASZKI/black_rook.png"));
}
