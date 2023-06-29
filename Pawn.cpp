#include "Pawn.h"
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
    enPassantPossible = false;
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

        // Sprawdzenie możliwości bicia w przelocie w lewo
        if (row == 3 && col > 0 && game->getCollection(row, col - 1)->getHasChessPiece() && game->getMoveCounter() == 1) {
            Piece *leftPiece = game->getCollection(row, col - 1)->getCurrentPiece();

            if (dynamic_cast<Pawn *>(leftPiece) && leftPiece->getSide() == "BLACK") {

                if (this->getEnPassantPossible()) {
                    location.append(game->getCollection(row - 1, col - 1));
                    boxSetting(location.last());
                }
            }
        }

        // Sprawdzenie możliwości bicia w przelocie w prawo
        if (row == 3 && col < 7 && game->getCollection(row, col + 1)->getHasChessPiece() && game->getMoveCounter() == 1) {
            Piece *rightPiece = game->getCollection(row, col + 1)->getCurrentPiece();

            if (dynamic_cast<Pawn *>(rightPiece) && rightPiece->getSide() == "BLACK") {

                if (this->getEnPassantPossible()) {
                    location.append(game->getCollection(row - 1, col + 1));
                    boxSetting(location.last());
                }
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

        // Sprawdzenie możliwości bicia w przelocie w lewo
        if (row == 4 && col > 0 && game->getCollection(row, col - 1)->getHasChessPiece() && game->getMoveCounter() == 1) {
            Piece *leftPiece = game->getCollection(row, col - 1)->getCurrentPiece();

            if (dynamic_cast<Pawn *>(leftPiece) && leftPiece->getSide() == "WHITE") {

                if (this->getEnPassantPossible()) {
                    location.append(game->getCollection(row + 1, col - 1));
                    boxSetting(location.last());
                }
            }
        }

        // Sprawdzenie możliwości bicia w przelocie w prawo
        if (row == 4 && col < 7 && game->getCollection(row, col + 1)->getHasChessPiece() && game->getMoveCounter() == 1) {
            Piece *rightPiece = game->getCollection(row, col + 1)->getCurrentPiece();

            if (dynamic_cast<Pawn *>(rightPiece) && rightPiece->getSide() == "WHITE") {

                if (this->getEnPassantPossible()) {
                    location.append(game->getCollection(row + 1, col + 1));
                    boxSetting(location.last());
                }
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

bool Pawn::getEnPassantPossible()
{
    return enPassantPossible;
}

void Pawn::setEnPassantPossible(bool value)
{
    enPassantPossible = value;
}




