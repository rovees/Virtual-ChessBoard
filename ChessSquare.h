#ifndef CHESSSQUARE_H
#define CHESSSQUARE_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>

class Piece;

class ChessSquare : public QGraphicsRectItem
{
public:

    //Constructor
    ChessSquare(QGraphicsItem *parent=0);
    ~ChessSquare();


    //public member function
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    /* ustawienie koloru pola szachowego*/
    void setColor(QColor color);
    /* */
    void placePiece(Piece *piece);


    void resetOriginalColor(); // metoda resetująca kolor pola szachowego na kolor oryginalny
    void setOriginalColor(QColor value);

    // gettery i settery atrybutu hasChessPiece
    bool getHasChessPiece();
    void setHasChessPiece(bool value, Piece *piece = 0);

    void checkForCheck();

    // getter i setter atrybutu chessPieceColor
    QString getChessPieceColor() ;
    void setChessPieceColor(QString value);

    // atrybuty przechowujące informacje o położeniu pola szachowego na szachownicy
    int rowPos;
    int colPos;

    Piece * currentPiece; // wskaźnik na aktualną figurę szachową

private:
    QBrush brush;
    QColor originalColor; // oryginalny kolor pola szachowego
    bool hasChessPiece; // atrybut informujący czy na danym polu szachowym znajduje się jakaś figura
    QString chessPieceColor; // atrybut określający kolor figury znajdującej się na danym polu szachowym

};

#endif // CHESSSQUARE_H
