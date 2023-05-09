#include "ChessSquare.h"
#include "Game.h"
#include <QDebug>
#include "King.h"

extern Game *game;

ChessSquare::ChessSquare(QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    //making the Square CHess Box
    setRect(0,0,0.8*100,0.8*100);
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
    setHasChessPiece(false);
    setChessPieceColor("NONE");
    currentPiece = NULL;
}

ChessSquare::~ChessSquare()
{
    delete this;
}


