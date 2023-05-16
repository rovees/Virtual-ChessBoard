#include "Piece.h"
#include "Game.h"
#include <QDebug>
#include "King.h"

extern Game *game;

Piece::Piece(QString team, QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    side = team;
    isPlaced = true;
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
    for(size_t i = 0, n = location.size(); i < n;i++) {
        location[i]->resetOriginalColor();
    }
}

bool Piece::boxSetting(ChessSquare *box)

{
    if(box->getHasChessPiece()) {
        King *q = dynamic_cast<King*>(location.last()->currentPiece);
        if(q){
            box->setColor(Qt::blue);
        }
        else
            box->setColor(Qt::green);
        return true;
    }
    else
        location.last()->setColor(Qt::darkGreen);
    return false;
}
