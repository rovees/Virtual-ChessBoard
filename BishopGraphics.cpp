#include "BishopGraphics.h"

BishopGraphics::BishopGraphics(QGraphicsItem *parent, Piece *p) : PieceGraphicsItem(parent)
{
    chessPiece = p;
    setImage();
}

BishopGraphics::~BishopGraphics()
{

}

void BishopGraphics::setImage()
{
    if(chessPiece->getSide() == "WHITE")
        setPixmap(QPixmap("C:/Users/Radek/Documents/SZASZKI/white_bishop.png"));
    else
        setPixmap(QPixmap("C:/Users/Radek/Documents/SZASZKI/black_bishop.png"));
}
