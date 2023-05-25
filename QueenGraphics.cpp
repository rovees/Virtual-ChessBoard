#include "QueenGraphics.h"

QueenGraphics::QueenGraphics(QGraphicsItem *parent, Piece *p) : PieceGraphicsItem(parent)
{
    chessPiece = p;
    setImage();
}

QueenGraphics::~QueenGraphics()
{

}

void QueenGraphics::setImage()
{
    if(chessPiece->getSide() == "WHITE")
        setPixmap(QPixmap("C:/Users/Radek/Documents/SZASZKI/white_queen.png"));
    else
        setPixmap(QPixmap("C:/Users/Radek/Documents/SZASZKI/black_queen.png"));
}
