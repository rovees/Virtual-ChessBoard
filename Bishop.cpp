#include "Bishop.h"
#include <QDebug>
#include "Game.h"

extern Game *game;

Bishop::Bishop(QString team,QGraphicsItem *parent) : Piece(team, parent)
{
    setImage();
}

Bishop::~Bishop()
{

}

void Bishop::setImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/white_bishop.png"));
    else
        setPixmap(QPixmap("C:/Users/Radek/Desktop/Projekt_szachy/Szachy/black_bishop.png"));
}

void Bishop::move()
{

}


