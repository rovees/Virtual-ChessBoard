#include "Game.h"
#include <QPixmap>
#include <QDebug>
#include "GameGraphics.h"
#include "King.h"
#include "Bishop.h"
#include "Queen.h"
#include "Rook.h"
#include <cmath>

Game::Game()
{
    chess = new ChessBoard();
    gameGraphics = new GameGraphics(nullptr, this);
    pieceToMove = nullptr;
    setTurn("WHITE");
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
        King *p = dynamic_cast <King *> (alivePiecesList[i]);
        // jezeli figura jest królem to przeskakujemy do następnego kroku pętli
        if(p)
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



