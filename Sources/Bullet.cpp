#include "Headers/Bullet.h"
#include "Headers/Enemy.h"
#include "Headers/Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

extern Game * game; // there is an external global object called game

Bullet::Bullet(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent){
    // Set bullet sound
    bulletsound = new QMediaPlayer();
    bulletaudio = new QAudioOutput();
    bulletsound->setAudioOutput(bulletaudio);
    bulletsound->setSource(QUrl("qrc:/sounds/Resources/bullet.wav"));
    bulletaudio->setVolume(1);

    // play bulletsound
    if(bulletsound->playbackState() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->playbackState() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }

    // draw graphics
    setPixmap(QPixmap(":/images/Resources/bullet.png"));

    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move(){
    // if bullet collides with enemy, destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // increase score
            game->score->increase();

            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    //move bullet up
    setPos(x(),y()-10);
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}

Bullet::~Bullet()
{

}
