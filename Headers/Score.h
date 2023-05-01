#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent=0); // constructor
    void increase(); // Accessor for the score varibale;
    int getScore(); // Mutator for the score variable;
private:
    int score;
};

#endif // SCORE_H
