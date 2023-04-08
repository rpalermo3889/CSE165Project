#include "Headers/Enemy.h"
#include "Headers/Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //set random position
    int random_number = rand() % 700;
    setPos(random_number,0);

    // drew the enemy
    setPixmap(QPixmap(":/images/Resources/enemy.png"));
    setTransformOriginPoint(50,50);
    setRotation(180);

    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move(){
    //move enemy down
    setPos(x(),y()+5);

    // destroy enemy when it goes out of screen
    if (pos().y() > 600){
        //decrease the health
        game ->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}

