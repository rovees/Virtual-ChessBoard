#include "Queen.h"
#include "Game.h"
#include "QueenGraphics.h"

extern Game *game;

Queen::Queen(QString team) : Piece(team) //,parent)
{
    pieceGraphics = new QueenGraphics(nullptr, this);
    // setImage();
}

Queen::~Queen()
{

}

/*
void Queen::setImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/white_queen.png"));
    else
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/black_queen.png"));
}
*/

void Queen::move()
{
    location.clear();
    int row = this->getCurrentBox()->getRowPos();
    int col = this->getCurrentBox()->getColPos();
    QString team = this->getSide();

    // ruch w dół
    for(int i = row - 1, j = col; i >= 0 ; i--) {
        if(game->getCollection(i, j)->getChessPieceColor() == team ) {
            break;
        }
        else
        {
            location.append(game->getCollection(i, j));
            if(boxSetting(location.last()))
                break;
        }
    }

    // ruch w dół
    for(int i = row + 1, j = col; i <= 7 ; i++) {
        if(game->getCollection(i, j)->getChessPieceColor() == team ) {
            break;
        }
        else
        {
            location.append(game->getCollection(i, j));
            if(boxSetting(location.last())){
                break;
            }
        }
    }

    // ruch w lewo
    for(int i = row, j = col - 1; j >= 0 ; j--) {
        if(game->getCollection(i, j)->getChessPieceColor() == team ) {
            break;
        }
        else
        {
            location.append(game->getCollection(i, j));
            if(boxSetting(location.last()))
                break;
        }
    }

    // ruch w prawo
    for(int i = row, j = col + 1; j <= 7 ; j++)
    {
        if(game->getCollection(i, j)->getChessPieceColor() == team ) {
            break;
        }
        else
        {
            location.append(game->getCollection(i, j));
            if(boxSetting(location.last()))
                break;
        }

    }

    // ruch w góre w lewo
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {

        if(game->getCollection(i, j)->getChessPieceColor() == team ) {
            break;

        }
        else
        {
            location.append(game->getCollection(i, j));

            if(boxSetting(location.last()) ){
                break;
            }
        }
    }

    // ruch w góre w prawo
    for(int i = row - 1, j = col + 1; i >= 0 && j <= 7; i--, j++) {
        if(game->getCollection(i, j)->getChessPieceColor() == team ) {
            break;

        }
        else
        {
            location.append(game->getCollection(i, j));
            if(boxSetting(location.last())){
                break;
            }
        }
    }

    // ruch w dół w prawo
    for(int i = row + 1, j = col + 1; i <= 7 && j <= 7; i++ , j++) {
        if(game->getCollection(i, j)->getChessPieceColor() == team ) {
            break;

        }
        else
        {
            location.append(game->getCollection(i, j));
            if(boxSetting(location.last())){
                break;
            }
        }
    }

    // ruch w dół w lewo
    for(int i = row + 1, j = col - 1; i <= 7 && j >= 0; i++, j--) {
        if(game->getCollection(i, j)->getChessPieceColor() == team ) {
            break;

        }
        else
        {
            location.append(game->getCollection(i, j));
            if(boxSetting(location.last())){
                break;
            }

        }
    }

}
