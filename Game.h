#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <ChessBoard.h>
#include "Piece.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    //Constructors
    Game(QWidget *parent = 0);

    /* metoda tworząca obszar, w którym będą wyświetlane figury (odpowiedniego kolory), które zostały zbite*/
    void drawDeadHolder(int x, int y, QColor color);
    /* metoda rysująca szachownicę */
    void drawChessBoard();
    /* wyświetlenie zbitych figur białych i czarnych */
    void displayDeadWhite();
    void displayDeadBlack();
    /* metoda umieszczająca zbite figury do odpowiedniego obszaru ich przechowywania (w zależności od koloru figury) c*/
    void placeInDeadPlace(Piece *piece);

    /* metoda dodająca elementy graficzne do okna aplikacji */
    void addToScene(QGraphicsItem *item);
    /* metoda usuwająca elementy graficzne z okna aplikacji */
    void removeFromScene(QGraphicsItem *item);

    // Wskaźnik na figurę, którą chcemy przesunąć
    Piece *pieceToMove;

    // getter i setter atrybutu turn
    QString getTurn() ;
    void setTurn( QString value);

    /* metoda zmieniająca wartość atrybutu tura w zależności jaka jest aktualna jego wartość */
    void changeTurn();


    ChessSquare *collection[8][8]; // tablica reprezentująca pola szachowe
    QGraphicsTextItem *check;
    QList <Piece *> alivePiece; // lista przechowująca figury znajdujące się na szachownicy
    void displayMainMenu();

    /* */
    void gameOver();
    /* usunięcie wszystkich elementów */
    void removeAll();
    /* wyświetlenie aktualnej tury */
    void setTurnDisplay(QString value);
public slots:
    void start();
private:
    QGraphicsScene *gameScene;
    // Listy przechowujące zbite figury (białe lub czarne)
    QList <Piece *> whiteDead;
    QList <Piece *> blackDead;
    QGraphicsRectItem *deadHolder; // wskaźnik na obiekt klasy QGraphicsRectItem, który reprezentuje pole do wyświetlania zbitych figur
    QString turn; // atrybut przechowujący aktualną turę
    ChessBoard *chess; // wskaźnik na obiekt klasy ChessBoard, który reprezentuje szachownicę
    QList <QGraphicsItem *> listG; // lista przechowująca wskaźniki na obiekty QGraphicsItem reprezentujące ekran menu głównego
    QGraphicsTextItem *turnDisplay; // wskaźnik na obiekt klasy QGraphicsRectItem, który reprezentuje pole, w którym wyświetla się aktualna tura

};

#endif // GAME_H
