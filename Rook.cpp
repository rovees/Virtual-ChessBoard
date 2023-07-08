#include "Rook.h"
#include "Game.h"
#include "RookGraphics.h"


extern Game *game;

Rook::Rook(QString team) : Piece(team)
{
    pieceGraphics = new RookGraphics(nullptr, this);
    firstMove = true;
}

Rook::~Rook()
{
    delete pieceGraphics;
}

void Rook::move()
{
    location.clear();
    int row = this->getCurrentBox()->getRowPos();
    int col = this->getCurrentBox()->getColPos();
    QString team = this->getSide();

    // ruch w dół
    for(int i = row - 1, j = col; i >= 0; i--) {
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
    for(int i = row + 1, j = col; i <= 7; i++) {
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
    for(int i = row, j = col - 1; j >= 0; j--) {
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
    for(int i = row, j = col + 1; j <= 7; j++)
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
    qDebug() << firstMove;
}
