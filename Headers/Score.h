#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent=0); // constructor
    void increase(); // Mutator for the score varibale;
    int getScore(); // Accessor for the score variable;
private:
    int score;
};

#endif // SCORE_H
