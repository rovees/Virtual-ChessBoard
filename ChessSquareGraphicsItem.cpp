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
        if (!game->getIsCheck())
        {
        // jeżeli klikniemy na figurę tego samego koloru to nic dalej nie jest wykonywane, chyba że jest możliwość wykonania roszady
        if (this->currSquare->getChessPieceColor() == game->getPieceToMove()->getSide())
        {
            game->performCastling(this);
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


        // przypadek bicia w przelocie;
        game->checkIfEnPassantPossible(this);
        Pawn *pawnPerformingEnPassant = dynamic_cast<Pawn*> (game->getPieceToMove());

        if (pawnPerformingEnPassant && pawnPerformingEnPassant->getEnPassantPossible() && pawnPerformingEnPassant->getSide() == game->getTurn())
        {
            game->performEnPassant(pawnPerformingEnPassant, this);
            return;
        }

        // ustawienie figury na nowym polu
        currSquare->placePiece(game->getPieceToMove());
        game->incrementMoveCounter();

        // sprawdzenie czy jest szach
        bool isCheck;
        isCheck = game->checkForCheck();
        game->setIsCheck(isCheck);

        qDebug() << "Move counter: " << game->getMoveCounter();
        game->setPieceToMove(nullptr);
        // zmiana tury
        game->getGameGraphics()->changeTurn();
        }

        else
        {
        if (!dynamic_cast<King*> (game->getPieceToMove()))
                return;
        else
        {
                // jeżeli klikniemy na figurę tego samego koloru to nic dalej nie jest wykonywane, chyba że jest możliwość wykonania roszady
                if (this->currSquare->getChessPieceColor() == game->getPieceToMove()->getSide())
                {
                game->performCastling(this);
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
                game->incrementMoveCounter();

                // sprawdzenie czy jest szach
                bool isCheck;
                isCheck = game->checkForCheck();
                game->setIsCheck(isCheck);

                qDebug() << "Move counter: " << game->getMoveCounter();
                game->setPieceToMove(nullptr);
                // zmiana tury
                game->getGameGraphics()->changeTurn();

        }

        }


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
