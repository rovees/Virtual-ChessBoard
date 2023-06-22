#include "King.h"
#include "Game.h"
#include "Pawn.h"
#include "KingGraphics.h"
#include "Rook.h"

extern Game *game;

King::King(QString team) : Piece(team)
{
    pieceGraphics = new KingGraphics(nullptr, this);
    firstMove = true;
}

King::~King()
{
    delete pieceGraphics;
}

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

    // Roszada
    qDebug() << "First move: " << firstMove;
    if (firstMove) {
        ChessSquare* leftRookSquare = game->getCollection(row, 0);
        ChessSquare* rightRookSquare = game->getCollection(row, 7);

        if (leftRookSquare->getHasChessPiece()) {
            Piece* leftRookPiece = leftRookSquare->getCurrentPiece();
            Rook* leftRook = dynamic_cast<Rook*>(leftRookPiece);

            if (leftRook && leftRook->getFirstMove()) {
                // qDebug() << "CASTLE: " << getCanCastle();
                setLongCastling(true);
                for (int i = col - 1; i > 0; i--) {
                    if (game->getCollection(row, i)->getHasChessPiece() || isLocationUnsafe(game->getCollection(row, i))) {
                        setLongCastling(false);
                        break;
                    }
                }
                if (getLongCastling()) {;
                    location.append(leftRookSquare);
                    leftRookSquare->getBoxGraphics()->setColor(Qt::darkGreen);
                }
            }
        }

        if (rightRookSquare->getHasChessPiece()) {
            Piece* rightRookPiece = rightRookSquare->getCurrentPiece();
            Rook* rightRook = dynamic_cast<Rook*>(rightRookPiece);
            if (rightRook && rightRook->getFirstMove()) {
                setShortCastling(true);
                for (int i = col + 1; i < 7; i++) {
                    if (game->getCollection(row, i)->getHasChessPiece() || isLocationUnsafe(game->getCollection(row, i))) {
                        setShortCastling(false);
                        break;
                    }
                }
                if (getShortCastling()) {
                    location.append(rightRookSquare);
                    rightRookSquare->getBoxGraphics()->setColor(Qt::darkGreen);
                }
            }
        }
    }


    qDebug() << firstMove;
    qDebug() << "Long castling: " << longCastling;
    qDebug() << "Short castling: " << shortCastling;
    findUnSafeLocation();

}

void King::setLongCastling(bool value)
{
    longCastling = value;
}

bool King::getLongCastling()
{
    return longCastling;
}

void King::setShortCastling(bool value)
{
    shortCastling = value;
}

bool King::getShortCastling()
{
    return shortCastling;
}



void King::findUnSafeLocation() {

    QList <ChessSquare *> delSquares;

    QList <Piece *> alivePiecesList = game->getAlivePiece();
    for(size_t i = 0, n = alivePiecesList.size(); i < n; i++) {

        if(alivePiecesList[i]->getSide() != this->getSide())
        {
            Pawn *c = dynamic_cast<Pawn *> (alivePiecesList[i]);

                if(c)
                {
                    int PawnRow = c->getCurrentBox()->getRowPos();
                    int PawnCol = c->getCurrentBox()->getColPos();
                    for(size_t k = 0, n = location.size(); k < n; k++) {
                        if(c->getSide() == "WHITE" && (location [k]== game->getCollection(PawnRow-1, PawnCol+1) || location [k] == game->getCollection(PawnRow-1, PawnCol-1)))
                        {
                            location[k]->getBoxGraphics()->setColor(Qt::darkMagenta);
                            delSquares.append(location[k]);
                        }
                        else if (c->getSide() == "BLACK" && (location [k] == game->getCollection(PawnRow+1, PawnCol+1) || location [k]== game->getCollection(PawnRow+1, PawnCol-1)))

                        {
                            location[k]->getBoxGraphics()->setColor(Qt::red);
                            delSquares.append(location[k]);
                        }
                    }

                }

                else
                {
                    QList <ChessSquare *> moveLocationsList = alivePiecesList[i]->moveLocation();

                    for(size_t j = 0, n = moveLocationsList.size(); j < n; j++)
                    {
                        for(size_t k = 0, n = location.size(); k < n; k++)
                        {
                            if(moveLocationsList[j] == location [k] &&  !(dynamic_cast<Pawn *> (alivePiecesList[i])))
                            {
                                if (this->getSide() == "WHITE")
                                {
                                    location[k]->getBoxGraphics()->setColor(Qt::red);
                                    delSquares.append(location[k]);
                                }
                                else if (this->getSide() == "BLACK")
                                {
                                    location[k]->getBoxGraphics()->setColor(Qt::darkMagenta);
                                    delSquares.append(location[k]);
                                }
                            }
                        }
                    }
                }

            }
        }


    for (size_t i = 0, n = delSquares.size(); i < n; i++)
        {
            location.removeOne(delSquares[i]);
        }

}


bool King::isLocationUnsafe(ChessSquare* square)
{
    QList<Piece*> alivePiecesList = game->getAlivePiece();
    for (size_t i = 0, n = alivePiecesList.size(); i < n; i++) {
        if (alivePiecesList[i]->getSide() != this->getSide()) {
            QList<ChessSquare*> moveLocationsList = alivePiecesList[i]->moveLocation();
            for (size_t j = 0, n = moveLocationsList.size(); j < n; j++) {
                if (moveLocationsList[j] == square) {
                    return true;
                }
            }
        }
    }
    return false;
}



