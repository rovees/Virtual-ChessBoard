#include "Pawn.h"
#include "Game.h"
#include <QDebug>
#include <typeinfo>
#include "King.h"

extern Game * game;

Pawn::Pawn(QString team, QGraphicsItem *parent) : Piece(team, parent)
{
    setImage();
    firstMove = true;
}

Pawn::~Pawn()
{

}

void Pawn::setImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap("C:/Users/Radek/Documents/SZASZKI/white_pawn.png"));
    else
        setPixmap(QPixmap("C:/Users/Radek/Documents/SZASZKI/black_pawn.png"));
}



void Pawn::move()
{
    location.clear();

    int row = this->getCurrentBox()->rowPos;
    int col = this->getCurrentBox()->colPos;

    if(this->getSide() == "WHITE")  {
        if(col > 0 && row > 0 && game->collection[row-1][col-1]->getChessPieceColor() == "BLACK") {
            location.append(game->collection[row-1][col-1]);
            boxSetting(location.last());
        }
        if(col < 7 && row > 0 && game->collection[row-1][col+1]->getChessPieceColor() == "BLACK") {
            location.append(game->collection[row-1][col+1]);
            boxSetting(location.last());
        }
        if(row>0 && (!game->collection[row-1][col]->getHasChessPiece())) {
            location.append(game->collection[row-1][col]);
            boxSetting(location.last());
            if(firstMove && !game->collection[row-2][col]->getHasChessPiece()){
                location.append(game->collection[row-2][col]);
                boxSetting(location.last());
            }
        }

    }
    else{
        if(col > 0 && row < 7 && game->collection[row+1][col-1]->getChessPieceColor() == "WHITE") {
            location.append(game->collection[row+1][col-1]);
            boxSetting(location.last());
        }
        if(col < 7 && row <  7 && game->collection[row+1][col+1]->getChessPieceColor() == "WHITE") {
            location.append(game->collection[row+1][col+1]);
            boxSetting(location.last());
        }
        if(row<7 && (!game->collection[row+1][col]->getHasChessPiece())) {
            location.append(game->collection[row+1][col]);
            boxSetting(location.last());
            if(firstMove && !game->collection[row+2][col]->getHasChessPiece()){
                location.append(game->collection[row+2][col]);
                boxSetting(location.last());
            }

        }

    }

}

