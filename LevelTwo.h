#ifndef LEVELTWO_H
#define LEVELTWO_H

#include "Level.h"

class LevelTwo : public Level {
public:
    LevelTwo() = default;
    ~LevelTwo() override = default;

    Block* generateBlock() override;
    void incLevel() override;
    void decLevel() override;
    int getLevel() const override;
};

#endif