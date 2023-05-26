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

/*
void Piece::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // odznaczanie wybranej figury
    if(this == game->getPieceToMove()){
        game->getPieceToMove()->getCurrentBox()->getBoxGraphics()->resetOriginalColor();
        game->getPieceToMove()->getPieceGraphics()->decolor();
        game->setPieceToMove(nullptr);
        return;
    }

    // jeżeli figura została zbita oraz zapobieganie możliwości poruszania się figurą, której kolor nie odpowiada aktualnej turze
    if((!getIsPlaced()) || ((game->getTurn() != this->getSide()) && (!game->getPieceToMove())))
        return;

    // wybranie danej figury
    if(!game->getPieceToMove()){

        game->setPieceToMove(this);
        game->getPieceToMove()->getCurrentBox()->getBoxGraphics()->setColor(Qt::green);
        game->getPieceToMove()->move();
    }
    game->pieceToMove - to figura którą chcemy przesunąć, a 'this' to figura na którą aktualnie klikamy, jest to po prostu
    mechanizm bicia, stąd kolory tych dwóch figur muszą być różne
    else if(this->getSide() != game->getPieceToMove()->getSide()){
        this->getCurrentBox()->getBoxGraphics()->mousePressEvent(event);
    }
}
*/

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

/*
void Piece::decolor()
{
    for(int i = 0, n = location.size(); i < n;i++) {
        location[i]->getBoxGraphics()->resetOriginalColor();
    }
}
*/

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
            box->getBoxGraphics()->setColor(Qt::blue);
        }
        else
            box->getBoxGraphics()->setColor(Qt::green);
        return true;
    }
    else
        location.last()->getBoxGraphics()->setColor(Qt::darkGreen);
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
