#ifndef PIECE_H
#define PIECE_H

#include <QGraphicsPixmapItem>
#include "ChessSquare.h"
#include <QGraphicsSceneMouseEvent>

class ChessSquare;

class Piece:public QGraphicsPixmapItem
{
public:
    Piece(QString team = "", QGraphicsItem *parent = 0);
    ~Piece();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setCurrentBox(ChessSquare *box);

    ChessSquare *getCurrentBox(); // położenie figury na szachownicy odpowiada położeniu pola, na którym stoi w danym momencie figura

    QString getSide(); // pobranie strony (koloru: biały lub czarny) dla danej figury
    void setSide(QString value);
    virtual void setImage() = 0;

    bool getIsPlaced(); // pobranie informacji czy figura została ustawiona w danym polu
    void setIsPlaced(bool value); // ustawienie wartości atrybutu isPlaced

    QList <ChessSquare *> moveLocation();
    virtual void move() = 0; // funkcja wirtualna realizująca odpowiedni ruch w zależności od danej figury szachowej
    void decolor();

    bool firstMove; // zmienna informująca czy aktualnie jest pierwszy ruch w partii czy nie

    bool boxSetting(ChessSquare *box); // ustawienie figury na polu wynikającym z ruchu w zależności czy to pole jest puste czy nie

protected:
    ChessSquare *currentBox;
    QString side; // zmienna przechowująca stronę (kolor: biały lub czarny)
    bool isPlaced; // zmienna informująca czy figura została ustawiona na danym pol
    QList <ChessSquare *> location; // lista przechowująca wskaźnik na aktualne położenie (pole szachowe) figury i położenie, do którego chcemy się ruszyć daną figurą

};

#endif // PIECE_H

