#include "PawnGraphics.h"

PawnGraphics::PawnGraphics(QGraphicsItem *parent, Piece *p) : PieceGraphicsItem(parent, p)
{
    setImage();
}

PawnGraphics::~PawnGraphics()
{

}

void PawnGraphics::setImage()
{
    if(chessPiece->getSide() == "WHITE")
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/white_pawn.png"));
    else
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/black_pawn.png"));
}
