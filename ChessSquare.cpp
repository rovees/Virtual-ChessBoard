#include "ChessSquare.h"
#include "Game.h"
#include <QDebug>
#include "King.h"
#include "GameGraphics.h"

extern Game *game;

ChessSquare::ChessSquare()
{
    setHasChessPiece(false);
    setChessPieceColor("NONE");
    currentPiece = nullptr;
    boxGraphics = new ChessSquareGraphicsItem(nullptr, this);
}

ChessSquare::~ChessSquare()
{
    delete boxGraphics;
}


void ChessSquare::setCurrentPiece(Piece *p)
{
    currentPiece = p;
}

Piece *ChessSquare::getCurrentPiece()
{
    return currentPiece;
}

void ChessSquare::setRowPos(int row)
{
    rowPos = row;
}

int ChessSquare::getRowPos()
{
    return rowPos;
}

void ChessSquare::setColPos(int col)
{
    colPos = col;
}

int ChessSquare::getColPos()
{
    return colPos;
}

void ChessSquare::placePiece(Piece *piece)
{
    piece->getPieceGraphics()->setPos(getBoxGraphics()->x() + 0.8*50 - piece->getPieceGraphics()->pixmap().width()/2  ,getBoxGraphics()->y() + 0.8*50 - piece->getPieceGraphics()->pixmap().width()/2);
    piece->setCurrentBox(this);
    setHasChessPiece(true, piece);
    currentPiece = piece;

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

void ChessSquare::setBoxGraphics(ChessSquareGraphicsItem *boxG)
{
    boxGraphics = boxG;
}


ChessSquareGraphicsItem *ChessSquare::getBoxGraphics()
{
    return boxGraphics;
}

