#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <ChessBoard.h>

const static int N = 8;

class GameGraphics;
class Piece;
class Pawn;

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


    /**
     * @brief pobiera liczbę wykonanych ruchów
     * @return zwraca liczbę wykonanych ruchów
     */
    int getMoveCounter();

    /**
     * @brief ustawia liczbe ruchów
     * @param value Wartość do ustawienia licznika ruchów
     */
    void setMoveCounter(int value);

    /**
     * @brief inkrementuje licznik ruchów o 1
     */
    void incrementMoveCounter();

    /**
     * @brief obsługuje wykonanie roszady
     * @param chessBoxGraphics wskaźnik na element graficzny odpowiadający polu szachowemu na które klikamy
     */
    void performCastling(ChessSquareGraphicsItem *chessBoxGraphics);

    /**
     * @brief Sprawdza czy można wykonać bicie w przelocie w następnym ruchu
     * @param chessBoxGraphics wskaźnik na element graficzny odpowiadający polu szachowemu na które klikamy
     */
    void checkIfEnPassantPossible(ChessSquareGraphicsItem *chessBoxGraphics);

    /**
     * @brief obsługuje wykonanie bicia w przelocie lub zwykły ruch pionka wynikający z możliwości pionka w pozycji gdzie jest możliwe wykonanie bicia w przelocie
     * @param pawnPerformingEnPassant wskaźnik na pionek który ma możliwość wykonania bicia w przelocie
     * @param chessBoxGraphics wskaźnik na element graficzny odpowiadający polu szachowemu na które klikamy
     */
    void performEnPassant(Pawn *pawnPerformingEnPassant, ChessSquareGraphicsItem *chessBoxGraphics);
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
    int moveCounter; /**< Licznik kolejno wykonywanych ruchów */

};

#endif // GAME_H
