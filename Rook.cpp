#include "Rook.h"
#include "Game.h"

extern Game *game;

Rook::Rook(QString team,QGraphicsItem *parent) : Piece(team,parent)
{
    setImage();
}

Rook::~Rook()
{

}

void Rook::setImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/white_rook.png"));
    else
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/black_rook.png"));
}

void Rook::move()
{

}
