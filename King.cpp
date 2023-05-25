#include "King.h"
#include "Game.h"
#include "Pawn.h"
#include "KingGraphics.h"


extern Game *game;

King::King(QString team) : Piece(team) // ,parent)
{
    pieceGraphics = new KingGraphics(nullptr, this);
    // setImage();
}

King::~King()
{

}

/*
void King::setImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap("C:/Users/Radek/Documents/SZASZKI/white_king.png"));
    else
        setPixmap(QPixmap("C:/Users/Radek/Documents/SZASZKI/black_king.png"));
}
*/

void King::move()
{

    location.clear();
    int row = this->getCurrentBox()->getRowPos();
    int col = this->getCurrentBox()->getColPos();
    QString team = this->getSide();

    // góra lewo
    if(col > 0 && row > 0 && !(game->getCollection(row-1, col-1)->getChessPieceColor() == team)) {
        location.append(game->getCollection(row-1, col-1));
        game->getCollection(row-1, col-1)->getBoxGraphics()->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->getBoxGraphics()->setColor(Qt::green);
        }
    }

    // góra prawo
    if(col < 7 && row > 0 && !(game->getCollection(row-1, col+1)->getChessPieceColor() == team)) {
        location.append(game->getCollection(row-1, col+1));
        game->getCollection(row-1, col+1)->getBoxGraphics()->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->getBoxGraphics()->setColor(Qt::green);
        }
    }

    // góra
    if(row > 0 && !(game->getCollection(row-1, col)->getChessPieceColor() == team)) {
        location.append(game->getCollection(row-1, col));
        game->getCollection(row-1, col)->getBoxGraphics()->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->getBoxGraphics()->setColor(Qt::green);
        }
    }

    // dół
    if(row < 7 && !(game->getCollection(row+1, col)->getChessPieceColor() == team)) {
        location.append(game->getCollection(row+1, col));
        game->getCollection(row+1, col)->getBoxGraphics()->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->getBoxGraphics()->setColor(Qt::green);
        }
    }

    // lewo
    if(col > 0 && !(game->getCollection(row, col-1)->getChessPieceColor() == team)) {
        location.append(game->getCollection(row, col-1));
        game->getCollection(row, col-1)->getBoxGraphics()->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->getBoxGraphics()->setColor(Qt::green);
        }
    }

    // prawo
    if(col < 7 && !(game->getCollection(row, col+1)->getChessPieceColor() == team)) {
        location.append(game->getCollection(row, col+1));
        game->getCollection(row, col+1)->getBoxGraphics()->setColor(Qt::darkGreen);

        if(location.last()->getHasChessPiece()){
            location.last()->getBoxGraphics()->setColor(Qt::green);
        }
    }

    // dół lewo
    if(col > 0 && row < 7  && !(game->getCollection(row+1, col-1)->getChessPieceColor() == team)) {
        location.append(game->getCollection(row+1, col-1));
        game->getCollection(row+1, col-1)->getBoxGraphics()->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->getBoxGraphics()->setColor(Qt::green);
        }
    }

    // dół prawo
    if(col < 7 && row < 7 && !(game->getCollection(row+1, col+1)->getChessPieceColor() == team)) {
        location.append(game->getCollection(row+1, col+1));
        game->getCollection(row+1, col+1)->getBoxGraphics()->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->getBoxGraphics()->setColor(Qt::green);
        }
    }


    findUnSafeLocation();


}


void King::findUnSafeLocation() {
    QList <Piece *> pList = game->getAlivePiece();
    for(size_t i = 0,n = pList.size(); i < n; i++) {

        if(pList[i]->getSide() != this->getSide())
        {
            QList <ChessSquare *> bList = pList[i]->moveLocation();

            for(size_t j = 0, n = bList.size(); j < n; j++) {
                Pawn *c = dynamic_cast<Pawn *> (pList[i]) ;
                if(c)
                {
                    continue;

                    int PawnRow = c->getCurrentBox()->getRowPos();
                    int PawnCol = c->getCurrentBox()->getColPos();
                    for(size_t k = 0, n = location.size(); k < n; k++) {
                        if((game->getCollection(PawnRow-1, PawnCol+1) == location [k] || game->getCollection(PawnRow-1, PawnCol-1) == location [k]) ||
                            (game->getCollection(PawnRow-1, PawnCol+1) == location [k] && game->getCollection(PawnRow-1, PawnCol-1) == location [k])) {
                            qDebug() << "getCollection: " << game->getCollection(PawnRow-1, PawnCol+1);
                            qDebug() << "location[k]: " << location [k];
                            location[k]->getBoxGraphics()->setColor(Qt::red);
                            // location.removeAt(location.indexOf(location[k]));

                }
                    }
                }

                else
                {
                    for(size_t k = 0, n = location.size(); k < n; k++) {
                        if(bList[j] == location [k]) {
                            location[k]->getBoxGraphics()->setColor(Qt::red);
                            // location.removeAt(location.indexOf(location[k]));
                        }
                    }
                }

            }
        }
    }
}

/*
void King::findUnSafeLocation() {
   QList <Piece *> pList = game->getAlivePiece();
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
*/
