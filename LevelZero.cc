#include "LevelZero.h"
#include "block.h"
#include <fstream>

using namespace std;

LevelZero::LevelZero(const string& fileOne, const string& fileTwo)
    : firstPlayerIdx(0), secondPlayerIdx(0) {
    loadSequenceFromFile(fileOne, firstPlayerSequence);
    loadSequenceFromFile(fileTwo, secondPlayerSequence);
}

void LevelZero::loadSequenceFromFile(const string& fileName, vector<string>& sequence) {
    ifstream file(fileName);
    string block;

    while (file >> block) {
        sequence.push_back(block);
    }

    file.close();
}

Block* LevelZero::generateBlock(int player) {
    vector<string>* seq;
    size_t* index;

    if (player == 1) {
        seq = &firstPlayerSequence;
        index = &firstPlayerIdx;
    } else if (player == 2) {
        seq = &secondPlayerSequence;
        index = &secondPlayerIdx;
    }

    // Get the next block type
    string block = (*seq)[*index];

    // Increment and wrap around the index
    *index = (*index + 1) % seq->size();

    // Create and return the appropriate block
    if (block == "I") return new IBlock();
    if (block == "J") return new JBlock();
    if (block == "L") return new LBlock();
    if (block == "O") return new OBlock();
    if (block == "S") return new SBlock();
    if (block == "Z") return new ZBlock();
    if (block == "T") return new TBlock();
}

void LevelZero::incLevel() {
    delete this;
    *this = *Level::initLevel(1);
}

void LevelZero::decLevel() {
    //Can't go below level 0
}

int LevelZero::getLevel() const {
    return 0;
}
