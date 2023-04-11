#ifndef BOSS_H
#define BOSS_H
#include "Enemy.h"

class Enemy;
class Boss : public Enemy{
public:
    virtual ~Boss();
    virtual void spawn();
};

#endif // BOSS_H
