#ifndef ROOKGRAPHICS_H
#define ROOKGRAPHICS_H

#include "Rook.h"
#include "PieceGraphicsItem.h"

/**
 * @brief Klasa reprezentująca graficzną reprezentację wieży na szachownicy.
 *
 * Klasa RookGraphics dziedziczy po klasie PieceGraphicsItem i odpowiada za wyświetlanie graficznej reprezentacji wieży na szachownicy.
 */
class RookGraphics : public PieceGraphicsItem
{
public:
    /**
     * @brief Konstruktor klasy RookGraphics.
     * \param parent Wskaźnik na obiekt rodzica (domyślnie nullptr).
     * \param p Wskaźnik na obiekt wieży (domyślnie nullptr).
     */
    RookGraphics(QGraphicsItem *parent = nullptr, Piece *p = nullptr);

    /**
     * @brief Destruktor klasy RookGraphics.
     */
    ~RookGraphics();

    /**
     * @brief Ustawia obrazek dla graficznej reprezentacji wieży.
     *
     * Metoda setImage() ustawia odpowiedni obrazek dla graficznej reprezentacji wieży na szachownicy.
     */
    void setImage();
};

#endif // ROOKGRAPHICS_H
