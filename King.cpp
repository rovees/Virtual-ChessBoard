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
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/white_king.png"));
    else
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/black_king.png"));
}


void King::move()
{


}

