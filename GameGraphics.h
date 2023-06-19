#ifndef GAMEGRAPHICS_H
#define GAMEGRAPHICS_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QList>

class Game;
class Piece;

/**
 * @brief Klasa reprezentująca grafikę gry szachowej.
 */
class GameGraphics : public QGraphicsView
{
    Q_OBJECT
public:

    /**
     * @brief Konstruktor klasy GameGraphics.
     * \param parent Wskaźnik na obiekt rodzica (QWidget).
     * \param g Wskaźnik na obiekt gry (Game).
     */
    GameGraphics(QWidget *parent = nullptr, Game *g = nullptr);

    /**
     * @brief Zwraca wskaźnik na obiekt logiki gry.
     * @return Wskaźnik na obiekt Game.
     */
    Game *getGameLogic();

    /**
     * @brief Zwraca wskaźnik na scenę gry.
     * @return Wskaźnik na obiekt QGraphicsScene.
     */
    QGraphicsScene *getGameScene();

    /**
     * @brief Tworzy obszar, w którym będą wyświetlane zbite figury odpowiedniego koloru.
     * \param x Współrzędna x obszaru.
     * \param y Współrzędna y obszaru.
     * \param color Kolor obszaru.
     */
    void drawDeadHolder(int x, int y, QColor color);

    /**
     * @brief Rysuje szachownicę.
     */
    void drawChessBoard();

    /**
     * @brief Wyświetla zbite figury białe.
     */
    void displayDeadWhite();

    /**
     * @brief Wyświetla zbite figury czarne.
     */
    void displayDeadBlack();

    /**
     * @brief Umieszcza zbite figury w odpowiednim obszarze przechowywania (w zależności od koloru figury).
     * \param piece Wskaźnik na figurę.
     */
    void placeInDeadPlace(Piece *piece);

    /**
     * @brief Dodaje element do sceny.
     * \param item Wskaźnik na obiekt QGraphicsItem.
     */
    void addToScene(QGraphicsItem *item);

    /**
     * @brief Usuwa element ze sceny.
     * \param item Wskaźnik na obiekt QGraphicsItem.
     */
    void removeFromScene(QGraphicsItem *item);

    /**
     * @brief Zwraca wskaźnik na pole tekstowe wyświetlające informację o szachu.
     * @return Wskaźnik na obiekt QGraphicsTextItem.
     */
    QGraphicsTextItem *getCheck();

    /**
     * @brief Zmienia wartość tury w zależności od aktualnej wartości.
     */
    void changeTurn();

    /**
     * @brief Wyświetla menu główne.
     */
    void displayMainMenu();

    /**
     * @brief Ustawia wartość wyświetlaną dla tury.
     * \param value Aktualna tura (kolor: biały lub czarny).
     */
    void setTurnDisplay(QString value);

    /**
     * @brief Usuwa wszystkie elementy ze sceny.
     */
    void removeAll();

    /**
     * @brief Ustawia zwycięzcę gry.
     * \param winnerColor Kolor zwycięzcy (biały lub czarny).
     */
    void setWinner(QString winnerColor);

    /**
     * @brief Zwraca informację o zwycięzcy gry.
     * @return Kolor zwycięzcy (biały lub czarny).
     */
    QString getWinner();

    /**
     * @brief Wyświetla informację o zwycięzcy gry.
     * \param winColor Kolor zwycięzcy (biały lub czarny).
     */
    void displayWinner(QString winColor);

public slots:

    /**
     * @brief Slot uruchamiający grę.
     */
    void start();

private:

    Game *gameLogic; /**< Wskaźnik na obiekt logiki gry. */
    QGraphicsScene *gameScene; /**< Wskaźnik na scenę gry. */
    QGraphicsRectItem *deadHolder; /**< Wskaźnik na obiekt reprezentujący pole do wyświetlania zbitych figur. */
    QGraphicsTextItem *check; /**< Wskaźnik na pole tekstowe wyświetlające informację o szachu. */
    QList <QGraphicsItem *> listGraphicsItems; /**< Lista przechowująca wskaźniki na obiekty QGraphicsItem reprezentujące ekran menu głównego. */
    QGraphicsTextItem *turnDisplay; /**< Wskaźnik na obiekt reprezentujący pole, w którym wyświetla się aktualna tura. */
    QString winner; /**< Informacja o zwycięzcy gry (kolor: biały lub czarny). */

};

#endif // GAMEGRAPHICS_H
