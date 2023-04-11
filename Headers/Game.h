#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Headers/Player.h"
#include "Headers/Score.h"
#include "Headers/Health.h"

#include <QOpenGLWidget>

class Game: public QGraphicsView{
public:
    Game(QWidget * parent = 0); // constructor

    QGraphicsView *view;
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;

    /*
    ~Game();
    virtual void setGame();
    */
};

#endif // GAME_H
