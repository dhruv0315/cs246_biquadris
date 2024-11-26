#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "board.h"

using namespace std;

const int boardWidth = 11;
const int boardHeight = 18;


class Block {
	protected:
	Board& board; // a reference to the board that this block belongs to
	std::vector<std::vector<int>> cell; // 2D grid representing the position of all cells in the block
    int x, y;  // Position of the block on the board (bottom-left corner of the block)

	public:

	Block(Board& board, int x, int y);
	virtual ~Block() = 0; //pure virtual method, abstract class, preventing initializing a "BLock" obj
	
	virtual void rotateClockwise() = 0; 
	virtual void rotateCounterClockwise() = 0;
	void moveLeft();
	void moveRight();
	void moveDown();
	void dropToBottom(); // should call placeOnBoard() after this.
	void placeOnBoard(); // place this block on the board it belongs to. should then lose the control to this block after calling this.
    bool isValidPosition(const std::vector<std::vector<int>>& newCells, int newX, int newY) const; // Helper method to check if a move or rotation is valid

};

// the following are the seven type of blocks's concrete class
//----------------------------------------------------------------------------------------------
class IBlock : public Block {
    int rotateState; // 0 or 1 for horizontal/vertical states
    public:
        IBlock(Board& board, int x, int y);
        void rotateClockwise() override;
        void rotateCounterClockwise() override;
};


class JBlock : public Block {
    int rotateState; // 0-3 for each rotation state
public:
    JBlock(Board& board, int x, int y);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
};


class LBlock : public Block {
    int rotateState;
public:
    LBlock(Board& board, int x, int y);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
};

class OBlock : public Block {
public:
    OBlock(Board& board, int x, int y);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
};

class SBlock : public Block {
    int rotateState;
public:
    SBlock(Board& board, int x, int y);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
};

class ZBlock : public Block {
    int rotateState;
public:
    ZBlock(Board& board, int x, int y);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
};

class TBlock : public Block {
    int rotateState;
public:
    TBlock(Board& board, int x, int y);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
};



#endif
