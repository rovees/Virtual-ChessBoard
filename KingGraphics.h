#ifndef KINGGRAPHICS_H
#define KINGGRAPHICS_H

#include "King.h"
#include "PieceGraphicsItem.h"

/**
 * @brief Klasa reprezentująca graficzną reprezentację króla.
 *
 * Klasa KingGraphics dziedziczy po klasie PieceGraphicsItem i odpowiada za wyświetlanie graficznej
 * reprezentacji króla na planszy.
 */
class KingGraphics : public PieceGraphicsItem
{
public:
    /**
     * @brief Konstruktor klasy KingGraphics.
     * \param parent Wskaźnik na obiekt QGraphicsItem reprezentujący rodzica elementu graficznego.
     * \param p Wskaźnik na obiekt Piece reprezentujący króla.
     */
    KingGraphics(QGraphicsItem *parent = nullptr, Piece *p = nullptr);

    /**
     * @brief Destruktor klasy KingGraphics.
     */
    ~KingGraphics();

    /**
     * @brief Ustawia odpowiedni obrazek dla graficznej reprezentacji króla.
     *
     * Metoda setImage() ustawia obrazek reprezentujący króla w elemente graficznym.
     */
    void setImage();
};

#endif // KINGGRAPHICS_H
