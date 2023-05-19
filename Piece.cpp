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
    // odznaczanie wybranej figury
    if(this == game->getPieceToMove()){
        game->getPieceToMove()->getCurrentBox()->resetOriginalColor();
        game->getPieceToMove()->decolor();
        game->setPieceToMove(nullptr);
        return;
    }

    // jeżeli figura została zbita oraz zapobieganie możliwości poruszania się figurą, której kolor nie odpowiada aktualnej turze
    if((!getIsPlaced()) || ((game->getTurn() != this->getSide()) && (!game->getPieceToMove())))
        return;

    // wybranie danej figury
    if(!game->getPieceToMove()){

        game->setPieceToMove(this);
        game->getPieceToMove()->getCurrentBox()->setColor(Qt::green);
        game->getPieceToMove()->move();
    }
    /* game->pieceToMove - to figura którą chcemy przesunąć, a 'this' to figura na którą aktualnie klikamy, jest to po prostu
    mechanizm bicia, stąd kolory tych dwóch figur muszą być różne */
    else if(this->getSide() != game->getPieceToMove()->getSide()){
        this->getCurrentBox()->mousePressEvent(event);
    }
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
    if(box->getHasChessPiece()) {
        King *q = dynamic_cast<King*>(location.last()->getCurrentPiece());
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
