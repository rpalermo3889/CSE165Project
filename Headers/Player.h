#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0); // constructor
    ~Player();
    void keyPressEvent(QKeyEvent * event);
public slots:
    virtual void spawn();
};

#endif // PLAYER_H
