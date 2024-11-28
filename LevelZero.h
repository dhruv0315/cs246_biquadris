#ifndef LEVELZERO_H
#define LEVELZERO_H

#include "Level.h"
#include <string>
#include <vector>

using namespace std;

class LevelZero : public Level {
private:
    vector<string> firstPlayerSequence; 
    vector<string> secondPlayerSequence; 
    size_t firstPlayerIdx; 
    size_t secondPlayerIdx; 

public:
    // Constructor and Destructor
    LevelZero(const string& fileOne, const string& fileTwo);
    ~LevelZero() override = default;

    // Override Level methods
    void loadFile(const string& fileName, vector<string>& sequence);
    Block* generateBlock(Board *board, int player);  // Generate block for a specific player
    void incLevel() override;
    void decLevel() override;
    int getLevel() const override;
}; 
 
#endif