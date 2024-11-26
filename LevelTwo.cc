#include "LevelTwo.h"
#include "LevelOne.h"
#include "LevelThree.h"
#include "Block.h"
#include "IBlock.h"
#include "JBlock.h"
#include "LBlock.h"
#include "OBlock.h"
#include "SBlock.h"
#include "ZBlock.h"
#include "TBlock.h"


Block* LevelTwo::generateBlock() {
    int randomInt = rand() % 7;
    if (randomInt == 0) {
        reutrn new IBlock();
    } else if (randomInt == 1) {
        return new JBlock();
    } else if (randomInt == 2) {
        reutrn new LBlock();
    } else if (randomInt == 3) {
        return new OBlock();
    } else if (randomInt == 4) {
        return new SBlock();
    } else if (randomInt == 5) {
        return new ZBlock();
    } else if (randomInt == 6) {
        return new TBlock();
    }
}

void LevelTwo::incLevel() {
    // Transition to LevelThree
    delete this;           // Free the current level object
    *this = *Level::initLevel(3); // Replace with LevelThree
}

void LevelTwo::decLevel() {
    // Transition to LevelOne
    delete this;           // Free the current level object
    *this = *Level::initLevel(1); // Replace with LevelOne
}

int LevelTwo::getLevel() const {
    return 2;
}