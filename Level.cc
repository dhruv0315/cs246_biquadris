#include "Level.h"
#include "LevelOne.h"
#include "LevelTwo.h"
#include "LevelThree.h"
#include "LevelFour.h"

Level *Level::initLevel(int level) {
    if (level == 1) {
        return new LevelOne;
    } else if (level == 2) {
        return new LevelTwo;
    } else if (level == 3) {
        return new LevelThree;
    } else if (level == 4) {
        return new LevelFour;
    } else {
        return nullptr;
    }
}

