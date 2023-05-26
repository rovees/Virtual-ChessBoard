#ifndef GAMEGRAPHICS_H
#define GAMEGRAPHICS_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QList>

class Game;
class Piece;

class GameGraphics : public QGraphicsView
{
    Q_OBJECT
public:
    GameGraphics(QWidget *parent = nullptr, Game *g = nullptr);

    Game *getGameLogic();
    /* metoda tworząca obszar, w którym będą wyświetlane figury (odpowiedniego koloru), które zostały zbite*/
    void drawDeadHolder(int x, int y, QColor color);
    /* metoda rysująca szachownicę */
    void drawChessBoard();
    /* wyświetlenie zbitych figur białych i czarnych */
    void displayDeadWhite();
    void displayDeadBlack();
    /* metoda umieszczająca zbite figury do odpowiedniego obszaru ich przechowywania (w zależności od koloru figury) c*/
    void placeInDeadPlace(Piece *piece);
    void addToScene(QGraphicsItem *item);
    void removeFromScene(QGraphicsItem *item);
    QGraphicsTextItem *getCheck();
    /* metoda zmieniająca wartość atrybutu tura w zależności jaka jest aktualna jego wartość */
    void changeTurn();
    void displayMainMenu();
    void setTurnDisplay(QString value);
    void removeAll();
public slots:
    void start();
private:
    Game *gameLogic;
    QGraphicsScene *gameScene;
    QGraphicsRectItem *deadHolder; // wskaźnik na obiekt klasy QGraphicsRectItem, który reprezentuje pole do wyświetlania zbitych figur
    QGraphicsTextItem *check; // wskaźnik na pole tekstowe do wyświetlania informacji o szachu
    QList <QGraphicsItem *> listG; // lista przechowująca wskaźniki na obiekty QGraphicsItem reprezentujące ekran menu głównego
    QGraphicsTextItem *turnDisplay; // wskaźnik na obiekt klasy QGraphicsRectItem, który reprezentuje pole, w którym wyświetla się aktualna tura
};

#endif // GAMEGRAPHICS_H
