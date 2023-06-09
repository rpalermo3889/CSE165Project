#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsItem * parent=0);  // constructor
    virtual void decrease(); // Mutator for the health variable
    int getHealth(); // Accessor for the score variable
private:
    int health;
};

#endif // HEALTH_H
