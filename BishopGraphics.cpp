#include "BishopGraphics.h"

BishopGraphics::BishopGraphics(QGraphicsItem *parent, Piece *p) : PieceGraphicsItem(parent, p)
{
    setImage();
}

BishopGraphics::~BishopGraphics()
{

}

void BishopGraphics::setImage()
{
    if(chessPiece->getSide() == "WHITE")
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/white_bishop.png"));
    else
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/black_bishop.png"));
}
