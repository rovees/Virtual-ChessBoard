#ifndef BISHOPGRAPHICS_H
#define BISHOPGRAPHICS_H

#include "Bishop.h"
#include "PieceGraphicsItem.h"

/**
 * @brief Klasa reprezentująca graficzną reprezentację gońca.
 *
 * Klasa BishopGraphics dziedziczy po klasie PieceGraphicsItem i implementuje metodę setImage(),
 * która ustawia odpowiednią grafikę dla gońca.
 */
class BishopGraphics : public PieceGraphicsItem
{
public:
    /**
     * @brief Konstruktor klasy BishopGraphics.
     * \param parent Wskaźnik na obiekt nadrzędny w hierarchii QGraphicsItem (opcjonalny).
     * \param p Wskaźnik na obiekt Bishop reprezentujący figurę gońca (opcjonalny).
     */
    BishopGraphics(QGraphicsItem *parent = nullptr, Piece *p = nullptr);

    /**
     * @brief Destruktor klasy BishopGraphics.
     */
    ~BishopGraphics();

    /**
     * @brief Ustawia odpowiednią grafikę dla gońca.
     *
     * Metoda setImage() ustawia odpowiednią grafikę dla gońca na podstawie jego koloru.
     */
    void setImage();
};

#endif // BISHOPGRAPHICS_H
