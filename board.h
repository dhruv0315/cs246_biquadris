#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>

using namespace std;

class Board {
    vector<vector<char>> grid; // 2D grid to represent the board (' ' for empty, other chars for blocks)
    const int width;          // Width of the board
    const int height;         // Height of the board

public:
    Board(int width, int height);
    ~Board() = default;

    bool isLineFull(int row) const;        // Checks if a specific row is completely filled
    void clearFullRow(int row);           // Clear the specified row and shifts rows above it down

		char getCell(int x, int y) const;     // Get the content of a specific cell
    void setCell(int x, int y, char value); // Set the content of a specific cell

		
    void printBoard() const;              // Print the current board state for debugging
    void reset();                         // Clear the board
};

#endif

