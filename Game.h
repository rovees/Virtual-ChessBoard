#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <ChessBoard.h>
// #include "Piece.h"
// #include "GameGraphics.h"

// class Game;

const int N = 8;

class GameGraphics;
class Piece;


class Game
{

public:

    Game();
    // Game(QWidget *parent = nullptr);
    // ~Game();
    /* metoda tworząca obszar, w którym będą wyświetlane figury (odpowiedniego koloru), które zostały zbite*/
    // void drawDeadHolder(int x, int y, QColor color);
    /* metoda rysująca szachownicę */
    // void drawChessBoard();
    /* wyświetlenie zbitych figur białych i czarnych */
    //void displayDeadWhite();
    //void displayDeadBlack();
    /* metoda umieszczająca zbite figury do odpowiedniego obszaru ich przechowywania (w zależności od koloru figury) c*/
    // void placeInDeadPlace(Piece *piece);

    /* metoda dodająca elementy graficzne do okna aplikacji */
    // void addToScene(QGraphicsItem *item);
    /* metoda usuwająca elementy graficzne z okna aplikacji */
    // void removeFromScene(QGraphicsItem *item);

    // Wskaźnik na figurę, którą chcemy przesunąć
    // Piece *pieceToMove;

    // gettery i settey odpowiednich atrybutów

    GameGraphics *getGameGraphics();
    void setGameGraphics(GameGraphics *gameG);

    QList <Piece *>& getWhiteDead();

    // void setWhiteDead
    QList <Piece *>& getBlackDead();

    QString getTurn() ;
    void setTurn(QString value);

    // QGraphicsTextItem *getCheck();

    QList <Piece *>& getAlivePiece(); // getter listy żywych figur (chcemy zwracać oryginalną listę, dlatego zwracamy referencję)

    void setPieceToMove(Piece *p);
    Piece *getPieceToMove();

    void setCollection(int x, int y, ChessSquare *box);
    ChessSquare *getCollection(int x, int y);

    ChessBoard *getChess();
    /* metoda zmieniająca wartość atrybutu tura w zależności jaka jest aktualna jego wartość */
    // void changeTurn();


    // ChessSquare *collection[8][8]; // tablica 8x8 reprezentująca pola szachowe
    // QGraphicsTextItem *check;
    // QList <Piece *> alivePiece; // lista przechowująca figury znajdujące się na szachownicy
    // void displayMainMenu();

    /* */
    void gameOver();
    /* usunięcie wszystkich elementów graficznych */
    // void removeAll();
    /* wyświetlenie aktualnej tury */
    // void setTurnDisplay(QString value);
private:
    // QGraphicsScene *gameScene;
    // Listy przechowujące zbite figury (białe lub czarne)
    GameGraphics *gameGraphics;
    QList <Piece *> whiteDead;
    QList <Piece *> blackDead;
    // QGraphicsRectItem *deadHolder; // wskaźnik na obiekt klasy QGraphicsRectItem, który reprezentuje pole do wyświetlania zbitych figur
    QString turn; // atrybut przechowujący aktualną turę
    Piece *pieceToMove; // Wskaźnik na figurę, którą chcemy przesunąć
    // QGraphicsTextItem *check; // wskaźnik na pole tekstowe do wyświetlania informacji o szachu
    QList <Piece *> alivePiece; // lista przechowująca figury znajdujące się na szachownicy
    ChessSquare *collection[N][N]; // tablica reprezentująca pola szachowe
    ChessBoard *chess; // wskaźnik na obiekt klasy ChessBoard, który reprezentuje szachownicę
    // QList <QGraphicsItem *> listG; // lista przechowująca wskaźniki na obiekty QGraphicsItem reprezentujące ekran menu głównego
    // QGraphicsTextItem *turnDisplay; // wskaźnik na obiekt klasy QGraphicsRectItem, który reprezentuje pole, w którym wyświetla się aktualna tura

};

#endif // GAME_H
