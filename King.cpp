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
        boxSetting(location.last());
    }

    // góra prawo
    if(col < 7 && row > 0 && !(game->getCollection(row-1, col+1)->getChessPieceColor() == team)) {
        location.append(game->getCollection(row-1, col+1));
        boxSetting(location.last());
    }

    // góra
    if(row > 0 && !(game->getCollection(row-1, col)->getChessPieceColor() == team)) {
        location.append(game->getCollection(row-1, col));
        boxSetting(location.last());
    }

    // dół
    if(row < 7 && !(game->getCollection(row+1, col)->getChessPieceColor() == team)) {
        location.append(game->getCollection(row+1, col));
        boxSetting(location.last());
    }

    // lewo
    if(col > 0 && !(game->getCollection(row, col-1)->getChessPieceColor() == team)) {
        location.append(game->getCollection(row, col-1));
        boxSetting(location.last());
    }

    // prawo
    if(col < 7 && !(game->getCollection(row, col+1)->getChessPieceColor() == team)) {
        location.append(game->getCollection(row, col+1));
        boxSetting(location.last());
    }

    // dół lewo
    if(col > 0 && row < 7  && !(game->getCollection(row+1, col-1)->getChessPieceColor() == team)) {
        location.append(game->getCollection(row+1, col-1));
        boxSetting(location.last());
    }

    // dół prawo
    if(col < 7 && row < 7 && !(game->getCollection(row+1, col+1)->getChessPieceColor() == team)) {
        location.append(game->getCollection(row+1, col+1));
        boxSetting(location.last());
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
                setLongCastling(true);
                for (int i = col - 1; i > 0; i--) {
                    if (game->getCollection(row, i)->getHasChessPiece() || isLocationUnsafe(game->getCollection(row, col - 2)) || game->getIsCheck()) {
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
                    if (game->getCollection(row, i)->getHasChessPiece() || isLocationUnsafe(game->getCollection(row, col + 2)) || game->getIsCheck()) {
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

    QList <Piece *> alivePiecesList = game->getAlivePiece();
    QList <ChessSquare *> unsafeLocations;

    for(size_t i = 0, n1 = alivePiecesList.size(); i < n1; i++) {

        if(alivePiecesList[i]->getSide() != this->getSide())
        {
            Pawn *pawn = dynamic_cast<Pawn *> (alivePiecesList[i]);

                if(pawn)
                {
                    int PawnRow = pawn->getCurrentBox()->getRowPos();
                    int PawnCol = pawn->getCurrentBox()->getColPos();
                    for(size_t k = 0, n2 = location.size(); k < n2; k++) {
                    if(pawn->getSide() == "WHITE" && ((location [k] == game->getCollection(PawnRow-1, PawnCol+1) && PawnCol+1 <= 7)
                        || (location [k] == game->getCollection(PawnRow-1, PawnCol-1) && PawnCol-1 >= 0)))
                        {
                            location[k]->getBoxGraphics()->setColor(Qt::darkMagenta);
                            unsafeLocations.append(location[k]);
                        }
                    else if (pawn->getSide() == "BLACK" && ((location [k] == game->getCollection(PawnRow+1, PawnCol+1) && PawnCol+1 <= 7)
                        || (location [k]== game->getCollection(PawnRow+1, PawnCol-1) && PawnCol-1 >= 0)))
                        {
                            location[k]->getBoxGraphics()->setColor(Qt::red);
                            unsafeLocations.append(location[k]);
                        }
                    }
                }

                else
                {
                    QList <ChessSquare *> moveLocationsList = alivePiecesList[i]->moveLocation();

                    for(size_t j = 0, n3 = moveLocationsList.size(); j < n3; j++)
                    {
                        for(size_t k = 0, n4 = location.size(); k < n4; k++)
                        {
                            if(moveLocationsList[j] == location[k])
                            {
                                if (this->getSide() == "WHITE")
                                {
                                    location[k]->getBoxGraphics()->setColor(Qt::red);
                                    unsafeLocations.append(location[k]);

                                }
                                else if (this->getSide() == "BLACK")
                                {
                                    location[k]->getBoxGraphics()->setColor(Qt::darkMagenta);
                                    unsafeLocations.append(location[k]);

                                }
                            }
                        }
                    }
                }
            }
        }

    for (size_t i = 0, n5 = unsafeLocations.size(); i < n5; i++)
        {
            location.removeOne(unsafeLocations[i]);
        }
    }


bool King::isLocationUnsafe(ChessSquare* square)
{
    QList<Piece*> alivePiecesList = game->getAlivePiece();
    for (size_t i = 0, n1 = alivePiecesList.size(); i < n1; i++) {
        if (alivePiecesList[i]->getSide() != this->getSide()) {
            QList<ChessSquare*> moveLocationsList = alivePiecesList[i]->moveLocation();
            for (size_t j = 0, n2 = moveLocationsList.size(); j < n2; j++) {
                if (moveLocationsList[j] == square) {
                    return true;
                }
            }
        }
    }
    return false;
}



