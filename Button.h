#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>

/**
 * @brief Klasa reprezentująca przycisk.
 */
class Button : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    /**
     * @brief Konstruktor klasy Button.
     * \param name Nazwa przycisku.
     * \param parent Wskaźnik na obiekt rodzica.
     */
    Button(QString name, QGraphicsItem* parent = nullptr);

    /**
     * @brief Obsługa zdarzenia naciśnięcia przycisku myszy.
     * \param event Obiekt zdarzenia naciśnięcia myszy.
     */
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

    /**
     * @brief Obsługa zdarzenia najechania myszą na przycisk.
     * \param event Obiekt zdarzenia najechania myszą.
     */
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event);

    /**
     * @brief Obsługa zdarzenia opuszczenia przycisku myszą.
     * \param event Obiekt zdarzenia opuszczenia myszą.
     */
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);

signals:
    /**
     * @brief Sygnał emitowany po kliknięciu przycisku.
     */
    void clicked();

private:
    QGraphicsTextItem* text; /**< Wskaźnik na obiekt tekstowy wyświetlający nazwę przycisku. */
};

#endif // BUTTON_H
