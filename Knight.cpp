#include "Knight.h"
#include "Game.h"
#include "KnightGraphics.h"


extern Game *game;

Knight::Knight(QString team) : Piece(team) //,parent)
{
    pieceGraphics = new KnightGraphics(nullptr, this);
    //setImage();
}

Knight::~Knight()
{

}

/*
void Knight::setImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/white_knight.png"));
    else
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/black_knight.png"));
}
*/


void Knight::move()
{
    int row = this->getCurrentBox()->getRowPos();
    int col = this->getCurrentBox()->getColPos();
    int i ,j;
    QString team  = this->getSide();

    // Jest 8 pól w które koń moze się poruszyc

    // 1) góra góra lewo
    i = row - 2;
    j = col - 1;
    if(i >= 0 && j >= 0 && (game->getCollection(i, j)->getChessPieceColor() != team) ) {
        location.append(game->getCollection(i, j));
        if(location.last()->getHasChessPiece()){
            location.last()->getBoxGraphics()->setColor(Qt::green);
            boxSetting(location.last());
        }
        else
            location.last()->getBoxGraphics()->setColor(Qt::darkGreen);
    }

    // 2) góra góra prawo
    i = row - 2;
    j = col + 1;
    if(i >= 0 && j <= 7 && (game->getCollection(i, j)->getChessPieceColor() != team) ) {
        location.append(game->getCollection(i, j));
        if(location.last()->getHasChessPiece()){
            location.last()->getBoxGraphics()->setColor(Qt::green);
            boxSetting(location.last());
        }
        else
            location.last()->getBoxGraphics()->setColor(Qt::darkGreen);
    }

    // 3) dół dół lewo
    i = row + 2;
    j = col - 1;
    if(i <= 7 && j >= 0 && (game->getCollection(i, j)->getChessPieceColor() != team) ) {
        location.append(game->getCollection(i, j));
        if(location.last()->getHasChessPiece()){
            location.last()->getBoxGraphics()->setColor(Qt::green);
            boxSetting(location.last());
        }
        else
            location.last()->getBoxGraphics()->setColor(Qt::darkGreen);
    }

    // 4) dół dół prawo
    i = row + 2;
    j = col + 1;
    if(i <= 7 && j <= 7 && (game->getCollection(i, j)->getChessPieceColor() != team) ) {
        location.append(game->getCollection(i, j));
        if(location.last()->getHasChessPiece()){
            location.last()->getBoxGraphics()->setColor(Qt::green);
            boxSetting(location.last());
        }
        else
            location.last()->getBoxGraphics()->setColor(Qt::darkGreen);
    }

    // 5) lewo lewo góra
    i = row - 1;
    j = col - 2;
    if(i >=0 && j >= 0 && (game->getCollection(i, j)->getChessPieceColor() != team) ) {
        location.append(game->getCollection(i, j));
        if(location.last()->getHasChessPiece()){
            location.last()->getBoxGraphics()->setColor(Qt::green);
            boxSetting(location.last());
        }
        else
            location.last()->getBoxGraphics()->setColor(Qt::darkGreen);
    }

    // 6) lewo lewo dół
    i = row + 1;
    j = col - 2;
    if(i <= 7 && j >= 0 && (game->getCollection(i, j)->getChessPieceColor() != team) ) {
        location.append(game->getCollection(i, j));
        if(location.last()->getHasChessPiece()){
            location.last()->getBoxGraphics()->setColor(Qt::green);
            boxSetting(location.last());
        }
        else
            location.last()->getBoxGraphics()->setColor(Qt::darkGreen);
    }

    // 7) prawo prawo góra
    i = row - 1;
    j = col + 2;
    if(i >= 0 && j <= 7 && (game->getCollection(i, j)->getChessPieceColor() != team) ) {
        location.append(game->getCollection(i, j));
        if(location.last()->getHasChessPiece()){
            location.last()->getBoxGraphics()->setColor(Qt::green);
            boxSetting(location.last());
        }
        else
            location.last()->getBoxGraphics()->setColor(Qt::darkGreen);
    }

    // 8) prawo prawo dół
    i = row + 1;
    j = col +  2;
    if(i <= 7 && j <= 7 && (game->getCollection(i, j)->getChessPieceColor() != team) ) {
        location.append(game->getCollection(i, j));
        if(location.last()->getHasChessPiece()){
            location.last()->getBoxGraphics()->setColor(Qt::green);
            boxSetting(location.last());
        }
        else
            location.last()->getBoxGraphics()->setColor(Qt::darkGreen);
    }
}
