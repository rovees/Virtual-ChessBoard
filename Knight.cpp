#include "Knight.h"
#include "Game.h"

extern Game *game;

Knight::Knight(QString team,QGraphicsItem *parent) : Piece(team,parent)
{
    setImage();
}

Knight::~Knight()
{

}

void Knight::setImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/white_knight.png"));
    else
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/black_knight.png"));
}



void Knight::move()
{


}
