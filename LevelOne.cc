#include "LevelOne.h"
#include "LevelTwo.h"
#include "Block.h"


Block* LevelOne::generateBlock() {
    // Generate a random number between 0 and 11
    int randomInt = rand() % 12;

    // Assign blocks based on probabilities
    if (randomInt == 0) return new SBlock();             // 1/12 probability
    else if (randomInt == 1) return new ZBlock();        // 1/12 probability
    else if (randomInt <= 3) return new IBlock();        // 2/12 probability (1/6)
    else if (randomInt <= 5) return new JBlock();        // 2/12 probability (1/6)
    else if (randomInt <= 7) return new LBlock();        // 2/12 probability (1/6)
    else if (randomInt <= 9) return new OBlock();        // 2/12 probability (1/6)
    else return new TBlock();                            // 2/12 probability (1/6)
}

void LevelOne::incLevel() {
    delete this;
    *this = *Level::initLevel(2);
}

void LevelOne::decLevel() {
    // LevelOne cannot decrease below Level 1
}

int LevelOne::getLevel() const {
    return 1;
}