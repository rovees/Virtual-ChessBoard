#include "KnightGraphics.h"

KnightGraphics::KnightGraphics(QGraphicsItem *parent, Piece *p) : PieceGraphicsItem(parent, p)
{
    setImage();
}

KnightGraphics::~KnightGraphics()
{

}

void KnightGraphics::setImage()
{
    if(chessPiece->getSide() == "WHITE")
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/white_knight.png"));

    else
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/black_knight.png"));
}
