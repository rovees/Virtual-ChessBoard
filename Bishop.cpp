#include "Bishop.h"
#include <QDebug>
#include "Game.h"
#include "BishopGraphics.h"


extern Game *game;

Bishop::Bishop(QString team) : Piece(team) //,QGraphicsItem *parent) : Piece(team, parent)
{
    pieceGraphics = new BishopGraphics(nullptr, this);
    // pieceGraphics->setChessPiece(this);
    // this->pieceGraphics->setImage();
    // setImage();
}

Bishop::~Bishop()
{

}

/*
void Bishop::setImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/white_bishop.png"));
    else
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/black_bishop.png"));
}
*/

void Bishop::move()
{
    location.clear();
    int row = this->getCurrentBox()->getRowPos();
    int col = this->getCurrentBox()->getColPos();
    QString team = this->getSide();

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
    for(int i = row - 1,j = col + 1; i >= 0 && j <= 7; i--,j++) {
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
    for(int i = row + 1, j = col + 1; i <= 7 && j <= 7; i++ ,j++) {
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

