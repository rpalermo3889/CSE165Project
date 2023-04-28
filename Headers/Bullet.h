#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>

class Bullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent=0); // constructor
    ~Bullet();
public slots:
    virtual void move();
private:
    QMediaPlayer * bulletsound;
    QAudioOutput * bulletaudio;
};

#endif // BULLET_H
