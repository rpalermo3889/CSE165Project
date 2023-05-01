#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Headers/Player.h"
#include "Headers/Score.h"
#include "Headers/Health.h"
#include <QOpenGLWidget>
#include <QPushButton>

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget *parent = 0); // constructor
    ~Game();

    QGraphicsView *view;
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
    QPushButton* backToMenuButton;
    void displayMainMenu();
public slots:
    void backToMenu();
    void start();
};

#endif // GAME_H
