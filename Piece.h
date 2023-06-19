#ifndef PIECE_H
#define PIECE_H

#include "PieceGraphicsItem.h"

class ChessSquare;

/**
 * @brief Klasa reprezentująca figurę szachową.
 */
class Piece
{
public:
    /**
     * @brief Konstruktor klasy Piece.
     * \param team Strona figury (kolor: biały lub czarny).
     */
    Piece(QString team = "");

    /**
     * @brief Destruktor klasy Piece.
     */
    ~Piece();

    /**
     * @brief Ustawia bieżące pole figury.
     * \param box Wskaźnik na pole szachowe.
     */
    void setCurrentBox(ChessSquare* box);

    /**
     * @brief Zwraca bieżące pole figury.
     * @return Wskaźnik na pole szachowe.
     */
    ChessSquare* getCurrentBox();

    /**
     * @brief Zwraca stronę figury.
     * @return Strona figury (kolor: biały lub czarny).
     */
    QString getSide();

    /**
     * @brief Ustawia stronę figury.
     * \param value Strona figury (kolor: biały lub czarny).
     */
    void setSide(QString value);

    /**
     * @brief Zwraca informację czy figura została ustawiona na polu.
     * @return true, jeśli figura jest ustawiona; false w przeciwnym razie.
     */
    bool getIsPlaced();

    /**
     * @brief Ustawia informację czy figura została ustawiona na polu.
     * \param value Wartość informująca o ustawieniu figury na polu.
     */
    void setIsPlaced(bool value);

    /**
     * @brief Zwraca listę możliwych ruchów figury.
     * @return Lista wskaźników na pola szachowe, na które figura może się ruszyć.
     */
    QList<ChessSquare*> moveLocation();

    /**
     * @brief Wykonuje ruch figury.
     *
     * Metoda wirtualna, która powinna być zaimplementowana w klasach pochodnych.
     * Realizuje odpowiedni ruch figury w zależności od jej rodzaju.
     */
    virtual void move() = 0;

    /**
     * @brief Ustawia informację o pierwszym ruchu figury.
     * \param value Wartość informująca o pierwszym ruchu figury.
     */
    void setFirstMove(bool value);

    /**
     * @brief Zwraca informację o pierwszym ruchu figury.
     * @return true, jeśli to jest pierwszy ruch figury; false w przeciwnym razie.
     */
    bool getFirstMove();

    /**
     * @brief Ustawia figurę na polu wynikającym z ruchu.
     * \param box Wskaźnik na pole szachowe.
     * \return true, jeśli ustawienie figury na polu powiodło się; false w przeciwnym razie.
     */
    bool boxSetting(ChessSquare* box);

    /**
     * @brief Zwraca wskaźnik na obiekt graficzny reprezentujący figurę.
     * @return Wskaźnik na obiekt PieceGraphicsItem.
     */
    PieceGraphicsItem* getPieceGraphics();

    /**
     * @brief Ustawia wskaźnik na obiekt graficzny reprezentujący figurę.
     * \param pieceG Wskaźnik na obiekt PieceGraphicsItem.
     */
    void setPieceGraphics(PieceGraphicsItem* pieceG);

protected:
    PieceGraphicsItem* pieceGraphics; /**< Wskaźnik na obiekt graficzny reprezentujący figurę. */
    ChessSquare* currentBox; /**< Wskaźnik na bieżące pole szachowe. */
    QString side; /**< Strona figury (kolor: biały lub czarny). */
    bool isPlaced; /**< Informacja czy figura została ustawiona na polu. */
    QList<ChessSquare*> location; /**< Lista wskaźników na pola szachowe, na które figura może się ruszyć. */
    bool firstMove; /**< Informacja czy to jest pierwszy ruch figury w partii. */
};

#endif // PIECE_H

