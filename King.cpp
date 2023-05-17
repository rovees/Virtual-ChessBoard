#include "King.h"
#include "Game.h"
#include "Pawn.h"

extern Game *game;

King::King(QString team,QGraphicsItem *parent) : Piece(team,parent)
{
    setImage();
}

King::~King()
{

}

void King::setImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap("C:/Users/Radek/Documents/SZASZKI/white_king.png"));
    else
        setPixmap(QPixmap("C:/Users/Radek/Documents/SZASZKI/black_king.png"));
}


void King::move()
{

    location.clear();
    int row = this->getCurrentBox()->rowPos;
    int col = this->getCurrentBox()->colPos;
    QString team = this->getSide();

    // góra lewo
    if(col > 0 && row > 0 && !(game->collection[row-1][col-1]->getChessPieceColor() == team)) {
        location.append(game->collection[row-1][col-1]);
        game->collection[row-1][col-1]->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->setColor(Qt::green);
        }
    }

    // góra prawo
    if(col < 7 && row > 0 && !(game->collection[row-1][col+1]->getChessPieceColor() == team)) {
        location.append(game->collection[row-1][col+1]);
        game->collection[row-1][col+1]->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->setColor(Qt::green);
        }
    }

    // w górę
    if(row>0 && !(game->collection[row-1][col]->getChessPieceColor() == team)) {
        location.append(game->collection[row-1][col]);
        game->collection[row-1][col]->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->setColor(Qt::green);
        }
    }

    // w dół
    if(row<7 && !(game->collection[row+1][col]->getChessPieceColor() == team)) {
        location.append(game->collection[row+1][col]);
        game->collection[row+1][col]->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->setColor(Qt::green);
        }
    }

    // lewo
    if(col>0 && !(game->collection[row][col-1]->getChessPieceColor() == team)) {
        location.append(game->collection[row][col-1]);
        game->collection[row][col-1]->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->setColor(Qt::green);
        }
    }

    // prawo
    if(col<7 && !(game->collection[row][col+1]->getChessPieceColor() == team)) {
        location.append(game->collection[row][col+1]);
        game->collection[row][col+1]->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->setColor(Qt::green);
        }
    }

    // dół lewo
    if(col > 0 && row < 7  && !(game->collection[row+1][col-1]->getChessPieceColor() == team)) {
        location.append(game->collection[row+1][col-1]);
        game->collection[row+1][col-1]->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->setColor(Qt::green);
        }
    }

    // dół prawo
    if(col < 7 && row < 7 && !(game->collection[row+1][col+1]->getChessPieceColor() == team)) {
        location.append(game->collection[row+1][col+1]);
        game->collection[row+1][col+1]->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->setColor(Qt::green);
        }
    }

   findUnSafeLocation();


}



void King::findUnSafeLocation() {
   QList <Piece *> pList = game->alivePiece;
   for(size_t i = 0,n = pList.size(); i < n; i++) {

        if(pList[i]->getSide() != this->getSide())
        {
            QList <ChessSquare *> bList = pList[i]->moveLocation();

            for(size_t j = 0, n = bList.size(); j < n; j++) {
                Pawn *c = dynamic_cast<Pawn *> (pList[i]) ;
                if(c)
                    continue;
                for(size_t k = 0, n = location.size(); k < n; k++) {
                    if(bList[j] == location [k]) {
                        location[k]->setColor(Qt::red);
                        // location.removeAt(location.indexOf(location[k]));
                    }
                }
            }
        }
   }
}

