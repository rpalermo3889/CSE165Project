#include "Headers/Button.h"
#include <QBrush>


Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    //drawing rectangle
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    // draw the text
    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text -> boundingRect().width()/2;
    int yPos = rect().width()/2 - text -> boundingRect().height()/2;
    text -> setPos(xPos,yPos);

    // responds to hover
    setAcceptHoverEvents(true);
}
void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();

}


void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);

}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
}
