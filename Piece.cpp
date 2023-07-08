#include "Piece.h"
#include "Game.h"
#include <QDebug>
#include "King.h"
#include "PieceGraphicsItem.h"


extern Game *game;

Piece::Piece(QString team)
{
    side = team;
    isPlaced = true;
}

Piece::~Piece()
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


void Piece::setFirstMove(bool value)
{
    firstMove = value;
}

bool Piece::getFirstMove()
{
    return firstMove;
}

bool Piece::boxSetting(ChessSquare *box)

{
    if(box->getHasChessPiece())
    {
        King *k = dynamic_cast<King*>(box->getCurrentPiece());
        if(k)
        {
            box->getBoxGraphics()->setColor(Qt::blue);
        }
        else
            box->getBoxGraphics()->setColor(Qt::green);
        return true;
    }
    else
        box->getBoxGraphics()->setColor(Qt::darkGreen);
    return false;
}

PieceGraphicsItem *Piece::getPieceGraphics()
{
    return pieceGraphics;
}

void Piece::setPieceGraphics(PieceGraphicsItem *pieceG)
{
    pieceGraphics = pieceG;
}
