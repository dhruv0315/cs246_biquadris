#ifndef LEVELTHREE_H
#define LEVELTHREE_H

#include "Level.h"

class LevelThree : public Level {
public:
    LevelThree() = default;
    ~LevelThree() override = default;

    Block* generateBlock() override;
    void incLevel() override;
    void decLevel() override;
    int getLevel() const override;
};

#endif