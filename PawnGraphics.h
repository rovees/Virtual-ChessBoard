#ifndef PAWNGRAPHICS_H
#define PAWNGRAPHICS_H

#include "Pawn.h"
#include "PieceGraphicsItem.h"

/**
 * @brief Klasa reprezentująca graficzną reprezentację pionka.
 *
 * Klasa PawnGraphics dziedziczy po klasie PieceGraphicsItem i reprezentuje graficzną reprezentację pionka na szachownicy.
 */
class PawnGraphics : public PieceGraphicsItem
{
public:
    /**
     * @brief Konstruktor klasy PawnGraphics.
     * \param parent Wskaźnik na obiekt nadrzędny (rodzic).
     * \param p Wskaźnik na obiekt reprezentujący pionka.
     */
    PawnGraphics(QGraphicsItem *parent = nullptr, Piece *p = nullptr);

    /**
     * @brief Destruktor klasy PawnGraphics.
     */
    ~PawnGraphics();

    /**
     * @brief Ustawienie obrazka dla graficznej reprezentacji pionka.
     *
     * Metoda setImage() ustawia odpowiedni obrazek dla graficznej reprezentacji pionka na planszy szachowej.
     */
    void setImage();
};

#endif // PAWNGRAPHICS_H
