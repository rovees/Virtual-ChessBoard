#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <ChessBoard.h>

const static int N = 8;

class GameGraphics;
class Piece;


/**
 * @brief Klasa reprezentująca grę szachową.
 */
class Game
{

public:

    /**
     * @brief Konstruktor klasy Game.
     */
    Game();

    /**
     * @brief Destruktor klasy Game.
     */
    ~Game();


    /**
     * @brief Zwraca wskaźnik na obiekt graficzny reprezentujący grę.
     * @return Wskaźnik na obiekt GameGraphics.
     */
    GameGraphics *getGameGraphics();

    /**
     * @brief Ustawia wskaźnik na obiekt graficzny reprezentujący grę.
     * \param gameG Wskaźnik na obiekt GameGraphics.
     */
    void setGameGraphics(GameGraphics *gameG);

    /**
     * @brief Zwraca listę zbitych białych figur.
     * @return Referencja do listy wskaźników na figury (białe).
     */
    QList <Piece *>& getWhiteDead();

    /**
     * @brief Zwraca listę zbitych czarnych figur.
     * @return Referencja do listy wskaźników na figury (czarne).
     */
    QList <Piece *>& getBlackDead();

    /**
     * @brief Zwraca aktualną turę.
     * @return Aktualna tura (kolor: biały lub czarny).
     */
    QString getTurn();

    /**
     * @brief Ustawia aktualną turę.
     * \param value Aktualna tura (kolor: biały lub czarny).
     */
    void setTurn(QString value);

    /**
     * @brief Zwraca listę żywych figur.
     * @return Referencja do listy wskaźników na figury (żywe).
     */
    QList <Piece *>& getAlivePiece();

    /**
     * @brief Ustawia figurę do przesunięcia.
     * \param p Wskaźnik na figurę.
     */
    void setPieceToMove(Piece *p);

    /**
     * @brief Zwraca wskaźnik na figurę do przesunięcia.
     * @return Wskaźnik na figurę.
     */
    Piece *getPieceToMove();

    /**
     * @brief Ustawia kolekcję na określonym polu.
     * \param x Indeks kolumny pola.
     * \param y Indeks wiersza pola.
     * \param box Wskaźnik na pole szachowe.
     */
    void setCollection(int x, int y, ChessSquare *box);

    /**
     * @brief Zwraca pole kolekcji o określonych indeksach.
     * \param x Indeks kolumny pola.
     * \param y Indeks wiersza pola.
     * @return Wskaźnik na pole szachowe.
     */
    ChessSquare *getCollection(int x, int y);

    /**
     * @brief Zwraca wskaźnik na obiekt reprezentujący szachownicę.
     * @return Wskaźnik na obiekt ChessBoard.
     */
    ChessBoard *getChess();

    /**
     * @brief Sprawdza, czy pole jest w szachu.
     */
    bool checkForCheck();

    /**
     * @brief Pobiera wartość flagi informującej czy jest szach.
     * @return Wartość logiczna, czy jest szach.
     */
    bool getIsCheck();

    /**
     * @brief Ustawia wartość flagi informującej czy jest szach.
     * \param val Wartość logiczna określająca, czy jest szach.
     */
    void setIsCheck(bool val);

    /**
     * @brief Kończy grę.
     */
    void gameOver();

private:

    GameGraphics *gameGraphics; /**< Wskaźnik na obiekt graficzny reprezentujący grę. */
    QList <Piece *> whiteDead; /**< Lista zbitych białych figur. */
    QList <Piece *> blackDead; /**< Lista zbitych czarnych figur. */
    QString turn; /**< Aktualna tura (kolor: biały lub czarny). */
    Piece *pieceToMove; /**< Wskaźnik na figurę do przesunięcia. */
    QList <Piece *> alivePiece; /**< Lista żywych figur. */
    ChessSquare *collection[N][N]; /**< Tablica reprezentująca pola szachowe. */
    ChessBoard *chess; /**< Wskaźnik na obiekt reprezentujący szachownicę. */
    bool isCheck; /**< Flaga informująca, czy jest szach. */

};

#endif // GAME_H
