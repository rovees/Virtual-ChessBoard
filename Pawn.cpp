#include "Pawn.h"
#include "Game.h"
#include <QDebug>
#include <typeinfo>
#include "King.h"

extern Game * game;

Pawn::Pawn(QString team,QGraphicsItem *parent) : Piece(team,parent)
{
    setImage();
    firstMove = true;
}

Pawn::~Pawn()
{

}

void Pawn::setImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/white_pawn.png"));
    else
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/black_pawn.png"));
}



void Pawn::move()
{


}

