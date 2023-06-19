#ifndef PIECEGRAPHICSITEM_H
#define PIECEGRAPHICSITEM_H

#include <QGraphicsPixmapItem>
#include "ChessSquare.h"
#include <QGraphicsSceneMouseEvent>
#include "ChessSquareGraphicsItem.h"

/**
 * @brief Klasa reprezentująca obiekt graficzny figury szachowej.
 */
class PieceGraphicsItem : public QGraphicsPixmapItem
{
public:

    /**
     * @brief Konstruktor klasy PieceGraphicsItem.
     * \param parent Wskaźnik na obiekt rodzica.
     * \param p Wskaźnik na obiekt figury.
     */

    PieceGraphicsItem(QGraphicsItem* parent = nullptr, Piece* p = nullptr);

    /**
     * @brief Destruktor klasy PieceGraphicsItem.
     */
    ~PieceGraphicsItem();

    /**
     * @brief Ustawia obrazek dla obiektu graficznego figury.
     *
     * Metoda wirtualna, która powinna być zaimplementowana w klasach pochodnych.
     * Ustawia odpowiedni obrazek dla obiektu graficznego figury szachowej.
     */
    virtual void setImage() = 0;

    /**
     * @brief Zresetuj kolory pól.
     *
     * Metoda resetuje kolory pól na szachownicy.
     * Wywoływana w momencie, gdy odznaczamy wybraną figurę lub wykonujemy ruch.
     * Przywraca oryginalne kolory pól, do których można było się przesunąć.
     */
    void decolor();

    /**
     * @brief Obsługa zdarzenia naciśnięcia myszy.
     * \param event Wskaźnik na obiekt zdarzenia myszy.
     */
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

    /**
     * @brief Zwraca wskaźnik na obiekt figury szachowej.
     * @return Wskaźnik na obiekt figury.
     */
    Piece* getChessPiece();

    /**
     * @brief Ustawia wskaźnik na obiekt figury szachowej.
     * \param p Wskaźnik na obiekt figury.
     */
    void setChessPiece(Piece* p);

protected:
    Piece* chessPiece; /**< Wskaźnik na obiekt figury szachowej. */
};

#endif // PIECEGRAPHICSITEM_H
