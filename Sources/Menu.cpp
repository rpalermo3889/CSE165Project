#include "Headers/Menu.h"
#include <QBrush>


Menu::Menu(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    //drawing rectangle
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::Dense3Pattern);
    brush.setColor(Qt::green);
    setBrush(brush);

    // draw the text
    text = new QGraphicsTextItem(name, this);
    int xPos = rect().width() / 2 - text->boundingRect().width() / 2;
    int yPos = rect().height() / 2 - text->boundingRect().height() / 2;
    text->setPos(xPos, yPos);

    // responds to hover
    setAcceptHoverEvents(true);
}
void Menu::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();

}


void Menu::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::Dense3Pattern);
    brush.setColor(Qt::red);
    setBrush(brush);

}

void Menu::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::Dense3Pattern);
    brush.setColor(Qt::green);
    setBrush(brush);
}

