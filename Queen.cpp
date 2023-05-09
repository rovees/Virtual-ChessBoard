#include "Queen.h"
#include "Game.h"

extern Game *game;

Queen::Queen(QString team,QGraphicsItem *parent) : Piece(team,parent)
{
    setImage();
}

Queen::~Queen()
{

}

void Queen::setImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/white_queen.png"));
    else
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/black_queen.png"));
}


void Queen::move()
{

}
