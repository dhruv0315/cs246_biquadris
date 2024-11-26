#include "LevelThree.h"
#include "LevelTwo.h"
#include "LevelFour.h"
#include "Block.h"

Block* LevelThree::generateBlock() {
    // Generate a random number between 0 and 8
    int randomInt = rand() % 9;

    // Assign blocks based on probabilities
    if (randomInt <= 1) return new SBlock();             // 2/9 probability
    else if (randomInt <= 3) return new ZBlock();        // 2/9 probability
    else if (randomInt == 4) return new IBlock();        // 1/9 probability
    else if (randomInt == 5) return new JBlock();        // 1/9 probability
    else if (randomInt == 6) return new LBlock();        // 1/9 probability
    else if (randomInt == 7) return new OBlock();        // 1/9 probability
    else return new TBlock();                            // 1/9 probability
}

void LevelThree::incLevel() {
    // Transition to LevelFour
    delete this;           // Free the current level object
    *this = *Level::initLevel(4); // Replace with LevelFour
}

void LevelThree::decLevel() {
    // Transition to LevelTwo
    delete this;           // Free the current level object
    *this = *Level::initLevel(2); // Replace with LevelTwo
}

int LevelThree::getLevel() const {
    return 3;
}