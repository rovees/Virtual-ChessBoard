#include "Pawn.h"
#include "Game.h"
#include <QDebug>
#include <typeinfo>
#include "King.h"
#include "PawnGraphics.h"
#include "Queen.h"
#include "GameGraphics.h"

extern Game * game;

Pawn::Pawn(QString team) : Piece(team)
{
    pieceGraphics = new PawnGraphics(nullptr, this);
    firstMove = true;
}

Pawn::~Pawn()
{
    delete pieceGraphics;
}


void Pawn::move()
{
    location.clear();

    int row = this->getCurrentBox()->getRowPos();
    int col = this->getCurrentBox()->getColPos();


    if(this->getSide() == "WHITE")  {

        if(col > 0 && row > 0 && game->getCollection(row-1, col-1)->getChessPieceColor() == "BLACK") {
            location.append(game->getCollection(row-1, col-1));
            boxSetting(location.last());
        }
        if(col < 7 && row > 0 && game->getCollection(row-1, col+1)->getChessPieceColor() == "BLACK") {
            location.append(game->getCollection(row-1, col+1));
            boxSetting(location.last());
        }
        if(row > 0 && (!game->getCollection(row-1, col)->getHasChessPiece())) {
            location.append(game->getCollection(row-1, col));
            boxSetting(location.last());
            if(firstMove && !game->getCollection(row-2, col)->getHasChessPiece()){
                location.append(game->getCollection(row-2, col));
                boxSetting(location.last());
            }
        }


    }
    else{

        if(col > 0 && row < 7 && game->getCollection(row+1, col-1)->getChessPieceColor() == "WHITE") {
            location.append(game->getCollection(row+1, col-1));
            boxSetting(location.last());
        }
        if(col < 7 && row <  7 && game->getCollection(row+1, col+1)->getChessPieceColor() == "WHITE") {
            location.append(game->getCollection(row+1, col+1));
            boxSetting(location.last());
        }
        if(row < 7 && (!game->getCollection(row+1, col)->getHasChessPiece())) {
            location.append(game->getCollection(row+1, col));
            boxSetting(location.last());
            if(firstMove && !game->getCollection(row+2, col)->getHasChessPiece()){
                location.append(game->getCollection(row+2, col));
                boxSetting(location.last());
            }

        }
    }
    promoteToQueen();

}

void Pawn::promoteToQueen()
{
    // Sprawdzenie, czy pionek dotarł do ostatniego wiersza
    int extremeRow = this->getCurrentBox()->getRowPos();
    int col = this->getCurrentBox()->getColPos();

    if ((this->getSide() == "WHITE" && extremeRow == 0) ||
        (this->getSide() == "BLACK" && extremeRow == 7))
    {
        // Usunięcie pionka z listy żywych figur
        game->getAlivePiece().removeAll(this);

        // Usunięcie pionka z listy figur
        game->getGameGraphics()->removeFromScene(this->getPieceGraphics());

        // Dodanie hetmana na to samo miejsce
        Queen *queen = new Queen(this->getSide());
        game->getCollection(extremeRow, col)->placePiece(queen);

        // Dodanie hetmana do listy żywych figur
        game->getAlivePiece().append(queen);

        // Dodanie hetmana do sceny gry
        game->getGameGraphics()->addToScene(queen->getPieceGraphics());

    }
}

