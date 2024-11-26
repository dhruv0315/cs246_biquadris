#include "LevelFour.h"
#include "LevelThree.h"
#include "IBlock.h"
#include "JBlock.h"
#include "LBlock.h"
#include "OBlock.h"
#include "SBlock.h"
#include "ZBlock.h"
#include "TBlock.h"


Block* LevelFour::generateBlock() {
    // Generate a random number between 0 and 8
    int randomInt = rand() % 9;

    // Assign blocks based on probabilities (same as Level 3)
    if (randomInt <= 1) return new SBlock();             // 2/9 probability
    else if (randomInt <= 3) return new ZBlock();        // 2/9 probability
    else if (randomInt == 4) return new IBlock();        // 1/9 probability
    else if (randomInt == 5) return new JBlock();        // 1/9 probability
    else if (randomInt == 6) return new LBlock();        // 1/9 probability
    else if (randomInt == 7) return new OBlock();        // 1/9 probability
    else return new TBlock();                            // 1/9 probability
}

void LevelFour::incLevel() {
    // LevelFour cannot increase beyond Level 4, do nothing
}

void LevelFour::decLevel() {
    // Transition to LevelThree
    delete this;           // Free the current level object
    *this = *Level::initLevel(3); // Replace with LevelThree
}

int LevelFour::getLevel() const {
    return 4;
}