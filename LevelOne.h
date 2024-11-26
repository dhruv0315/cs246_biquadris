#ifndef LEVELONE_H
#define LEVELONE_H

#include "Level.h"

class LevelOne : public Level {
public:
    // Constructor and Destructor
    LevelOne() = default;
    ~LevelOne() override = default;

    // Override methods from Level
    Block* generateBlock() override;
    void incLevel() override;
    void decLevel() override;
    int getLevel() const override;
};

#endif