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


