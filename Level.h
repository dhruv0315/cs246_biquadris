#ifndef LEVEL_H
#define LEVEL_H

#include "block.h"

// Abstract base class for all levels
class Level {
public:
    // Virtual destructor
    virtual ~Level() = default;

    // Pure virtual function for generating blocks
    virtual Block* generateBlock() = 0;

    // Pure virtual functions
    virtual void incLevel() = 0;
    virtual void decLevel() = 0;
    virtual int getLevel() const = 0;

    // Factory method to initialize levels
    static Level* initLevel(int level);
};

#endif