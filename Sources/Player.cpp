#include "Headers/Player.h"
#include "Headers/Bullet.h"
#include "Headers/Enemy.h"
#include <QGraphicsScene>
#include <QKeyEvent>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    // Set bullet sound
    bulletsound = new QMediaPlayer();
    bulletaudio = new QAudioOutput();
    bulletsound->setAudioOutput(bulletaudio);
    bulletsound->setSource(QUrl("qrc:/sounds/Resources/bullet.wav"));
    bulletaudio->setVolume(1);

    // set graphic
    setPixmap(QPixmap(":/images/Resources/player.png"));
}

void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if(event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    else if(event->key() == Qt::Key_Space){
        //create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+19,y()-40);
        scene()->addItem(bullet);

        // play bulletsound
        if(bulletsound->playbackState() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->playbackState() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
    }
}

void Player::spawn(){
    //create enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
