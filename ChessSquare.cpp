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
    if(currentPiece == game->getPieceToMove() && currentPiece){

        currentPiece->mousePressEvent(event);
        return;
    }

    // jeżeli wybrano figurę
    if(game->getPieceToMove()){
        // jeżeli klikniemy na figurę tego samego koloru to nic dalej nie jest wykonywane
        if(this->getChessPieceColor() == game->getPieceToMove()->getSide())
            return;

        QList <ChessSquare *> movLoc = game->getPieceToMove()->moveLocation();
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
        game->getPieceToMove()->decolor();
        // ustawienie atrybutu firstMove (tylko dla pionka, jeżeli został nim wykonany pierwszy ruch)
        game->getPieceToMove()->setFirstMove(false);
        // ruch w pole na którym znajduje się figura przeciwnika (bicie) i umieszczenie zbitej figury do obszaru zbitych figur
        if(this->getHasChessPiece()){
            this->currentPiece->setIsPlaced(false);
            this->currentPiece->setCurrentBox(NULL);
            game->placeInDeadPlace(this->currentPiece);

        }
        // resetowanie pola, na którym znajdowała się figura
        game->getPieceToMove()->getCurrentBox()->setHasChessPiece(false);
        game->getPieceToMove()->getCurrentBox()->currentPiece = NULL;
        game->getPieceToMove()->getCurrentBox()->resetOriginalColor();
        // ustawienie figury na nowym polu
        placePiece(game->getPieceToMove());

        game->setPieceToMove(nullptr);
        // zmiana tury
        game->changeTurn();
        // sprawdzenie czy jest szach
        checkForCheck();
    }
    //Selecting couterpart of the chessPiece
    else if(this->getHasChessPiece())
    {
        this->currentPiece->mousePressEvent(event);
    }
}

void ChessSquare::checkForCheck()
{
    // czy został obsłużony szach
    int c = 0;
    // lista wszystkich figur na szachownicy
    QList <Piece *> pList = game->getAlivePiece();
    // iteracja przez żywe figury na szachownicy
    for(size_t i = 0, n = pList.size(); i < n; i++ ) {
    // rzutowanie aktualnej figury na króla
        King * p = dynamic_cast <King *> (pList[i]);
        // jezeli figura jest królem to przeskakujemy do następnego kroku pętli
        if(p){
            continue;
        }
        pList[i]->move();
        pList[i]->decolor();
        // lista pól w które można się przesunąć daną figurą
        QList <ChessSquare *> bList = pList[i]->moveLocation();
        // iteracja przez pola, w które możemy się poruszyć daną figurą znajdującą się na polu bList
        for(size_t j = 0, n = bList.size(); j < n; j++) {
            // rzutowanie figury stojącej na danym polu szachowym na Króla
            King * p = dynamic_cast<King *> (bList[j]->currentPiece);

            if(p) {
                /*jezeli figura znajdująca się na polu bList jest Królem i jest tego samego koloru co figura z listy pList, którą przesuwamy to
                 przeskakujemy do następnego kroku pętli */
                if(p->getSide() == pList[i]->getSide())
                    continue;
                bList[j]->setColor(Qt::darkRed);
                if(!game->getCheck()->isVisible())
                    game->getCheck()->setVisible(true);
                else{
                    bList[j]->resetOriginalColor();
                    pList[i]->getCurrentBox()->resetOriginalColor();
                    // game->gameOver();
                }
                c++;

            }
        }


    }

    // jesli nie ma szacha to resetujemy kolory pól wszystkich figur na szachownicy
    if(!c){
        game->getCheck()->setVisible(false);
        for(size_t i = 0, n = pList.size(); i < n; i++ )
            pList[i]->getCurrentBox()->resetOriginalColor();
    }
}

void ChessSquare::setColor(QColor color)
{
    brush.setColor(color);
    setBrush(color);
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

