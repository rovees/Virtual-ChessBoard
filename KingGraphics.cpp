#include "KingGraphics.h"


KingGraphics::KingGraphics(QGraphicsItem *parent, Piece *p) : PieceGraphicsItem(parent, p)
{
    setImage();
}

KingGraphics::~KingGraphics()
{

}

void KingGraphics::setImage()
{
    if(chessPiece->getSide() == "WHITE")
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/white_king.png"));
    else
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/black_king.png"));
}
