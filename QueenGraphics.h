#ifndef QUEENGRAPHICS_H
#define QUEENGRAPHICS_H

#include "Queen.h"
#include "PieceGraphicsItem.h"

/**
 * @brief Klasa reprezentująca graficzną reprezentację królowej (hetmana) na szachownicy.
 *
 * Klasa QueenGraphics dziedziczy po klasie PieceGraphicsItem i odpowiada za wyświetlanie graficznej reprezentacji
 * królowej (hetmana) na szachownicy.
 */
class QueenGraphics : public PieceGraphicsItem
{
public:
    /**
     * @brief Konstruktor klasy QueenGraphics.
     * \param parent Wskaźnik na obiekt rodzica w hierarchii graficznej.
     * \param p Wskaźnik na obiekt klasy Queen, reprezentujący królową (hetmana).
     */
    QueenGraphics(QGraphicsItem *parent = nullptr, Piece *p = nullptr);

    /**
     * @brief Destruktor klasy QueenGraphics.
     */
    ~QueenGraphics();

    /**
     * @brief Ustawienie grafiki reprezentującej królową.
     *
     * Metoda setImage() ustawia odpowiednią grafikę reprezentującą królową (hetmana) na polu szachownicy.
     */
    void setImage();
};

#endif // QUEENGRAPHICS_H
