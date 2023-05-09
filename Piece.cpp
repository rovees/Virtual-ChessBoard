#include "Piece.h"
#include "Game.h"
#include <QDebug>
#include "King.h"

extern Game *game;

Piece::Piece(QString team, QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    side = team;
    isPlaced = true;
    firstMove = true;
}

Piece::~Piece()
{

}

void Piece::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}


void Piece::setCurrentBox(ChessSquare *box)
{
    currentBox = box;
}

ChessSquare *Piece::getCurrentBox()
{
    return currentBox;
}

QString Piece::getSide()
{
    return side;
}

void Piece::setSide( QString value)
{
    side = value;
}

bool Piece::getIsPlaced()
{
    return isPlaced;
}

void Piece::setIsPlaced(bool value)
{
    isPlaced = value;

}
QList<ChessSquare *> Piece::moveLocation()
{
    return location;
}
void Piece::decolor()
{

}

bool Piece::boxSetting(ChessSquare *box)
{

}
