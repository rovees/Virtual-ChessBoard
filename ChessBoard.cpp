#include "ChessSquare.h"
#include "ChessBoard.h"
#include "Game.h"
#include "Queen.h"
#include "Rook.h"
#include "Pawn.h"
#include "King.h"
#include "Knight.h"
#include "Bishop.h"

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
            game->collection[i][j] = box;
            box->rowPos = i;
            box->colPos = j;
            box->setPos(x+SHIFT*j,y+SHIFT*i);
            if((i + j)%2==0)
                box->setOriginalColor(Qt::lightGray);
            else
                box->setOriginalColor(Qt::darkGray);
            game->addToScene(box);



        }
    }

}


void ChessBoard::addChessPiece() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {

            ChessSquare *box = game->collection[i][j];
            if(i < 2) {
                static int k;
                box->placePiece(black[k]);
                game->alivePiece.append(black[k]);
                game->addToScene(black[k++]);
            }
            if(i > 5) {
                static int h;
                box->placePiece(white[h]);
                game->alivePiece.append(white[h]);
                game->addToScene(white[h++]);
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




