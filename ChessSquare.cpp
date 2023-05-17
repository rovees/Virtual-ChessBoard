#include "ChessSquare.h"
#include "Game.h"
#include <QDebug>
#include "King.h"

extern Game *game;

ChessSquare::ChessSquare(QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    // utworzenie pojedynczego pola szachowego
    setRect(0,0,0.8*100,0.8*100);
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
    setHasChessPiece(false);
    setChessPieceColor("NONE");
    currentPiece = NULL;
}

ChessSquare::~ChessSquare()
{
    // delete this;
}

void ChessSquare::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << getChessPieceColor();
    /* sprawdzenie czy kliknięta figura jest już wybraną figurą, dodatkowo zabezpieczamy się przed błędami wynikającymi z sytuacji, kiedy
    currentPiece miałoby wartość null*/
    if(currentPiece == game->pieceToMove && currentPiece){

        currentPiece->mousePressEvent(event);
        return;
    }

    // jeżeli wybrano figurę
    if(game->pieceToMove){
        // jeżeli klikniemy na figurę tego samego koloru to nic dalej nie jest wykonywane
        if(this->getChessPieceColor() == game->pieceToMove->getSide())
            return;

        QList <ChessSquare *> movLoc = game->pieceToMove->moveLocation();
        // sprawdzenie czy wybrane pole należy do listy możliwych ruchów dla danej figury
        int check = 0;
        for(size_t i = 0, n = movLoc.size(); i < n; i++) {
            if(movLoc[i] == this) {
                check++;

            }
        }
        // jezeli wybrane pole nie jest jednym z pól do którego można się poruszyć to nic dalej nie jest wykonywane
        if(check == 0)
            return;
        // przywrócenie oryginalnych kolorów pól
        game->pieceToMove->decolor();
        // ustawienie atrybutu firstMove (tylko dla pionka, jeżeli został nim wykonany pierwszy ruch)
        game->pieceToMove->firstMove = false;
        // ruch w pole na którym znajduje się figura przeciwnika (bicie) i umieszczenie zbitej figury do obszaru zbitych figur
        if(this->getHasChessPiece()){
            this->currentPiece->setIsPlaced(false);
            this->currentPiece->setCurrentBox(NULL);
            game->placeInDeadPlace(this->currentPiece);

        }
        // resetowanie pola, na którym znajdowała się figura
        game->pieceToMove->getCurrentBox()->setHasChessPiece(false);
        game->pieceToMove->getCurrentBox()->currentPiece = NULL;
        game->pieceToMove->getCurrentBox()->resetOriginalColor();
        // ustawienie figury na nowym polu
        placePiece(game->pieceToMove);

        game->pieceToMove = NULL;
        // zmiana tury
        game->changeTurn();
        // checkForCheck();
    }
    //Selecting couterpart of the chessPiece
    else if(this->getHasChessPiece())
    {
        this->currentPiece->mousePressEvent(event);
    }
}

void ChessSquare::setColor(QColor color)
{
    brush.setColor(color);
    setBrush(color);
}

void ChessSquare::placePiece(Piece *piece)
{

    piece->setPos(x() + 0.8*50 - piece->pixmap().width()/2  ,y() + 0.8*50 - piece->pixmap().width()/2);
    piece->setCurrentBox(this);
    setHasChessPiece(true, piece);
    currentPiece = piece;

}

void ChessSquare::resetOriginalColor()
{
    setColor(originalColor);
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

