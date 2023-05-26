#include "ChessSquareGraphicsItem.h"
#include "ChessSquare.h"
#include "Game.h"
#include "GameGraphics.h"

extern Game *game;

ChessSquareGraphicsItem::ChessSquareGraphicsItem(QGraphicsItem *parent, ChessSquare *cS) : QGraphicsRectItem(parent)
{
    currSquare = cS;
    // currSquare = new ChessSquare(this);
    setRect(0,0,0.8*100,0.8*100);
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
}


void ChessSquareGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    qDebug() << "1: " << this->currSquare;
    // Deselecting counter part of ChessPiece
    if(currSquare->getCurrentPiece() == game->getPieceToMove() && currSquare->getCurrentPiece()){

        currSquare->getCurrentPiece()->getPieceGraphics()->mousePressEvent(event);
        return;
    }

    // if selected
    qDebug() << "2: " << this->currSquare;
    if(game->getPieceToMove()){
        // if same team
        if(this->currSquare->getChessPieceColor() == game->getPieceToMove()->getSide())
            return;
        // removing the eaten piece
        qDebug() << "3: " << this->currSquare;
        QList <ChessSquare *> movLoc = game->getPieceToMove()->moveLocation();
        qDebug() << "4: " << this->currSquare;
        // To make sure the selected box is in move zone
        int check = 0;
        for(size_t i = 0, n = movLoc.size(); i < n; i++) {
            if(movLoc[i] == this->currSquare) {
                check++;

            }
        }
        // if not prsent return
        if(check == 0)
            return;
        // change the color back to normal
        game->getPieceToMove()->getPieceGraphics()->decolor();
        // make the first move false applicable for pawn only
        game->getPieceToMove()->setFirstMove(false);
        // this is to eat or consume the enemy present in the movable region
        qDebug() << "5: " <<  this->currSquare;
        if(this->currSquare->getHasChessPiece()){
            this->currSquare->getCurrentPiece()->setIsPlaced(false);
            this->currSquare->getCurrentPiece()->setCurrentBox(nullptr);
            // this->currSquare->getCurrentPiece()->getCurrentBox()->setBoxGraphics(nullptr);
            game->getGameGraphics()->placeInDeadPlace(this->currSquare->getCurrentPiece());

        }
        // changing the new stat and resetting the previous left region
        game->getPieceToMove()->getCurrentBox()->setHasChessPiece(false);
        game->getPieceToMove()->getCurrentBox()->setCurrentPiece(nullptr);
        game->getPieceToMove()->getCurrentBox()->getBoxGraphics()->resetOriginalColor();
        currSquare->placePiece(game->getPieceToMove());

        game->setPieceToMove(nullptr);
        //changing turn
        game->getGameGraphics()->changeTurn();
        this->currSquare->checkForCheck();
        qDebug() << "6: " << this->currSquare;
    }
    //Selecting couterpart of the chessPiece

    else if(this->currSquare->getHasChessPiece())
    {
        qDebug() << "7: " << this->currSquare;
        currSquare->getCurrentPiece()->getPieceGraphics()->mousePressEvent(event);
        qDebug() << "8: " << this->currSquare;
    }

}


void ChessSquareGraphicsItem::setColor(QColor color)
{
    brush.setColor(color);
    setBrush(color);
}

QColor ChessSquareGraphicsItem::getColor()
{
    return brush.color();
}

void ChessSquareGraphicsItem::resetOriginalColor()
{
    setColor(originalColor);
}

void ChessSquareGraphicsItem::setOriginalColor(QColor value)
{
    originalColor = value;
    setColor(originalColor);
}



ChessSquare *ChessSquareGraphicsItem::getCurrSquare()
{
    return currSquare;
}

void ChessSquareGraphicsItem::setCurrSquare(ChessSquare *currChessSquare)
{
    currSquare = currChessSquare;
}
