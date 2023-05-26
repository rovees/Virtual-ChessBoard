#include "ChessSquare.h"
// #include "ChessBoard.h"
#include "Queen.h"
#include "Rook.h"
#include "Pawn.h"
#include "King.h"
#include "Knight.h"
#include "Bishop.h"
#include "Game.h"
#include "GameGraphics.h"


extern Game *game;


ChessBoard::ChessBoard()
{
    setUpBlack();
    setUpWhite();
}

ChessBoard::~ChessBoard()
{

}

void ChessBoard::drawBoxes(int x,int y)
{
    int SHIFT = 0.8*100;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {
            ChessSquare *box = new ChessSquare();
            game->setCollection(i, j, box);
            box->setRowPos(i);
            box->setColPos(j);
            box->getBoxGraphics()->setPos(x+SHIFT*j,y+SHIFT*i);
            if((i + j)%2 == 0)
                box->getBoxGraphics()->setOriginalColor(Qt::lightGray);
            else
                box->getBoxGraphics()->setOriginalColor(Qt::darkGray);
            game->getGameGraphics()->addToScene(box->getBoxGraphics());

        }
    }
}


void ChessBoard::addChessPiece() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {

            ChessSquare *box = game->getCollection(i, j);
            if(i < 2) {
                static int k;
                box->placePiece(black[k]);
                game->getAlivePiece().append(black[k]);
                game->getGameGraphics()->addToScene(black[k++]->getPieceGraphics());
            }
            if(i > 5) {
                static int h;
                box->placePiece(white[h]);
                game->getAlivePiece().append(white[h]);
                game->getGameGraphics()->addToScene(white[h++]->getPieceGraphics());
            }

        }
    }
}

void ChessBoard::setUpWhite()
{
    Piece *piece;
    for(int i = 0; i < 8; i++) {
        piece = new Pawn("WHITE");
        white.append(piece);
    }
    piece = new Rook("WHITE");
    white.append(piece);
    piece = new Knight("WHITE");
    white.append(piece);
    piece = new Bishop("WHITE");
    white.append(piece);
    piece = new Queen("WHITE");
    white.append(piece);
    piece = new King("WHITE");
    white.append(piece);
    piece = new Bishop("WHITE");
    white.append(piece);
    piece = new Knight("WHITE");
    white.append(piece);
    piece = new Rook("WHITE");
    white.append(piece);

}

void ChessBoard::setUpBlack()
{
    Piece *piece;
    piece = new Rook("BLACK");
    black.append(piece);
    piece = new Knight("BLACK");
    black.append(piece);
    piece = new Bishop("BLACK");
    black.append(piece);
    piece = new Queen("BLACK");
    black.append(piece);
    piece = new King("BLACK");
    black.append(piece);
    piece = new Bishop("BLACK");
    black.append(piece);
    piece = new Knight("BLACK");
    black.append(piece);
    piece = new Rook("BLACK");
    black.append(piece);
    for(int i = 0; i < 8; i++) {
        piece = new Pawn("BLACK");
        black.append(piece);
    }
}


void ChessBoard::reset() {
    int k = 0; int h = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {

            ChessSquare *box = game->getCollection(i, j);
            box->setHasChessPiece(false);
            box->setChessPieceColor("NONE");
            box->setCurrentPiece(nullptr);
            if(i < 2) {

                box->placePiece(black[k]);
                black[k]->setIsPlaced(true);
                black[k]->setFirstMove(true);
                game->getAlivePiece().append(black[k++]);

            }
            if(i > 5) {

                box->placePiece(white[h]);
                white[h]->setIsPlaced(true);
                white[h]->setFirstMove(true);
                game->getAlivePiece().append(white[h++]);

            }

        }
    }
    // game->setTurnDisplay("Turn: WHITE");
}
