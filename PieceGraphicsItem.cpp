#include "PieceGraphicsItem.h"
#include "Piece.h"
#include "Game.h"
#include "King.h"
#include "Rook.h"

extern Game *game;

PieceGraphicsItem::PieceGraphicsItem(QGraphicsItem *parent, Piece *p) : QGraphicsPixmapItem(parent)
{
    chessPiece = p;
}

PieceGraphicsItem::~PieceGraphicsItem()
{

}

void PieceGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // odznaczanie wybranej figury
    if(this->chessPiece == game->getPieceToMove()){
        game->getPieceToMove()->getCurrentBox()->getBoxGraphics()->resetOriginalColor();
        game->getPieceToMove()->getPieceGraphics()->decolor();
        game->setPieceToMove(nullptr);
        return;
    }

    // jeżeli figura została zbita oraz zapobieganie możliwości poruszania się figurą, której kolor nie odpowiada aktualnej turze
    if((!this->chessPiece->getIsPlaced()) || ((game->getTurn() != chessPiece->getSide()) && (!game->getPieceToMove())))
        return;

    // wybranie danej figury
    if(!game->getPieceToMove()){
        game->setPieceToMove(chessPiece);
        game->getPieceToMove()->getCurrentBox()->getBoxGraphics()->setColor(Qt::green);
        game->getPieceToMove()->move();
    }

    /* game->pieceToMove - to figura którą chcemy przesunąć, a 'chessPiece' to figura na którą aktualnie klikamy, jest to po prostu
    mechanizm bicia, stąd kolory tych dwóch figur muszą być różne */

    else if(chessPiece->getSide() != game->getPieceToMove()->getSide()){
        chessPiece->getCurrentBox()->getBoxGraphics()->mousePressEvent(event);
    }

    else if(chessPiece->getSide() == game->getPieceToMove()->getSide())
    {
        chessPiece->getCurrentBox()->getBoxGraphics()->mousePressEvent(event);
    }

}


void PieceGraphicsItem::decolor()
{
    for(size_t i = 0, n = chessPiece->moveLocation().size(); i < n;i++) {
        this->chessPiece->moveLocation()[i]->getBoxGraphics()->resetOriginalColor();
    }
}

