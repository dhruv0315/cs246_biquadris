#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "block.h"

using namespace std;

const vector<vector<int>> IBlock0{{0,0},{0,-1},{0,-2},{0,-3}};
const vector<vector<int>> IBlock1{{0,0},{1,0},{2,0},{3,0}};

const vector<vector<int>> JBlock0{{0, 0}, {0, -1}, {1,0}, {2,0}};
const vector<vector<int>> JBlock1{{0, 0}, {0,-1}, {0,-2}, {1,-2}};
const vector<vector<int>> JBlock2{{0,-1}, {1, -1}, {2, -1}, {2, 0}};
const vector<vector<int>> JBlock3{{0, 0}, {1, 0}, {1,-1}, {1, -2}};

const vector<vector<int>> LBlock0{{0, 0}, {1,0}, {2, 0}, {2, -1}};
const vector<vector<int>> LBlock1{{0, 0}, {0, -1}, {0, -2}, {1,0}};
const vector<vector<int>> LBlock2{{0, 0}, {0,-1}, {1,-1}, {2,-1}};
const vector<vector<int>> LBlock3{{0, 0}, {1, 0}, {1, -1}, {1, -2}};

const vector<vector<int>> OBlock0{{0, 0}, {0, -1}, {1, 0}, {1, -1}};

const vector<vector<int>> SBlock0{{0, 0}, {1,0}, {1,-1}, {2, -1}};
const vector<vector<int>> SBlock1{{0, -1}, {0,-2}, {1,0}, {1, -1}};

const vector<vector<int>> ZBlock0{{0,-1}, {1,-1}, {1,0}, {2, 0}};
const vector<vector<int>> ZBlock1{{0,0}, {0,-1}, {1,-1}, {1, -1}};

const vector<vector<int>> TBlock0{{0, -1}, {1,-1}, {1, 0}, {2, -1}};
const vector<vector<int>> TBlock1{{0, -1}, {1, 0}, {1, -1}, {1,-2}};
const vector<vector<int>> TBlock2{{0, 0}, {1,0}, {1,-1}, {2,0}};
const vector<vector<int>> TBlock3{{0, 0}, {0, -1}, {0, -2}, {1, -1}};



Block::Block(Board* board, char c, int x, int y):board{board},cell{{0,0},{0,0},{0,0},{0,0}}, x{x}, y{y}, blockType{c} {}



bool Block::isValidPosition(const std::vector<std::vector<int>>& newCells, int newX, int newY) const {
    for (const auto& coord : newCells) {
        int checkX = newX + coord[0];
        int checkY = newY + coord[1];

        // Out-of-bounds or occupied cell
        if (checkX < 0 || checkX >= boardWidth || checkY < 0 || checkY >= boardHeight ||
            board->getCell(checkX, checkY) != ' ') {
            return false;
        }
    }
    return true;
}

char Block::getBlockType() const {
    return blockType;
}

int Block::getX() const {
    return x;
}

int Block::getY() const {
    return y;
}

const std::vector<std::vector<int>>& Block::getCells() const {
    return cell;
}


void Block::moveLeft() {

    if (isValidPosition(cell, x - 1, y)) --x;
}

void Block::moveRight() {
    if (isValidPosition(cell, x + 1, y)) ++x;
}

void Block::moveDown() {
    if (isValidPosition(cell, x, y - 1)) --y;
}

void Block::dropToBottom() {
    while (isValidPosition(cell, x, y - 1)) --y;
}

void Block::placeOnBoard() {
    for (const auto& coordinates : cell) {
        int blockX = x + coordinates[0]; // Calculate the absolute position
        int blockY = y + coordinates[1];
        
        if (blockX >= 0 && blockX < boardWidth && blockY >= 0 && blockY < boardHeight) {
            board->setCell(blockX, blockY, blockType); 
        } else {
            cout << "Error: Block out of bounds at (" << blockX << ", " << blockY << ")\n";
        }
    }
}



void Block::printBoard() const {
    for (int row = 0; row < boardHeight; ++row) {
        for (int col = 0; col < boardWidth; ++col) {
            bool blockCell = false;

            // Check if the current position is a part of the current block
            for (const auto& coord : cell) { 
                int blockX = x + coord[0]; // Block's global X position
                int blockY = y + coord[1]; // Block's global Y position

                if (blockX == col && blockY == row) {
                    blockCell = true;
                    break;
                }
            }

            // If blind effect is active, obscure part of the board with '?'
            if (board->isBlinded() && row >= 3 && row <= 12 && col >= 3 && col <= 9) {
                std::cout << '?'; // Blind effect
            } 
            // Print the block's character if it's in the current position
            else if (blockCell) {
                cout << blockType; 
            } 
            // Otherwise, print the regular board cell
            else {
                cout << board->getCell(row, col); // Access board's grid
            }
        }
        cout << '\n';
    }
}


Block::~Block() {}




IBlock::IBlock(Board* board, char c, int x, int y) : Block{board, 'I', x, y}, rotateState{0} {
    cell = IBlock0; // Default stateof IBlock(vertical)
}

void IBlock::rotateClockwise() {
    if (rotateState == 0) {
        if (isValidPosition(IBlock1, x, y)) {
            cell = IBlock1;
            rotateState = 1;
        }
    } else if (rotateState == 1) {
        if (isValidPosition(IBlock0, x, y)) {
            cell = IBlock0;
            rotateState = 0;
        }
    } else {
        cout << "Invalid rotate state in IBlock!" << endl;
    }
}

void IBlock::rotateCounterClockwise() {
    rotateClockwise(); // Same as clockwise rotation for IBlock
}

JBlock::JBlock(Board* board, char c, int x, int y) : Block{board, 'J', x, y}, rotateState{0}{
    cell = JBlock0;
}

void JBlock::rotateClockwise() {
    if (rotateState == 0) {
        if (isValidPosition(JBlock1, x, y)) {
            cell = JBlock1;
            rotateState = 1;
        }
    } else if (rotateState == 1) {
        if (isValidPosition(JBlock2, x, y)) {
            cell = JBlock2;
            rotateState = 2;
        }
    } else if (rotateState == 2) {
        if (isValidPosition(JBlock3, x, y)) {
            cell = JBlock3;
            rotateState = 3;
        }
    } else if (rotateState == 3) {
        if (isValidPosition(JBlock0, x, y)) {
            cell = JBlock0;
            rotateState = 0;
        }
    } else {
        cout << "Invalid rotate state in JBlock!" << endl;
    }
}

void JBlock::rotateCounterClockwise() {
    if (rotateState == 0) {
        if (isValidPosition(JBlock3, x, y)) {
            cell = JBlock3;
            rotateState = 3;
        }
    } else if (rotateState == 3) {
        if (isValidPosition(JBlock2, x, y)) {
            cell = JBlock2;
            rotateState = 2;
        }
    } else if (rotateState == 2) {
        if (isValidPosition(JBlock1, x, y)) {
            cell = JBlock1;
            rotateState = 1;
        }
    } else if (rotateState == 1) {
        if (isValidPosition(JBlock0, x, y)) {
            cell = JBlock0;
            rotateState = 0;
        }
    }
}

LBlock::LBlock(Board* board, char c, int x, int y) : Block{board, 'L', x, y}, rotateState{0} {
    cell = LBlock0;
}

void LBlock::rotateClockwise() {
    if (rotateState == 0) {
        if (isValidPosition(LBlock1, x, y)) {
            cell = LBlock1;
            rotateState = 1;
        }
    } else if (rotateState == 1) {
        if (isValidPosition(LBlock2, x, y)) {
            cell = LBlock2;
            rotateState = 2;
        }
    } else if (rotateState == 2) {
        if (isValidPosition(LBlock3, x, y)) {
            cell = LBlock3;
            rotateState = 3;
        }
    } else if (rotateState == 3) {
        if (isValidPosition(LBlock0, x, y)) {
            cell = LBlock0;
            rotateState = 0;
        }
    } else {
        cout << "Invalid rotate state in LBlock!" << endl;
    }
}

void LBlock::rotateCounterClockwise() {
    if (rotateState == 0) {
        if (isValidPosition(LBlock3, x, y)) {
            cell = LBlock3;
            rotateState = 3;
        }
    } else if (rotateState == 3) {
        if (isValidPosition(LBlock2, x, y)) {
            cell = LBlock2;
            rotateState = 2;
        }
    } else if (rotateState == 2) {
        if (isValidPosition(LBlock1, x, y)) {
            cell = LBlock1;
            rotateState = 1;
        }
    } else if (rotateState == 1) {
        if (isValidPosition(LBlock0, x, y)) {
            cell = LBlock0;
            rotateState = 0;
        }
    }
}



OBlock::OBlock(Board* board, char c, int x, int y) : Block{board, 'O', x, y} {
    cell = OBlock0;
}

void OBlock::rotateClockwise() {
    // No rotation needed for OBlock, it looks the same no matter what
}

void OBlock::rotateCounterClockwise() {}



SBlock::SBlock(Board* board, char c, int x, int y) : Block{board, 'S', x, y}, rotateState{0} {
    cell = SBlock0;
}

void SBlock::rotateClockwise() {
    if (rotateState == 0) {
        if (isValidPosition(SBlock1, x, y)) {
            cell = SBlock1;
            rotateState = 1;
        }
    } else if (rotateState == 1) {
        if (isValidPosition(SBlock0, x, y)) {
            cell = SBlock0;
            rotateState = 0;
        }
    }
}

void SBlock::rotateCounterClockwise() {
    rotateClockwise(); // Same as clockwise for SBlock
}


ZBlock::ZBlock(Board* board, char c, int x, int y) : Block{board, 'Z', x, y}, rotateState{0} {
    cell = ZBlock0;
}

void ZBlock::rotateClockwise() {
    if (rotateState == 0) {
        if (isValidPosition(ZBlock1, x, y)) {
            cell = ZBlock1;
            rotateState = 1;
        }
    } else if (rotateState == 1) {
        if (isValidPosition(ZBlock0, x, y)) {
            cell = ZBlock0;
            rotateState = 0;
        }
    }
}

void ZBlock::rotateCounterClockwise() {
    rotateClockwise(); // Same as clockwise for ZBlock
}



TBlock::TBlock(Board* board, char c, int x, int y) : Block{board, 'T', x, y}, rotateState{0} {
    cell = TBlock0;
}

void TBlock::rotateClockwise() {
    if (rotateState == 0) {
        if (isValidPosition(TBlock1, x, y)) {
            cell = TBlock1;
            rotateState = 1;
        }
    } else if (rotateState == 1) {
        if (isValidPosition(TBlock2, x, y)) {
            cell = TBlock2;
            rotateState = 2;
        }
    } else if (rotateState == 2) {
        if (isValidPosition(TBlock3, x, y)) {
            cell = TBlock3;
            rotateState = 3;
        }
    } else if (rotateState == 3) {
        if (isValidPosition(TBlock0, x, y)) {
            cell = TBlock0;
            rotateState = 0;
        }
    }
}

void TBlock::rotateCounterClockwise() {
    if (rotateState == 0) {
        if (isValidPosition(TBlock3, x, y)) {
            cell = TBlock3;
            rotateState = 3;
        }
    } else if (rotateState == 3) {
        if (isValidPosition(TBlock2, x, y)) {
            cell = TBlock2;
            rotateState = 2;
        }
    } else if (rotateState == 2) {
        if (isValidPosition(TBlock1, x, y)) {
            cell = TBlock1;
            rotateState = 1;
        }
    } else if (rotateState == 1) {
        if (isValidPosition(TBlock0, x, y)) {
            cell = TBlock0;
            rotateState = 0;
        }
    }
}


