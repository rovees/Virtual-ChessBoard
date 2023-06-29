#include "Game.h"
#include <QPixmap>
#include <QDebug>
#include "GameGraphics.h"
#include "King.h"
#include "Bishop.h"
#include "Queen.h"
#include "Rook.h"
#include <cmath>
#include "Pawn.h"

Game::Game()
{
    chess = new ChessBoard();
    gameGraphics = new GameGraphics(nullptr, this);
    pieceToMove = nullptr;
    setTurn("WHITE");
    moveCounter = 0;
}

Game::~Game()
{
    delete chess;
    delete gameGraphics;
}

GameGraphics *Game::getGameGraphics()
{
    return gameGraphics;
}

void Game::setGameGraphics(GameGraphics *gameG)
{
    gameGraphics = gameG;
}

QList <Piece *> &Game::getWhiteDead()
{
    return whiteDead;
}

QList <Piece *> &Game::getBlackDead()
{
    return blackDead;
}


QString Game::getTurn()
{
    return turn;
}

void Game::setTurn(QString value)
{
    turn = value;
}

void Game::setPieceToMove(Piece *p)
{
    pieceToMove = p;
}

Piece *Game::getPieceToMove()
{
    return pieceToMove;
}


QList <Piece *> &Game::getAlivePiece()
{
    return alivePiece;
}

void Game::setCollection(int x, int y, ChessSquare *box)
{
    collection[x][y] = box;
}

ChessSquare *Game::getCollection(int x, int y)
{
    return collection[x][y];
}

ChessBoard *Game::getChess()
{
    return chess;
}

bool Game::checkForCheck()
{

    // czy został obsłużony szach
    int c = 0;
    // lista wszystkich figur na szachownicy
    QList <Piece *> alivePiecesList = getAlivePiece();
    // iteracja przez żywe figury na szachownicy
    for(size_t i = 0, n1 = alivePiecesList.size(); i < n1; i++ ) {
        // rzutowanie aktualnej figury na króla
        King *k = dynamic_cast <King *> (alivePiecesList[i]);
        // jezeli figura jest królem to przeskakujemy do następnego kroku pętli
        if(k)
        {
            continue;
        }

        alivePiecesList[i]->move();
        alivePiecesList[i]->getPieceGraphics()->decolor();
        // lista pól w które można się przesunąć daną figurą
        QList <ChessSquare *> moveLocationsList = alivePiecesList[i]->moveLocation();
        // iteracja przez pola, w które możemy się poruszyć daną figurą znajdującą się na polu moveLocationsList
        for(size_t j = 0, n2 = moveLocationsList.size(); j < n2; j++) {
            // rzutowanie figury stojącej na danym polu szachowym na Króla
            King * king = dynamic_cast<King *> (moveLocationsList[j]->getCurrentPiece());

            if(king) {
                /*jezeli figura znajdująca się na polu moveLocationsList jest Królem i jest tego samego koloru co figura z listy alivePiecesList, którą przesuwamy to
                 przeskakujemy do następnego kroku pętli */
                if(king->getSide() == alivePiecesList[i]->getSide())
                    continue;
                moveLocationsList[j]->getBoxGraphics()->setColor(Qt::darkRed);
                if(!getGameGraphics()->getCheck()->isVisible())
                {
                    getGameGraphics()->getCheck()->setVisible(true);
                }
                else{
                    moveLocationsList[j]->getBoxGraphics()->resetOriginalColor();
                    alivePiecesList[i]->getCurrentBox()->getBoxGraphics()->resetOriginalColor();
                    // game->gameOver();
                }
                c++;

            }
        }


    }

    // jesli nie ma szacha to resetujemy kolory pól wszystkich figur na szachownicy
    if(!c){
        getGameGraphics()->getCheck()->setVisible(false);
        for(size_t i = 0, n3 = alivePiecesList.size(); i < n3; i++ )
            alivePiecesList[i]->getCurrentBox()->getBoxGraphics()->resetOriginalColor();
        return false;
    }


    return true;
}

bool Game::getIsCheck()
{
    return isCheck;
}

void Game::setIsCheck(bool val)
{
    isCheck = val;
}

void Game::gameOver()
{
    getGameGraphics()->removeAll();
    alivePiece.clear();
}

int Game::getMoveCounter()
{
    return moveCounter;
}

void Game::setMoveCounter(int value)
{
    moveCounter = value;
}

void Game::incrementMoveCounter()
{
    moveCounter++;
}

void Game::performCastling(ChessSquareGraphicsItem *chessBoxGraphics)
{

    // rzutowanie zaznaczonej figury i figury na którą klikamy odpowiednio na króla i wieżę
    King *k = dynamic_cast <King*> (getPieceToMove());
    Rook *r = dynamic_cast <Rook*> (chessBoxGraphics->getCurrSquare()->getCurrentPiece());

    qDebug() << "k: " << k;
    qDebug() << "r: " << r;

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
                getPieceToMove()->getCurrentBox()->setHasChessPiece(false, nullptr);
                getPieceToMove()->getCurrentBox()->setCurrentPiece(nullptr);
                getPieceToMove()->getPieceGraphics()->decolor();
                getPieceToMove()->getCurrentBox()->getBoxGraphics()->resetOriginalColor();
                setPieceToMove(nullptr);
                getGameGraphics()->changeTurn();

                chessBoxGraphics->getCurrSquare()->setCurrentPiece(nullptr);
                chessBoxGraphics->getCurrSquare()->setHasChessPiece(false, nullptr);


                getCollection(kingRowPos, kingColPos - 2)->placePiece(k);
                getCollection(rookRowPos, rookColPos + 3)->placePiece(r);
                k->setLongCastling(false);
                k->setFirstMove(false);
                r->setFirstMove(false);

                incrementMoveCounter();
            }
            else if (rookColPos == 7 && k->getShortCastling())
            {
                k->getCurrentBox()->setHasChessPiece(false, nullptr);

                getPieceToMove()->getCurrentBox()->setHasChessPiece(false);
                getPieceToMove()->getCurrentBox()->setCurrentPiece(nullptr);
                getPieceToMove()->getPieceGraphics()->decolor();
                getPieceToMove()->getCurrentBox()->getBoxGraphics()->resetOriginalColor();
                setPieceToMove(nullptr);
                getGameGraphics()->changeTurn();

                chessBoxGraphics->getCurrSquare()->setCurrentPiece(nullptr);
                chessBoxGraphics->getCurrSquare()->setHasChessPiece(false, nullptr);

                getCollection(kingRowPos, kingColPos + 2)->placePiece(k);
                getCollection(rookRowPos, rookColPos - 2)->placePiece(r);
                k->setShortCastling(false);
                k->setFirstMove(false);
                r->setFirstMove(false);

                incrementMoveCounter();
            }
        }
}

void Game::checkIfEnPassantPossible(ChessSquareGraphicsItem *chessBoxGraphics)
{
        // sprawdzenie czy będzie możliwe bicie w przelocie
        Pawn *pawn = dynamic_cast<Pawn*> (getPieceToMove());
        int pawnRow = getPieceToMove()->getCurrentBox()->getRowPos();
        int currSquareRow = chessBoxGraphics->getCurrSquare()->getRowPos();
        int currSquareCol = chessBoxGraphics->getCurrSquare()->getColPos();
        Pawn *leftPawn = dynamic_cast<Pawn*> (getCollection(currSquareRow, currSquareCol-1)->getCurrentPiece());
        Pawn *rightPawn = dynamic_cast<Pawn*> (getCollection(currSquareRow, currSquareCol+1)->getCurrentPiece());


        if (pawn && abs(pawnRow - currSquareRow) == 2)
        {
            if (leftPawn && leftPawn->getSide() != pawn->getSide())
            {
                leftPawn->setEnPassantPossible(true);
                setMoveCounter(0);
            }

            else if (rightPawn && rightPawn->getSide() != pawn->getSide())
            {
                rightPawn->setEnPassantPossible(true);
                setMoveCounter(0);
            }

            qDebug() << "roznica: " << abs(pawnRow - currSquareRow);
        }
}

void Game::performEnPassant(Pawn *pawnPerformingEnPassant, ChessSquareGraphicsItem *chessBoxGraphics)
{
        int currSquareRow = chessBoxGraphics->getCurrSquare()->getRowPos();
        int currSquareCol = chessBoxGraphics->getCurrSquare()->getColPos();
        int pawnRow = pawnPerformingEnPassant->getCurrentBox()->getRowPos();
        int pawnCol = pawnPerformingEnPassant->getCurrentBox()->getColPos();

        if (pawnPerformingEnPassant->getSide() == "WHITE")
        {
            // wykonanie bicia w przelocie
            if ((chessBoxGraphics->getCurrSquare() == getCollection(pawnRow-1, pawnCol-1) && !getCollection(pawnRow-1, pawnCol-1)->getHasChessPiece())
                || (chessBoxGraphics->getCurrSquare() == getCollection(pawnRow-1, pawnCol+1) && !getCollection(pawnRow-1, pawnCol+1)->getHasChessPiece()))
            {
                if (getMoveCounter() == 1)
                {
                    getGameGraphics()->placeInDeadPlace(getCollection(currSquareRow + 1, currSquareCol)->getCurrentPiece());
                    getCollection(currSquareRow + 1, currSquareCol)->setHasChessPiece(false, nullptr);
                    getCollection(currSquareRow + 1, currSquareCol)->setCurrentPiece(nullptr);
                    getCollection(currSquareRow + 1, currSquareCol)->getBoxGraphics()->resetOriginalColor();
                    chessBoxGraphics->getCurrSquare()->placePiece(pawnPerformingEnPassant);

                    incrementMoveCounter();
                    // sprawdzenie czy jest szach
                    bool isCheck;
                    isCheck = checkForCheck();
                    setIsCheck(isCheck);

                    setPieceToMove(nullptr);
                    getGameGraphics()->changeTurn();
                }
            }

            // wykonanie innego ruchu wynikająćego z możliwości piona w danej pozycji
            else
            {
                if(chessBoxGraphics->getCurrSquare()->getHasChessPiece() && chessBoxGraphics->getCurrSquare()->getCurrentPiece()->getSide() != pawnPerformingEnPassant->getSide())
                {
                    chessBoxGraphics->getCurrSquare()->getCurrentPiece()->setIsPlaced(false);
                    chessBoxGraphics->getCurrSquare()->getCurrentPiece()->setCurrentBox(nullptr);
                    King *k = dynamic_cast<King *> (chessBoxGraphics->getCurrSquare()->getCurrentPiece());

                    if (k)
                    {
                    getGameGraphics()->setWinner(pawnPerformingEnPassant->getSide());
                    gameOver();
                    getGameGraphics()->displayWinner(getGameGraphics()->getWinner());
                    }

                    getGameGraphics()->placeInDeadPlace(chessBoxGraphics->getCurrSquare()->getCurrentPiece());
                }

                // resetowanie pola, na którym znajdowała się figura
                pawnPerformingEnPassant->getCurrentBox()->setHasChessPiece(false, nullptr);
                pawnPerformingEnPassant->getCurrentBox()->setCurrentPiece(nullptr);
                pawnPerformingEnPassant->getCurrentBox()->getBoxGraphics()->resetOriginalColor();

                chessBoxGraphics->getCurrSquare()->placePiece(pawnPerformingEnPassant);
                incrementMoveCounter();

                // sprawdzenie czy jest szach
                bool isCheck;
                isCheck = checkForCheck();
                setIsCheck(isCheck);

                setPieceToMove(nullptr);
                getGameGraphics()->changeTurn();
            }
        }

        else if (pawnPerformingEnPassant->getSide() == "BLACK")
        {
            // wykonanie bicia w przelocie
            if ((chessBoxGraphics->getCurrSquare() == getCollection(pawnRow+1, pawnCol-1) && !getCollection(pawnRow+1, pawnCol-1)->getHasChessPiece())
                || (chessBoxGraphics->getCurrSquare() == getCollection(pawnRow+1, pawnCol+1) && !getCollection(pawnRow+1, pawnCol+1)->getHasChessPiece()))
            {
                if (getMoveCounter() == 1)
                {
                    getGameGraphics()->placeInDeadPlace(getCollection(currSquareRow - 1, currSquareCol)->getCurrentPiece());
                    getCollection(currSquareRow - 1, currSquareCol)->setHasChessPiece(false, nullptr);
                    getCollection(currSquareRow - 1, currSquareCol)->setCurrentPiece(nullptr);
                    getCollection(currSquareRow - 1, currSquareCol)->getBoxGraphics()->resetOriginalColor();
                    chessBoxGraphics->getCurrSquare()->placePiece(pawnPerformingEnPassant);
                    incrementMoveCounter();

                    // sprawdzenie czy jest szach
                    bool isCheck;
                    isCheck = checkForCheck();
                    setIsCheck(isCheck);

                    setPieceToMove(nullptr);
                    getGameGraphics()->changeTurn();
                }
            }

            // wykonanie innego ruchu wynikająćego z możliwości piona w danej pozycji
            else
            {
                if(chessBoxGraphics->getCurrSquare()->getHasChessPiece() && chessBoxGraphics->getCurrSquare()->getCurrentPiece()->getSide() != pawnPerformingEnPassant->getSide())
                {
                    chessBoxGraphics->getCurrSquare()->getCurrentPiece()->setIsPlaced(false);
                    chessBoxGraphics->getCurrSquare()->getCurrentPiece()->setCurrentBox(nullptr);
                    King *k = dynamic_cast<King *> (chessBoxGraphics->getCurrSquare()->getCurrentPiece());

                    if (k)
                    {
                    getGameGraphics()->setWinner(pawnPerformingEnPassant->getSide());
                    gameOver();
                    getGameGraphics()->displayWinner(getGameGraphics()->getWinner());
                    }

                    getGameGraphics()->placeInDeadPlace(chessBoxGraphics->getCurrSquare()->getCurrentPiece());
                }

                // resetowanie pola, na którym znajdowała się figura
                pawnPerformingEnPassant->getCurrentBox()->setHasChessPiece(false, nullptr);
                pawnPerformingEnPassant->getCurrentBox()->setCurrentPiece(nullptr);
                pawnPerformingEnPassant->getCurrentBox()->getBoxGraphics()->resetOriginalColor();

                chessBoxGraphics->getCurrSquare()->placePiece(pawnPerformingEnPassant);
                incrementMoveCounter();

                // sprawdzenie czy jest szach
                bool isCheck;
                isCheck = checkForCheck();
                setIsCheck(isCheck);

                setPieceToMove(nullptr);
                getGameGraphics()->changeTurn();
            }
        }
}



