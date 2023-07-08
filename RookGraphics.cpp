#include "RookGraphics.h"

RookGraphics::RookGraphics(QGraphicsItem *parent, Piece *p) : PieceGraphicsItem(parent, p)
{
    setImage();
}

RookGraphics::~RookGraphics()
{

}

void RookGraphics::setImage()
{
    if(chessPiece->getSide() == "WHITE")
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/white_rook.png"));
    else
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/black_rook.png"));
}
