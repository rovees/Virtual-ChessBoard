#include "PawnGraphics.h"

PawnGraphics::PawnGraphics(QGraphicsItem *parent, Piece *p) : PieceGraphicsItem(parent)
{
    chessPiece = p;
    setImage();
}

PawnGraphics::~PawnGraphics()
{

}

void PawnGraphics::setImage()
{
    if(chessPiece->getSide() == "WHITE")
        setPixmap(QPixmap("C:/Users/Radek/Documents/SZASZKI/white_pawn.png"));
    else
        setPixmap(QPixmap("C:/Users/Radek/Documents/SZASZKI/black_pawn.png"));
}
