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
    void loadFile(const string& fileName, vector<string>& sequence); 

public:
    // Constructor and Destructor
    LevelZero(const string& file1, const string& file2); 
    ~LevelZero() override = default; 

    // Override Level methods 
    Block* generateBlock(int player);  // Generate block for a specific player 
    void incLevel() override; 
    void decLevel() override; 
    int getLevel() const override; 
}; 
 
#endif