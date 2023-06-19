#ifndef CHESSSQUARE_H
#define CHESSSQUARE_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>

class Piece;
class ChessSquareGraphicsItem;

/**
 * @brief Klasa ChessSquare reprezentuje pojedyncze pole na szachownicy.
 *
 * Klasa ChessSquare przechowuje informacje o pojedynczym polu na szachownicy.
 * Zawiera informacje o położeniu, figury szachowej umieszczonej na polu (jeśli istnieje) oraz inne atrybuty.
 */
class ChessSquare
{
public:
    /**
     * @brief Konstruktor klasy ChessSquare.
     */
    ChessSquare();

    /**
     * @brief Destruktor klasy ChessSquare.
     */
    ~ChessSquare();

    /**
     * @brief Umieszcza figurę na polu.
     * \param piece Wskaźnik na figurę, która ma zostać umieszczona na polu.
     */
    void placePiece(Piece *piece);

    /**
     * @brief Sprawdza, czy na polu znajduje się figura.
     * @return True, jeśli na polu znajduje się figura. False w przeciwnym przypadku.
     */
    bool getHasChessPiece();

    /**
     * @brief Ustawia informację o tym, czy na polu znajduje się figura.
     * \param value Wartość logiczna informująca o obecności figury na polu.
     * \param piece Wskaźnik na figurę, która znajduje się na polu. Domyślnie nullptr.
     */
    void setHasChessPiece(bool value, Piece *piece = nullptr);

    /**
     * @brief Zwraca pozycję wiersza pola na szachownicy.
     * @return Pozycja wiersza pola.
     */
    int getRowPos();

    /**
     * @brief Ustawia pozycję wiersza pola na szachownicy.
     * \param row Pozycja wiersza pola.
     */
    void setRowPos(int row);

    /**
     * @brief Zwraca pozycję kolumny pola na szachownicy.
     * @return Pozycja kolumny pola.
     */
    int getColPos();

    /**
     * @brief Ustawia pozycję kolumny pola na szachownicy.
     * \param col Pozycja kolumny pola.
     */
    void setColPos(int col);

    /**
     * @brief Zwraca wskaźnik na aktualną figurę znajdującą się na polu.
     * @return Wskaźnik na aktualną figurę na polu. Może być nullptr, jeśli na polu nie ma figury.
     */
    Piece *getCurrentPiece();

    /**
     * @brief Ustawia wskaźnik na aktualną figurę znajdującą się na polu.
     * \param p Wskaźnik na figurę, która ma zostać umieszczona na polu.
     */
    void setCurrentPiece(Piece *p);

    /**
     * @brief Zwraca kolor figury znajdującej się na polu.
     * @return Kolor figury. Może być pusty, jeśli na polu nie ma figury.
     */
    QString getChessPieceColor();

    /**
     * @brief Ustawia kolor figury znajdującej się na polu.
     * \param value Kolor figury.
     */
    void setChessPieceColor(QString value);

    /**
     * @brief Zwraca wskaźnik na obiekt graficzny reprezentujący pole szachowe.
     * @return Wskaźnik na obiekt ChessSquareGraphicsItem.
     */
    ChessSquareGraphicsItem *getBoxGraphics();

    /**
     * @brief Ustawia wskaźnik na obiekt graficzny reprezentujący pole szachowe.
     * \param boxG Wskaźnik na obiekt ChessSquareGraphicsItem.
     */
    void setBoxGraphics(ChessSquareGraphicsItem *boxG);

    /**
     * @brief Sprawdza, czy pole jest w szachu.
     */
    void checkForCheck();

    /**
     * @brief Kończy grę.
     */
    void gameOver();

private:
    ChessSquareGraphicsItem *boxGraphics; /**< Wskaźnik na obiekt graficzny reprezentujący pojedyncze pole szachowe. */
    int rowPos; /**< Pozycja wiersza pola na szachownicy. */
    int colPos; /**< Pozycja kolumny pola na szachownicy. */
    Piece *currentPiece; /**< Wskaźnik na aktualną figurę szachową znajdującą się na danym polu szachowym. */
    bool hasChessPiece; /**< Atrybut informujący, czy na danym polu szachowym znajduje się jakaś figura. */
    QString chessPieceColor; /**< Atrybut określający kolor figury znajdującej się na danym polu szachowym. */
};

#endif // CHESSSQUARE_H
