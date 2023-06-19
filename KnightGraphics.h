#ifndef KNIGHTGRAPHICS_H
#define KNIGHTGRAPHICS_H

#include "Knight.h"
#include "PieceGraphicsItem.h"

/**
 * @brief Klasa reprezentująca graficzną reprezentację skoczka.
 *
 * Klasa KnightGraphics dziedziczy po klasie PieceGraphicsItem i reprezentuje graficzną reprezentację figury szachowej - skoczka.
 */
class KnightGraphics : public PieceGraphicsItem
{
public:
    /**
     * @brief Konstruktor klasy KnightGraphics.
     * \param parent Wskaźnik na obiekt rodzica.
     * \param p Wskaźnik na obiekt figury szachowej.
     */
    KnightGraphics(QGraphicsItem *parent = nullptr, Piece *p = nullptr);

    /**
     * @brief Destruktor klasy KnightGraphics.
     */
    ~KnightGraphics();

    /**
     * @brief Ustawia odpowiedni obrazek dla graficznej reprezentacji skoczka.
     *
     * Metoda setImage() ustawia odpowiedni obrazek dla graficznej reprezentacji figury szachowej - skoczka.
     */
    void setImage();
};

#endif // KNIGHTGRAPHICS_H
