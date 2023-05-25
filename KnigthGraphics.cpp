#include "KnightGraphics.h"

KnightGraphics::KnightGraphics(QGraphicsItem *parent, Piece *p) : PieceGraphicsItem(parent)
{
    chessPiece = p;
    setImage();
}

KnightGraphics::~KnightGraphics()
{

}

void KnightGraphics::setImage()
{
    if(chessPiece->getSide() == "WHITE")
        setPixmap(QPixmap("C:/Users/Radek/Documents/SZASZKI/white_knight.png"));

    else
        setPixmap(QPixmap("C:/Users/Radek/Documents/SZASZKI/black_knight.png"));
}
