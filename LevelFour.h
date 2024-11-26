#ifndef LEVELFOUR_H
#define LEVELFOUR_H

#include "Level.h"

class LevelFour : public Level {
public:
    LevelFour() = default;
    ~LevelFour() override = default;

    Block* generateBlock() override;
    void incLevel() override;
    void decLevel() override;
    int getLevel() const override;
};

#endif