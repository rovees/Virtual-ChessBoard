#include "Button.h"
#include <QGraphicsTextItem>
#include <QBrush>

Button::Button(QString name, QGraphicsItem *parent)
    :QGraphicsRectItem(parent)
{
    // narysuj przycisk
    setRect(0,0,0.8*200,0.8*50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    setBrush(brush);

    // narysuj tekst przycisku
    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);
    text->setDefaultTextColor(Qt::white);

    // reagowanie na najechanie myszką
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{

}
void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{

}
