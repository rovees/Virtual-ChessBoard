#include "ChessSquare.h"
#include "Game.h"
#include <QDebug>
#include "King.h"

extern Game *game;

ChessSquare::ChessSquare(QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    // tworzenie pola szachowego
    setRect(0,0,100,100);
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

void ChessSquare::setColor(QColor color)
{
    brush.setColor(color);
    setBrush(color);
}

void ChessSquare::placePiece(Piece *piece)
{

    piece->setPos(x() + 50 - piece->pixmap().width()/2  ,y() + 50 - piece->pixmap().width()/2);
    piece->setCurrentBox(this);
    setHasChessPiece(true, piece);
    currentPiece = piece;

}

void ChessSquare::setOriginalColor(QColor value)
{
    originalColor = value;
    setColor(originalColor);
}

bool ChessSquare::getHasChessPiece()
{
    return hasChessPiece;
}

void ChessSquare::setHasChessPiece(bool value, Piece *piece)
{
    hasChessPiece = value;
    if(value)
        setChessPieceColor(piece->getSide());
    else
        setChessPieceColor("NONE");
}

QString ChessSquare::getChessPieceColor()
{
    return chessPieceColor;
}

void ChessSquare::setChessPieceColor(QString value)
{
    chessPieceColor = value;
}
