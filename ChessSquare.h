#ifndef CHESSSQUARE_H
#define CHESSSQUARE_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>

class Piece;
class ChessSquareGraphicsItem;

class ChessSquare // : public QGraphicsRectItem
{
public:

    ChessSquare();
    ~ChessSquare();


    // zdarzenie kliknięcia myszą
    // void mousePressEvent(QGraphicsSceneMouseEvent *event);

    /* ustawienie koloru pola szachowego*/
    // void setColor(QColor color);
    /* */
    void placePiece(Piece *piece);


    // void resetOriginalColor(); // metoda resetująca kolor pola szachowego na kolor oryginalny
    // void setOriginalColor(QColor value);

    // gettery i settery odpowiednich atrybutów
    bool getHasChessPiece();
    void setHasChessPiece(bool value, Piece *piece = 0);

    int getRowPos();
    void setRowPos(int row);

    int getColPos();
    void setColPos(int col);

    Piece *getCurrentPiece();
    void setCurrentPiece(Piece *p);

    QString getChessPieceColor() ;
    void setChessPieceColor(QString value);
    ChessSquareGraphicsItem *getBoxGraphics();
    void setBoxGraphics(ChessSquareGraphicsItem *boxG);

    // sprawdzanie czy jest szach
    void checkForCheck();
    void gameOver();
    // int rowPos;
    // int colPos;

    // Piece * currentPiece; // wskaźnik na aktualną figurę szachową znajdującą się na danym polu szachowym

private:
    // QBrush brush;
    // QColor originalColor; // oryginalny kolor pola szachowego
    // atrybuty przechowujące informacje o położeniu pola szachowego na szachownicy
    ChessSquareGraphicsItem *boxGraphics; // wskaźnik na obiekt graficzny reprezentujący pojedyncze pole szachowe
    int rowPos;
    int colPos;
    Piece * currentPiece; // wskaźnik na aktualną figurę szachową znajdującą się na danym polu szachowym
    bool hasChessPiece; // atrybut informujący czy na danym polu szachowym znajduje się jakaś figura
    QString chessPieceColor; // atrybut określający kolor figury znajdującej się na danym polu szachowym

};

#endif // CHESSSQUARE_H
