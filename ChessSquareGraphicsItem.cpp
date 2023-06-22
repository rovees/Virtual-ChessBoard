#include "ChessSquareGraphicsItem.h"
#include "ChessSquare.h"
#include "Game.h"
#include "GameGraphics.h"
#include "King.h"
#include "Rook.h"
#include "Pawn.h"


extern Game *game;

ChessSquareGraphicsItem::ChessSquareGraphicsItem(QGraphicsItem *parent, ChessSquare *cS) : QGraphicsRectItem(parent)
{
    currSquare = cS;
    setRect(0,0,0.8*100,0.8*100);
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
}


void ChessSquareGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    // sprawdzenie czy kliknięta figura jest już wybraną figurą, dodatkowo zabezpieczamy się przed błędami wynikającymi z sytuacji, kiedy klikniemy
    // na puste pole szachowe bez zaznaczonej figury
    if(currSquare->getCurrentPiece() == game->getPieceToMove() && currSquare->getCurrentPiece())
    {
        currSquare->getCurrentPiece()->getPieceGraphics()->mousePressEvent(event);
        return;
    }

    qDebug() << "2: " << this->currSquare;
    qDebug() << "getHasChessPiece(): " << this->currSquare->getHasChessPiece();

    // jeżeli wybrano figurę

    if(game->getPieceToMove())
    {
        // rzutowanie zaznaczonej figury i figury na którą klikamy odpowiednio na króla i wieżę
        King *k = dynamic_cast <King*> (game->getPieceToMove());
        Rook *r = dynamic_cast <Rook*> (this->currSquare->getCurrentPiece());

        qDebug() << "k: " << k;
        qDebug() << "r: " << r;


        // jeżeli klikniemy na figurę tego samego koloru to nic dalej nie jest wykonywane, chyba że jest możliwość wykonania roszady
        if (this->currSquare->getChessPieceColor() == game->getPieceToMove()->getSide())
        {

            if(k && r)
            {
                    int kingRowPos = k->getCurrentBox()->getRowPos();
                    int kingColPos = k->getCurrentBox()->getColPos();
                    int rookRowPos = r->getCurrentBox()->getRowPos();
                    int rookColPos = r->getCurrentBox()->getColPos();

                    qDebug() << "king row: " << kingRowPos;
                    qDebug() << "king col: " << kingColPos;
                    qDebug() << "rook row: " << rookRowPos;
                    qDebug() << "rook col: " << rookColPos;

                    if (rookColPos == 0 && k->getLongCastling())
                    {
                        game->getPieceToMove()->getCurrentBox()->setHasChessPiece(false, nullptr);
                        game->getPieceToMove()->getCurrentBox()->setCurrentPiece(nullptr);
                        game->getPieceToMove()->getPieceGraphics()->decolor();
                        game->getPieceToMove()->getCurrentBox()->getBoxGraphics()->resetOriginalColor();
                        game->setPieceToMove(nullptr);
                        game->getGameGraphics()->changeTurn();

                        this->currSquare->setCurrentPiece(nullptr);
                        this->currSquare->setHasChessPiece(false, nullptr);


                        game->getCollection(kingRowPos, kingColPos - 2)->placePiece(k);
                        game->getCollection(rookRowPos, rookColPos + 3)->placePiece(r);
                        k->setLongCastling(false);
                        k->setFirstMove(false);
                        r->setFirstMove(false);
                    }
                    else if (rookColPos == 7 && k->getShortCastling())
                    {
                        k->getCurrentBox()->setHasChessPiece(false, nullptr);

                        game->getPieceToMove()->getCurrentBox()->setHasChessPiece(false);
                        game->getPieceToMove()->getCurrentBox()->setCurrentPiece(nullptr);
                        game->getPieceToMove()->getPieceGraphics()->decolor();
                        game->getPieceToMove()->getCurrentBox()->getBoxGraphics()->resetOriginalColor();
                        game->setPieceToMove(nullptr);
                        game->getGameGraphics()->changeTurn();

                        this->currSquare->setCurrentPiece(nullptr);
                        this->currSquare->setHasChessPiece(false, nullptr);

                        game->getCollection(kingRowPos, kingColPos + 2)->placePiece(k);
                        game->getCollection(rookRowPos, rookColPos - 2)->placePiece(r);
                        k->setShortCastling(false);
                        k->setFirstMove(false);
                        r->setFirstMove(false);

                    }
            }


            return;
        }

            QList <ChessSquare *> movLoc = game->getPieceToMove()->moveLocation();
             // sprawdzenie czy wybrane pole należy do listy możliwych ruchów dla danej figury
            int check = 0;
            for(size_t i = 0, n = movLoc.size(); i < n; i++)
            {
                if(movLoc[i] == this->currSquare)
                {
                    check++;
                }
            }

            // jezeli wybrane pole nie jest jednym z pól do którego można się poruszyć to nic dalej nie jest wykonywane
            if(check == 0)
                return;

            // przywrócenie oryginalnych kolorów pól
            game->getPieceToMove()->getPieceGraphics()->decolor();

            // ustawienie atrybutu firstMove (jeżeli został wykonany pierwszy ruch daną figurą)
            game->getPieceToMove()->setFirstMove(false);


            // ruch w pole na którym znajduje się figura przeciwnika (bicie) i umieszczenie zbitej figury do obszaru zbitych figur
            if(this->currSquare->getHasChessPiece() && this->currSquare->getCurrentPiece()->getSide() != game->getPieceToMove()->getSide())
            {
                this->currSquare->getCurrentPiece()->setIsPlaced(false);
                this->currSquare->getCurrentPiece()->setCurrentBox(nullptr);
                King *k = dynamic_cast<King *> (this->currSquare->getCurrentPiece());

                if (k)
                {
                    game->getGameGraphics()->setWinner(game->getPieceToMove()->getSide());
                    game->gameOver();
                    game->getGameGraphics()->displayWinner(game->getGameGraphics()->getWinner());
                }

                game->getGameGraphics()->placeInDeadPlace(this->currSquare->getCurrentPiece());
            }

            // resetowanie pola, na którym znajdowała się figura
            game->getPieceToMove()->getCurrentBox()->setHasChessPiece(false);
            game->getPieceToMove()->getCurrentBox()->setCurrentPiece(nullptr);
            game->getPieceToMove()->getCurrentBox()->getBoxGraphics()->resetOriginalColor();

            // ustawienie figury na nowym polu
            currSquare->placePiece(game->getPieceToMove());

            game->setPieceToMove(nullptr);
            // zmiana tury
            game->getGameGraphics()->changeTurn();

            // sprawdzenie czy jest szach
            this->currSquare->checkForCheck();
    }


        // obsługa zdarzenia kliknięcia na figurę, znajdującą się na danym polu, którą chcemy przesunąć
        else if(this->currSquare->getHasChessPiece())
        {
            currSquare->getCurrentPiece()->getPieceGraphics()->mousePressEvent(event);
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
