#include "Headers/Player.h"
#include "Headers/Bullet.h"
#include "Headers/Enemy.h"
#include <QGraphicsScene>
#include <QKeyEvent>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    // set graphic
    setPixmap(QPixmap(":/images/Resources/player.png"));
}

// Player Controls
void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
            setPos(x()-20,y());
    }
    else if(event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
            setPos(x()+20,y());
    }
    else if(event->key() == Qt::Key_Space){
        //create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+19,y()-15);
        scene()->addItem(bullet);
    }
}

void Player::spawn(){
    //create enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

Player::~Player()
{

}
