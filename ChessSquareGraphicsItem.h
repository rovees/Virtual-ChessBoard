#ifndef CHESSSQUAREGRAPHICSITEM_H
#define CHESSSQUAREGRAPHICSITEM_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include "ChessSquare.h"

class Piece;
class ChessSquare;

/**
 * @brief Klasa ChessSquareGraphicsItem reprezentuje graficzną reprezentację pojedynczego pola szachowego.
 *
 * Klasa ChessSquareGraphicsItem dziedziczy po QGraphicsRectItem i reprezentuje graficzną reprezentację pojedynczego pola na szachownicy.
 * Odpowiada za obsługę zdarzeń myszy oraz manipulację kolorem pola szachowego.
 */
class ChessSquareGraphicsItem : public QGraphicsRectItem
{
public:
    /**
     * @brief Konstruktor klasy ChessSquareGraphicsItem.
     * \param parent Wskaźnik na obiekt QGraphicsItem będący rodzicem elementu.
     * \param cS Wskaźnik na obiekt ChessSquare reprezentujący dane pole szachowe.
     */
    ChessSquareGraphicsItem(QGraphicsItem *parent = nullptr, ChessSquare *cS = nullptr);

    /**
     * @brief Obsługuje zdarzenie naciśnięcia myszy na polu szachowym.
     * \param event Wskaźnik na obiekt QGraphicsSceneMouseEvent reprezentujący zdarzenie myszy.
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    /**
     * @brief Ustawia kolor pola szachowego.
     * \param color Kolor pola szachowego.
     */
    void setColor(QColor color);

    /**
     * @brief Zwraca aktualny kolor pola szachowego.
     * @return Aktualny kolor pola szachowego.
     */
    QColor getColor();

    /**
     * @brief Ustawia oryginalny kolor pola szachowego.
     * \param value Oryginalny kolor pola szachowego.
     */
    void setOriginalColor(QColor value);

    /**
     * @brief Przywraca oryginalny kolor pola szachowego.
     */
    void resetOriginalColor();

    /**
     * @brief Zwraca wskaźnik na obiekt ChessSquare reprezentujący dane pole szachowe.
     * @return Wskaźnik na obiekt ChessSquare.
     */
    ChessSquare *getCurrSquare();

    /**
     * @brief Ustawia wskaźnik na obiekt ChessSquare reprezentujący dane pole szachowe.
     * \param currChessSquare Wskaźnik na obiekt ChessSquare.
     */
    void setCurrSquare(ChessSquare *currChessSquare);

private:
    ChessSquare *currSquare; /**< Pole szachowe (klasa ChessSquare) odpowiadające danej reprezentacji graficznej. */
    QBrush brush; /**< Obiekt QBrush reprezentujący pędzel dla pola szachowego. */
    QColor originalColor; /**< Oryginalny kolor pola szachowego. */
};

#endif // CHESSSQUAREGRAPHICSITEM_H
