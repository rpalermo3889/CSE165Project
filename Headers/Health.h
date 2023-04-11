#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsItem * parent=0);  // constructor
    void decrease(); // Accessor for the health variable
    int getHealth(); // Mutator for the score variable

private:
    int health;
};

#endif // HEALTH_H
